#include <stdio.h>
struct stud
{
    char name[100];
    int roll;
    int marks;
} s[3], *st;
int main()
{
    int i;
    int n;
    st = s;
    printf("How many numbers of the student: ");
    scanf("%d",&n);
    printf("Enter the details of the students: ");
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the name: ");
        scanf("%s", (st + i)->name);
        printf("Enter the roll of the student: ");
        scanf("%d", &(st + i)->roll);
        printf("Enter the marks of the student: ");
        scanf("%d", &(st + i)->marks);
    }
    printf("The details: ");
    for (i = 0; i < n; i++)
    {
        printf("\nNmae: %s\t", (st + i)->name);
        printf("\nRoll: %d\t", (st + i)->roll);
        printf("\nMarks: %d\t", (st + i)->marks);
    }
    return 0;
}
