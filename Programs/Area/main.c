#include<stdio.h>
#include<conio.h>

#include "area.h"


int main()
{
    int choice, a, b;
    printf("Menu\n1)Area of Square \n2)Area of Rectangle \n3)Area of Triangle \n4)Area of Circle \n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    switch (choice)
    {
        case 1:
            printf("\nEnter the value of side: ");
            scanf("%d",&a);
            printf("Area = %d \n", ASquare(a));
            break;

        case 2:
            printf("\nEnter the length & breadth: ");
            printf("\nLength: ");scanf("%d",&a);
            printf("Breadth: ");scanf("%d",&b);
            printf("Area = %d \n", ARectangle(a, b));
            break;

        case 3:
            printf("\nEnter the base & height: ");
            printf("\nBase: ");scanf("%d",&a);
            printf("Height: ");scanf("%d",&b);
            printf("Area = %f \n", ATriangle(a, b));
            break;

        case 4:
            printf("\nEnter the radius: ");
            scanf("%d",&a);
            printf("Area = %f \n", ACircle(a));
            break;

        default:
            printf("\nPlease enter a valid choice");
            break;
    }
    printf("\n*****  Press any key to exit  *****");
    getch();

    return 0;
}