#include<stdio.h>
void swap(int *val1,int *val2){
	int temp=*val1;
	*val1=*val2;
	*val2=temp;
}
void Bubblesort(int* arr,int n){
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
               swap(&arr[j+1],&arr[j]);    
            }
        }
    }
}
int main(){
    srand(time(0));
    int n;
    n=rand()%25;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=rand()%100;
    }
    Bubblesort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    int s=0;
    int target=4;
    int e=n-1;
    while(s<=e){
        int m=s+(e-s)/2;
        if( arr[m]==target){
            printf("element is present at indes %d",m);
            break;
        }
        else if(arr[m]>target){
            e=m-1;
        }
        else {
            s=m+1;
        }
    }
    return 0;




}