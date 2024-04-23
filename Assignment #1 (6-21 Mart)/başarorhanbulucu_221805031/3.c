/*
(20 pts) The Open Systems Interconnection model (OSI model) is a reference model from the International
Organization for Standardization (ISO) that "provides a common basis for the coordination of standards
development for the purpose of systems interconnection."
Write a program that takes the layer number as input from the user and prints out the “layer name” and “layer
description” as given in Figure 6.
Note: Mandatory to use a “switch case” statement
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{

    int layer; // değişkenler

    printf("1 - Physical Layer\n2 - Data Link Layer\n3 - Network Layer\n4 - Transport Layer\n5 - Session Layer\n6 - Presentation Layer\n7 - Application Layer\n\n");

    printf("Enter the layer for which you want to see the description: "); // bilgilendirme
    scanf("%d", &layer);

    switch (layer) // seçilen layere göre cevap ver
    {
    case 1:
        printf("\nPhysical Layer  -   Transmits raw bit stream over the physical medium.\n\n");
        break;
    case 2:
        printf("\nData Link Layer  -   Defines the format of data on the network.\n\n");
        break;
    case 3:
        printf("\nNetwork Layer  -   Decides which physical path the data will take.\n\n");
        break;
    case 4:
        printf("\nTransport Layer  -   Transmits data using transmission protocols including TCP and UDP.\n\n");
        break;
    case 5:
        printf("\nSession Layer  -   Maintains connections and is responsible for controlling ports and sessions.\n\n");
        break;
    case 6:
        printf("\nPresentation Layer  -   Ensures that data is in a usable format and is where data encryption occurs.\n\n");
        break;
    case 7:
        printf("\nApplication Layer  -   Human-computer interaction layer, where applications can access the network services.\n\n");
        break;
    default:
        printf("\nYou have entered the invalid layer!!\n\n");
        break;
    }

    getchar();
    getchar();
    return 0;
}
