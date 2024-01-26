#include<stdio.h>
void main(){
    int a[25], size,i;
    printf("\n\n\n    ARRAY TRAVERSAL    \n\n\n");
    printf("Enter the size of array: ");
    scanf("%d",&size);
    if(size>25)
        printf("Array Overflow\nArray size is 25\n");
    else{
        printf("Enter the elements: ");
        for(i=0;i<size;i++){
            scanf("%d",&a[i]);
       }
        printf("Elements of array are: \n");
        for(i=0;i<size;i++){
            printf("%d\t",a[i]);
       }
    }
}