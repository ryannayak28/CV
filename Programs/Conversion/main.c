#include<stdio.h>
#include<conio.h>

#include"convert.h"

int main()
{
    int choice; 
    float temp, len, vol;
    printf("Menu \n1)Celsius to Fahrenheit  \n2)Fahrenheit to Celsius \n3)Metre to Feet \n4)Feet to Metre \n5)Litre to Cubic Feet \n6)Cubic Feet to Litre \n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    switch (choice)
    {
        case 1:
            printf("\nEnter the temperature in Celsius: ");
            scanf("%f",&temp);
            printf("Temperature (in Fahrenheit) = %f \n",tempC2F(temp));
            break;

        case 2:
            printf("\nEnter the temperature in Fahrenheit: ");
            scanf("%f",&temp);
            printf("Temperature (in Celsius) = %f \n",tempF2C(temp));
            break;

        case 3:
            printf("\nEnter the Length in Metre: ");
            scanf("%f",&len);
            printf("Length (in Feet) = %f \n",lenM2F(len));
            break;
            
        case 4:
            printf("\nEnter the Length in Feet: ");
            scanf("%f",&len);
            printf("Length (in Metre) = %f \n",lenF2M(len));
            break;
            
        case 5:
            printf("\nEnter the Volume in Litre: ");
            scanf("%f",&vol);
            printf("Volume (in Cubic Feet) = %f \n",volL2CF(vol));
            break;

        case 6:
            printf("\nEnter the Volume in Cubic Feet: ");
            scanf("%f",&vol);
            printf("Volume (in Litre) = %f \n",volCF2L(vol));
            break;

        default:
            printf("\nPlease enter a valid choice");
            break;
    }
    printf("\n*****  Press any key to exit  *****");
    getch();

    return 0;
}
