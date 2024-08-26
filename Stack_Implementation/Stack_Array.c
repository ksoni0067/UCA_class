#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<time.h>
#include "Stack.h"
#include <stdbool.h>

int* array;
int N = 0;
int max_size = 1;

void resize_array(int new_capacity)
{
  int * new_array = (int *) malloc(sizeof(int)*new_capacity);

  for(int i = 0; i < N; i++)
    new_array[i] = array[i];

  free(array);
  array = new_array;
}


void push(int item)
{
  if(N == max_size) {
    max_size*=2;
    resize_array(max_size);
  }
  array[N++] = item;
}
int top(){
    return array[N-1];

}
int pop()
{
  int item = array[--N];
  if (N <= max_size/4) resize_array(N/2);
  max_size = N/2;

  return item;
}

bool isEmpty()
{
  return N == 0;
}

int size()
{
  return N;
}
