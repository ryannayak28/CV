#include <stdio.h>
#include <conio.h>

#include "fib_prime_leap.h"

int main()
{
    int choice, a;
    printf("Menu \n1)Fibbonaci Series \n2)Prime Series \n3)Leap Year \n");
    scanf("%d", &choice);
 
    switch (choice)
    {
        case 1:
            fibbSeries(n);
            break;
    
        case 2:
            PrimeNumbers(n);
            break;
    
        case 3:
            printf("\nEnter any year value: ");
            int r;
            scanf("%d", &r);
            LeapYear(r);
            break;
    
        default:
            printf("\nEnter a valid choice");
            break;
    }
    getch();
    return 0;
}
 
