#include<stdio.h>
#include<stdlib.h>


void swap(int *val1,int *val2){
	int temp=*val1;
	*val1=*val2;
	*val2=temp;
}

void SelectionSort(int* arr,int n){
    for(int i=0;i<n-1;i++){
	for(int j=i+1;j<n;j++){
	    if(arr[j]<arr[i]){
		swap(&arr[i],&arr[j]);    
	    }
	}	
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
	scanf("%d",&arr[i]);   
    }
    SelectionSort(arr,n);
    for(int i=0;i<n;i++){
	    printf("%d  ",arr[i]);
    }
    	
}
