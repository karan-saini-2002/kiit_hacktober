#include<stdio.h>

int factorial(int n)
{
    if(n==0)
    return 1;
    else
    return factorial(n-1)*n;      
}

int main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    printf("Factorial : %d ", factorial(n));
    return 0;
}