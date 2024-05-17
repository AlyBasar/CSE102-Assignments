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

void ui(); // UI fonksiyonu

int main(void)
{
    struct Product products[MAX_products];
    int num_products = 0;
    FILE *fp;
    char filename[] = "products.txt";
    char line[200];
    char *token;
    int i, choice = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    while (fgets(line, 200, fp) != NULL) // ürün okuma
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
        num_products++;
    }

    fclose(fp);

    while (choice != 7)
    {
        ui();
        scanf("%d", &choice);
        getchar(); // \n karakterini kaldır

        switch (choice)
        {
        case 1: // Add a product
        {
            int control = 0, id, quantity;
            char name[50], unit[50];

            printf("\n=============Add a product=============\n");

            do // Var olan bir id girilirse uyar
            {
                printf("Enter product ID: ");
                scanf("%d", &id);
                getchar(); // \n karakterini kaldır
                control = 1;

                for (i = 0; i < num_products; i++)
                {
                    if (id == products[i].id)
                    {
                        control = 0;
                        printf("A product with ID %d already exists.\n\n", id);
                        break;
                    }
                }

            } while (!control);

            printf("Enter name of the product: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0'; // \n karakterini kaldır
            printf("Enter the unit: ");
            fgets(unit, sizeof(unit), stdin);
            unit[strcspn(unit, "\n")] = '\0'; // \n karakterini kaldır
            printf("Enter the quantity: ");
            scanf("%d", &quantity);

            products[num_products].id = id;
            strcpy(products[num_products].name, name);
            strcpy(products[num_products].unit, unit);
            products[num_products].quantity = quantity;
            num_products++;

            printf("\n      |Product added succesfully|\n\n");
            break;
        }
        case 2: // Update a product
        {
            int control = 0, u_choice = 0, search_id, index, id, quantity;
            char name[50], unit[50];

            printf("\n===========Update a product============\n");

            do // Var olmayan bir id girilirse uyar
            {
                printf("Enter product ID to update: ");
                scanf("%d", &search_id);

                for (i = 0; i < num_products; i++)
                {
                    if (search_id == products[i].id)
                    {
                        printf("Product found. Which field would you like to update?");
                        index = i;
                        control = 1; // id bulundu
                        break;
                    }
                }

                if (control == 0)
                {
                    printf("Product with ID %d not found.\n\n", search_id);
                }
            } while (!control);

            while (u_choice != 5)
            {
                printf("\n1. ID\n2. Name\n3. Unit\n4. Quantity\n5. Exit\nEnter your choice (1-5):");
                scanf("%d", &u_choice);
                getchar(); // \n karakterini kaldır

                switch (u_choice)
                {
                case 1: // id update
                {

                    control = 0;

                    do // Var olan bir id girilirse uyar
                    {
                        printf("Enter new ID: ");
                        scanf("%d", &id);

                        control = 1;

                        for (i = 0; i < num_products; i++)
                        {
                            if (id == products[i].id)
                            {
                                printf("A product with ID %d already exists.\n\n", id);
                                control = 0;
                            }
                        }

                    } while (!control);

                    products[index].id = id;

                    printf("     |Product updated succesfully|\n\n");
                    u_choice = 5;

                    break;
                }
                case 2: // name update
                {
                    printf("Enter new Product name: ");
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = '\0'; // \n karakterini kaldır

                    strcpy(products[index].name, name);

                    printf("     |Product updated succesfully|\n\n");
                    u_choice = 5;
                    break;
                }
                case 3: // unit update
                {
                    printf("Enter new Unit: ");
                    fgets(unit, sizeof(unit), stdin);
                    unit[strcspn(unit, "\n")] = '\0'; // \n karakterini kaldır

                    strcpy(products[index].unit, unit);

                    printf("     |Product updated succesfully|\n\n");
                    u_choice = 5;
                    break;
                }
                case 4: // quantity update
                {
                    printf("Enter new Quantity: ");
                    scanf("%d", &quantity);

                    products[index].quantity = quantity;

                    printf("     |Product updated succesfully|\n\n");
                    u_choice = 5;
                    break;
                }
                case 5: // exit
                {
                    printf("Closing the update screen...\n\n");
                    break;
                }
                default:
                {
                    printf("Invalid choice!\n");
                    break;
                }
                }
            }

            break;
        }
        case 3: // Search for a product with name
        {
            int control = 0, index;
            char search_name[50];

            printf("\n=====Search for a product with name====");

            do // Var olmayan bir isim girilirse uyarı ver
            {
                printf("\nEnter name of the product: ");
                fgets(search_name, sizeof(search_name), stdin);
                search_name[strcspn(search_name, "\n")] = '\0'; // \n karakterini kaldır

                for (i = 0; i < num_products; i++)
                {
                    if (strcmp(products[i].name, search_name) == 0)
                    {
                        if (control == 0)
                        {
                            printf("      |Products from %s|\n", search_name);
                            control = 1;
                        }

                        printf("%d      %s      %s      %d\n", products[i].id, products[i].name, products[i].unit, products[i].quantity);
                    }
                }

                if (control == 0)
                {
                    printf("The product %s does not exist.\n", search_name);
                }
                else
                    printf("\n");

            } while (!control);

            break;
        }
        case 4: // Increase quantity of a product
        {
            int search_id, control = 0, quantity;

            printf("\n=====Increase quantity of a product====\n");

            do // Var olmayan bir id girilirse uyar
            {
                printf("Enter product ID to increase update: ");
                scanf("%d", &search_id);

                for (i = 0; i < num_products; i++)
                {
                    if (search_id == products[i].id)
                    {
                        printf("Product found. Enter the increment quantity: ");
                        scanf("%d", &quantity);

                        products[i].quantity += quantity;

                        printf("      |Increment Succesfull. New quantity of %s = %d|\n\n", products[i].name, products[i].quantity);

                        control = 1; // id bulundu
                        break;
                    }
                }

                if (control == 0)
                {
                    printf("Product with ID %d not found.\n\n", search_id);
                }
            } while (!control);

            break;
        }
        case 5: // Decrese quantity of a product
        {
            int search_id, control = 0, quantity;

            printf("\n=====Decrese quantity of a product=====\n");

            do // Var olmayan bir id girilirse uyar
            {
                printf("Enter product ID to decrese update: ");
                scanf("%d", &search_id);

                for (i = 0; i < num_products; i++)
                {
                    if (search_id == products[i].id)
                    {
                        printf("Product found. Enter the decrement quantity: ");
                        scanf("%d", &quantity);

                        products[i].quantity -= quantity;

                        printf("      |Decrement Succesfull. New quantity of %s = %d|\n\n", products[i].name, products[i].quantity);

                        control = 1; // id bulundu
                        break;
                    }
                }

                if (control == 0)
                {
                    printf("Product with ID %d not found.\n\n", search_id);
                }
            } while (!control);

            break;
        }
        case 6: // List all products
        {
            printf("    ID    Product Name                   Unit          Quantity\n");

            for (i = 0; i < num_products; i++)
            {
                printf("%-3d %-5d %-30s %-13s %-10d\n", (i + 1), products[i].id, products[i].name, products[i].unit, products[i].quantity);
            }
            printf("\n");
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

    getchar();
    return 0;
}

void ui() // UI fonksiyonu
{
    printf("---------Stock Tracking System---------\nMenu:\n1. Add a product\n2. Update a product\n3. Search for a product with name\n4. Increase quantity of a product\n5. Decrease quantity of a product\n6. List all products\n7. Exit\n---------------------------------------\nEnter your choice (1-7):");
}