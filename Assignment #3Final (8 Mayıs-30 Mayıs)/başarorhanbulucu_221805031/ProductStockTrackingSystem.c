#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_products 100 // eklenebilecek en fazla product

struct Product // product struct'ı
{
    int id;
    char name[50];
    char unit[50];
    int quantity;
};

void ui() // UI fonksiyonu
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
    int choice = 0;

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

    while (choice != 7) // ana döngü
    {
        ui();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Add a product
        {
            int id, quantity;
            char productname[50], unit[20];

            printf("\n=============Add a product=============\n");
            printf("Enter product ID: ");
            scanf("%d", &id);
            printf("Enter name of the product: ");
            scanf("%s", &productname);
            printf("Enter the unit: ");
            scanf("%s", &unit);
            printf("Enter the quantity: ");
            scanf("%d", &quantity);

            //! product ekleme yapılacak

            printf("\n      |Product added succesfully|\n\n");
            break;
        }
        case 2: // Update a product
        {
            int uchoice = 0, id, quantity;
            char productname[50], unit[20];

            printf("\n===========Update a product============\n");
            printf("Enter product ID to update: ");
            scanf("%d", &id);

            //! verilen id li product bulunacak(eğer bulunamazsa uyarılacak)

            printf("Product found. Which field would you like to update?");
            while (uchoice != 5)
            {
                printf("\n1. ID\n2. Name\n3. Unit\n4. Quantity\n5. Exit\nEnter your choice (1-5):");
                scanf("%d", &uchoice);

                switch (uchoice)
                {
                case 1:
                    printf("Enter new ID: ");
                    scanf("%d", &id);
                    //! id update edilecek
                    printf("     |Product updated succesfully|\n\n");
                    uchoice = 5;
                    break;
                case 2:
                    printf("Enter new name: ");
                    scanf("%s", &productname);
                    //! name update edilecek
                    printf("     |Product updated succesfully|\n\n");
                    uchoice = 5;
                    break;
                case 3:
                    printf("Enter new unit: ");
                    scanf("%s", &unit);
                    //! unit update edilecek
                    printf("     |Product updated succesfully|\n\n");
                    uchoice = 5;
                    break;
                case 4:
                    printf("Enter new quantity: ");
                    scanf("%d", quantity);
                    //! quantity update edilecek
                    printf("     |Product updated succesfully|\n\n");
                    uchoice = 5;
                    break;
                case 5:
                    printf("Closing the update screen...\n\n");
                    break;
                default:
                    printf("Invalid choice!\n");
                    break;
                }
            }
            break;
        }
        case 3: // Search for a product with name
        {
            char productname[50];

            printf("\n=====Search for a product with name====\n");
            printf("Enter name of the product: ");
            scanf("%s", &productname);

            //! eğer name bulunamazsa tekrar istenecek

            printf("      |Products from %s|\n", productname);

            //! seçilen product listelenecek

            break;
        }
        case 4: // Increase quantity of a product
        {
            int id, quantity;

            printf("\n=====Increase quantity of a product====\n");
            printf("Enter product ID to update: ");
            scanf("%d", &id);

            //! verilen id li product bulunacak(eğer bulunamazsa uyarılacak)

            printf("Product found. Enter the increment quantity: ");
            scanf("%d", &quantity);

            //! icrement işlemi yapılacak

            // printf("   |New quantity of %s = %d|\n", productname, newquantity);
            break;
        }
        case 5: // Decrese quantity of a product
        {
            int id, quantity;

            printf("\n=====Decrese quantity of a product=====\n");
            printf("Enter product ID to update: ");
            scanf("%d", &id);

            //! verilen id li product bulunacak(eğer bulunamazsa uyarılacak)

            printf("Product found. Enter the decrement quantity: ");
            scanf("%d", &quantity);

            //! decrement işlemi yapılacak

            // printf("   |New quantity of %s = %d|\n", productname, newquantity);
            break;
        }
        case 6: // List all products
        {
            //! tüm productlar listelenecek
            break;
        }
        case 7: // Exit
        {
            printf("Program is closing...");
            break;
        }
        default:
        {
            printf("Invalid choice!\n\n");
            break;
        }
        }
    }

    fclose(fp);
    getchar();
    getchar();
    return 0;
}