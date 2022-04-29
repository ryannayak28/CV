#include <stdio.h>
#include <conio.h>

#include "factorial_sum_factors.h"
 
int main()
{
    int choice;
    int n;
    printf("Menu \n1)Factorial of n \n2)Sum of n Numbers \n3)Factors of n \n");
 
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter a Number: ");
        scanf("%d", &n);
        factorial(n);
        break;
 
    case 2:
        printf("Enter a Number: ");
        scanf("%d", &n);
        sumof(n);
        break;
 
    case 3:
        printf("Enter a Number: ");
        scanf("%d", &n);
        factors(n);
        break;
 
    default:
        break;
    }
    getch();

    return 0;
}
