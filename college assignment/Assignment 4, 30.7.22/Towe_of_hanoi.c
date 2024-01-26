#include<stdio.h>
void toh(int ndisk, char source, char temp, char dest);
int main(){
   int ndisk;
   char source='a', temp='b', dest='c';

   printf("Enter number of disks: ");
   scanf("%d",&ndisk);
   printf("The sequence is: \n");
   toh(ndisk, source, temp, dest);
   return 0;
}
void toh(int ndisk, char source, char temp, char dest){
   if(ndisk==1){
      printf("Move disk %d from %c -> %c\n",ndisk,source,dest);
      return;
   }
   toh(ndisk-1,source,dest,temp);
   printf("Move disk %d from %c -> %c\n",ndisk,source,dest);
   toh(ndisk-1,temp,source,dest);
}