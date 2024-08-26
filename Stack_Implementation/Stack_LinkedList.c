#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<time.h>
#include "Stack.h"
#include <stdbool.h>
struct Node {
    int data;
    struct Node* next;
};
int n=0;
struct Node* head=NULL;
int pop(){
    if( n>0){
        n--;
        struct Node* old=head;
        int temp=head->data;
        head=head->next;
        free(old);
        return temp;
    }
    return -1;
}
void push(int item){
    n++;
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->data=item;
    temp->next=head;
    head=temp;

}
int top(){
    if(n>0){
        return head->data;
    }
    return -1;
}
int size(){
    return n;
}
bool isEmpty(){
    return n==0;
}
