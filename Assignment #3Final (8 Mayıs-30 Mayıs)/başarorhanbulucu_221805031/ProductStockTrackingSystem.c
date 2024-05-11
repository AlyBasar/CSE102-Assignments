#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_products 100 // eklenebilecek en fazla product

struct Product
{
    int id;
    char name[50];
    char unit[50];
    int quantity;
};

void ui()
{
    printf("---------Stock Tracking System---------\nMenu:\n1. Add a product\n2. Update a product\n3. Search for a product with name\n4. Increase quantity of a product\n5. Decrease quantity of a product\n6. List all products\n7. Exit\n---------------------------------------\nEnter your choice (1-7):");
}

int main(void)
{
    struct Product products[MAX_products];
    int num_products = 0;
    FILE *fp;
    char filename[] = "products.txt";
    char line[200];
    char *token;
    int choice, i;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    while (fgets(line, 200, fp) != NULL)
    {
        token = strtok(line, ",");
        products[num_products].id = atoi(token);
        token = strtok(NULL, ",");
        strcpy(products[num_products].name, token);
        token = strtok(NULL, ",");
        strcpy(products[num_products].unit, token);
        token = strtok(NULL, ",");
        products[num_products].quantity = atoi(token);
        token = strtok(NULL, ",");
        // printf("%d,%s,%s,%d\n",products[num_products].id,products[num_products].name, products[num_products].unit, products[num_products].quantity);
        num_products++;
    }

    while (choice != 7)
    {
        ui();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            printf("Program is closing...");
            break;
        default:
            printf("Invalid choice!\n\n");
            break;
        }
    }

    fclose(fp);
    getchar();
    getchar();
    return 0;
}