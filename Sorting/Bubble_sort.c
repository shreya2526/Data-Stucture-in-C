#include<stdio.h>

void main(){

    int  array[25],n,i,j,temp,flag,count=0; //count variable for counting the passes of sorting process
	
	printf("enter no of elements: \n");  //taking no of elements
	scanf("%d",&n);
	
	printf("Enter value into array: \n"); //taking value to sort from user
	
	for(i=0;i<n;i++)
	{
	scanf("%d",&array[i]); //inputting
    } 
	 
	printf("\nDisplay array before sorting: \n");
	
	for(i=0;i<n;i++)
	{
		printf("%d\t",array[i]); //printing before sorting
	}
	
	//sorting program
	
	for(i=0;i<n-1;i++)
	{     flag=0;
		for(j=0;j<n-1-i;j++)
		{
			if(array[j]>array[j+1])
			{
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
                flag=1;
			}
        }
        if(flag == 0)
            break;
        count++;  //counting the passes
	}
	
    printf("\nDisplay array after sorting \n"); //printing sorted array
	for(i=0;i<n;i++)
	{
		printf("%d\t",array[i]);
	}
	
    printf("\nSorting process has been done in %d passes",count);
	
}