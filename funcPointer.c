
#include <stdio.h>
int add(int a,int b){
    return a+b;
}
int div(int a ,int b){
    return a/b;
}
int mul(int a,int b){
    return a*b;
}
int sub(int a,int b){
    return a*b;
}
void preform(int (*func)(int,int),int a,int b){
   int val= (*func)(a,b);
   printf("%d\n",val);
}
int main() {
    
   int (*func)(int,int)=mul;
   preform(func,2,3);
   

    return 0;
}
