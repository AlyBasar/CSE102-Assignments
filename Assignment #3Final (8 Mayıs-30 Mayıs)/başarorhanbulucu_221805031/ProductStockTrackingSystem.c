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

    fp = fopen(filename, "r+");
    if (fp == NULL)
    {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    while (fgets(line, 200, fp) != NULL) // num_products hesaplama
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

    while (choice != 7) // ana döngü
    {
        ui();
        scanf("%d", &choice);
        getchar(); // \n karakterini kaldır

        switch (choice)
        {
        case 1: // Add a product
        {
            int kontrol = 0, i, id, quantity;
            char productname[100], unit[50];

            printf("\n=============Add a product=============\n");
            while (!kontrol) // hali hazırda bulunan bir id girilirse uyarı ver
            {
                printf("Enter product ID: ");
                scanf("%d", &id);
                getchar();

                kontrol = 1;

                for (i = 0; i < num_products; i++)
                {
                    if (products[i].id == id)
                    {
                        kontrol = 0;
                        printf("A product with ID %d already exists.\n\n", id);
                        break;
                    }
                }
            }
            printf("Enter name of the product: ");
            fgets(productname, sizeof(productname), stdin);
            productname[strcspn(productname, "\n")] = '\0'; // \n karakterini kaldır
            printf("Enter the unit: ");
            fgets(unit, sizeof(unit), stdin);
            unit[strcspn(unit, "\n")] = '\0'; // \n karakterini kaldır
            printf("Enter the quantity: ");
            scanf("%d", &quantity);

            fseek(fp, 0, SEEK_END); // dosya sonuna git
            fprintf(fp, "%d,%s,%s,%d\n", id, productname, unit, quantity);
            num_products++;

            printf("\n      |Product added succesfully|\n\n");
            break;
        }
        case 2: // t Update a product
        {
            int uchoice = 0, i, kontrol = 0, update_id, id, quantity;
            char productname[50], unit[20];

            fseek(fp, 0, SEEK_SET); // dosya başına git

            FILE *temp_fp; // geçici temp dosyası oluştur
            temp_fp = fopen("temp.txt", "w+");
            if (temp_fp == NULL)
            {
                printf("Error: could not open file %s\n", filename);
                return 1;
            }

            printf("\n===========Update a product============\n");

            while (!kontrol)
            {
                printf("Enter product ID to update: ");
                scanf("%d", &update_id);

                for (i = 0; i < num_products; i++)
                {
                    if (products[i].id == update_id)
                    {
                        printf("Product found. Which field would you like to update?");
                        kontrol = 1; // id bulundu
                        break;
                    }
                    else
                    {
                        printf("Product with ID %d not found.\n\n", id);
                        break;
                    }
                }
            }

            while (uchoice != 5)
            {
                printf("\n1. ID\n2. Name\n3. Unit\n4. Quantity\n5. Exit\nEnter your choice (1-5):");
                scanf("%d", &uchoice);
                getchar();

                switch (uchoice)
                {
                case 1: // id update
                {
                    printf("Enter new ID: ");
                    scanf("%d", &id);

                    for (i = 0; i < num_products; i++)
                    {
                        if (products[i].id == update_id)
                        {
                            fprintf(temp_fp, "%d,%s,%s,%d\n", id, products[i].name, products[i].unit, products[i].quantity);
                        }
                        else
                        {
                            fprintf(temp_fp, "%d,%s,%s,%d\n", products[i].id, products[i].name, products[i].unit, products[i].quantity);
                        }
                    }

                    printf("     |Product updated succesfully|\n\n");
                    uchoice = 5;
                    break;
                }
                case 2: // name update
                {
                    printf("Enter new name: ");
                    fgets(productname, sizeof(productname), stdin);
                    productname[strcspn(productname, "\n")] = '\0'; // \n karakterini kaldır

                    for (i = 0; i < num_products; i++)
                    {
                        if (products[i].id == update_id)
                        {
                            fprintf(temp_fp, "%d,%s,%s,%d\n", products[i].id, productname, products[i].unit, products[i].quantity);
                        }
                        else
                        {
                            fprintf(temp_fp, "%d,%s,%s,%d\n", products[i].id, products[i].name, products[i].unit, products[i].quantity);
                        }
                    }

                    printf("     |Product updated succesfully|\n\n");
                    uchoice = 5;
                    break;
                }
                case 3: // unit update
                {
                    printf("Enter new unit: ");
                    fgets(unit, sizeof(unit), stdin);
                    unit[strcspn(unit, "\n")] = '\0'; // \n karakterini kaldır
                    for (i = 0; i < num_products; i++)
                    {
                        if (products[i].id == update_id)
                        {
                            fprintf(temp_fp, "%d,%s,%s,%d\n", products[i].id, products[i].name, unit, products[i].quantity);
                        }
                        else
                        {
                            fprintf(temp_fp, "%d,%s,%s,%d\n", products[i].id, products[i].name, products[i].unit, products[i].quantity);
                        }
                    }

                    printf("     |Product updated succesfully|\n\n");
                    uchoice = 5;
                    break;
                }
                case 4: // quantity update
                {
                    printf("Enter new quantity: ");
                    scanf("%d", &quantity);

                    for (i = 0; i < num_products; i++)
                    {
                        if (products[i].id == update_id)
                        {
                            fprintf(temp_fp, "%d,%s,%s,%d\n", products[i].id, products[i].name, products[i].unit, quantity);
                        }
                        else
                        {
                            fprintf(temp_fp, "%d,%s,%s,%d\n", products[i].id, products[i].name, products[i].unit, products[i].quantity);
                        }
                    }

                    printf("     |Product updated succesfully|\n\n");
                    uchoice = 5;
                    break;
                }
                case 5:
                {
                    printf("Closing the update screen...\n\n");
                    break;
                }
                default:
                    printf("Invalid choice!\n");
                    break;
                }
            }

            fclose(temp_fp); // geçici dosyayı kapat
            fclose(fp);      // orijinal dosyayı kapat

            if (rename("temp.txt", "products.txt") != 0) // geçici temp dosyasının ismini değiştir
            {
                printf("Error: could not rename file\n");
                return 1;
            }

            fp = fopen(filename, "r+"); // asıl dosyayı tekrar aç
            if (fp == NULL)
            {
                printf("Error: could not open file %s\n", filename);
                return 1;
            }

            break;
        }
        case 3: // Search for a product with name
        {
            int i, kontrol = 0, found = 0;
            char productname[50];

            printf("\n=====Search for a product with name====");

            while (!kontrol)
            {
                printf("\nEnter name of the product: ");
                fgets(productname, sizeof(productname), stdin);
                productname[strcspn(productname, "\n")] = '\0'; // \n karakterini kaldır

                for (int i = 0; i < num_products; i++)
                {
                    if (strcmp(products[i].name, productname) == 0)
                    {
                        if (!found)
                        {
                            printf("      |Products from %s|\n", productname);
                            found = 1;
                        }
                        printf("%d      %s      %s      %d\n", products[i].id, products[i].name, products[i].unit, products[i].quantity);
                    }
                }

                if (!found)
                { // Eğer hiçbir ürün bulunamadıysa
                    printf("The product %s does not exist.\n", productname);
                }
                else
                {
                    kontrol = 1;
                    printf("\n");
                }
            }
            break;
        }
        case 4: // t Increase quantity of a product
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
        case 5: // t Decrese quantity of a product
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
            fseek(fp, 0, SEEK_SET); // dosya başına git
            printf("  ID    Product Name                   Unit          Quantity\n");
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
                printf("  %-5d %-30s %-13s %-10d\n", products[num_products].id, products[num_products].name, products[num_products].unit, products[num_products].quantity);
                num_products++;
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

    fclose(fp);
    getchar();
    getchar();
    return 0;
}