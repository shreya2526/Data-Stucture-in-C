#include<stdio.h>
int fib(int, int, int);
int main(){
    int n, a=0, b=1;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("fibonacci series upto %d is: ",n);
    printf("%d %d",a,b);
    fib(a,b,n);
    return 0;
}
int fib(int a, int b, int n){
    int c;
    if(n==0 || n==1){
        return n;
    }
    else{
        c=a+b;
        printf(" %d",c);
        return fib(b,c,n-1);
    }
}