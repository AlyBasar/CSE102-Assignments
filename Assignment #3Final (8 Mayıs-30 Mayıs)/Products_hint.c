#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_products 100 // Maximum number of products that can be stored

// Define a struct to hold product information
struct Product {
    int id;
    char name[50];
    char unit[50];
    int quantity;
};

int main() {
    struct Product products[MAX_products]; // Array of products
    int num_products = 0; // Number of products currently in the array
    FILE *fp; // Pointer to file
    char filename[] = "products.txt"; // Name of file containing product information
    char line[200]; // Buffer for reading each line of the file
    char *token; // Pointer to token within line
    int i;

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    // Read each line of file, parse product information, and store in array
    while (fgets(line, 100, fp) != NULL) {
        token = strtok(line, ",");
        products[num_products].id=atoi(token);
        token = strtok(NULL, ",");
        strcpy(products[num_products].name, token);
        token = strtok(NULL, ",");
        strcpy(products[num_products].unit, token);
        token = strtok(NULL, ",");
        products[num_products].quantity=atoi(token);
        token = strtok(NULL, ",");
        //printf("%d,%s,%s,%d\n",products[num_products].id,products[num_products].name, products[num_products].unit, products[num_products].quantity);
        num_products++;
    }

    // Close file
    fclose(fp);
	return 0;
}

