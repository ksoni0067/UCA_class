#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(){
	mode_t mode=S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IROTH;
	int fd=creat("first.txt",mode);
	close(fd);
	if(fd>0){
        int fd1=open("file1.txt",O_RDONLY);
		printf("Source file is opened\n");
	    int fd2=open("first.txt",O_WRONLY);
		printf("destination file is opened\n");
		

		if(fd1>0 && fd2>0){
		   char buffer[1000];
		   char sentence[1000];
		   int charptr=0;
		   size_t bytesread=0;
           while((bytesread=read(fd1,buffer,100))>0){
		   	for(int i=0;i<bytesread;i++){
			   sentence[charptr++]=buffer[i];
			   if(buffer[i]=='\n'){
					sentence[charptr]='\0';
					write(fd2,sentence,strlen(sentence));
					charptr=0;
			    }
            }
		  }
		  if(charptr>0){
			sentence[charptr++]='\n';
			sentence[charptr]='\0';
			write(fd2,sentence,strlen(sentence));
		  }
		  write(fd2,"All data is recover from  source file \n",strlen("All data is recover from  other file \n"));
		  close(fd1);
		  printf("source is Closed\n");
		  close(fd2);
		  printf("destination file is closed\n");
		}else{
			printf("file not opened\n");
		}
	}else{
		printf("file not created\n");
	}
	return 0;
}
