#include <stdio.h>
int fact1(int);
int fact2(int);
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d", n, fact2(n));
    return 0;
}
int fact1(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * fact2(n - 1);
    }
}
int fact2(int n1)
{
    if (n1 == 0)
    {
        return 1;
    }
    else if (n1 == 1)
    {
        return 1;
    }
    else
    {
        return n1 * fact1(n1 - 1);
    }
}
