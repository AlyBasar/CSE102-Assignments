#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randmatrix(int matrix[][4]) // random doldurulacak matrix fonksiyonu
{
    int same[9] = {0}; // üretilen sayının adedini kontrol arreyi
    int randnum, i, j;
    srand(time(NULL));

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            do
            {
                randnum = (rand() % 8) + 1; // 1 ve 8 (dahil) arasında bir sayıyı üret
            } while (same[randnum] >= 2); // eğer randnum üretme sayısı 2 den fazlaysa tekrar sayı üret
            same[randnum]++;
            matrix[i][j] = randnum;
        }
    }
}

void ui(int matrix[][4], int control[][4]) // UI ' yazdırma fonksiyonu
{
    int i, j;

    printf("=============Numbers Matching Game=============\n");
    printf("|          0       1       2       3          |\n");

    for (i = 0; i < 4; i++) // matrixi yazdır
    {
        for (j = 0; j < 4; j++)
        {
            if (j == 0) // sütün başıysa giriş yazdır
                printf("|%d         ", i);
            if (control[i][j] == 1) // sayı seçilmişse göster
                printf("%d       ", matrix[i][j]);
            else if (control[i][j] == 2) // sayı bulunmuşsa yok et
                printf("        ");
            else // sayı seçilmemişse gizle
                printf("X       ");
        }
        printf("   |\n");
    }
    printf("===============================================\n");
}

int main(void)
{
    int matrix[4][4];
    int control[4][4] = {0};
    int totalguess = 0;
    int toend = 0;
    int found[8] = {0};
    int guess_1x, guess_1y, guess_2x, guess_2y, i;

    randmatrix(matrix);  // rastgele matrix üret
    ui(matrix, control); // UI ı yazdır

    printf("\n------Please enter \"-1\" to close the game------\n\n");

    while (toend != 8) // sayıların hepsi bulunana kadar devam et
    {
        printf("Enter X and Y coordinates of your firs guess:\n"); // 1. tahmini al
        printf("X = ");
        scanf("%d", &guess_1x);
        if (guess_1x == -1)
            break;
        printf("Y = ");
        scanf("%d", &guess_1y);
        if (guess_1y == -1)
            break;
        if (guess_1x < 0 || guess_1y < 0 || guess_1x > 3 || guess_1y > 3) // girilen koordinat hatalıysa
        {
            printf("İnvalid coordinates! Your guesses must be between 0 and 3!\n\n");
            continue;
        }

        if (control[guess_1x][guess_1y] == 2) // önceden bulunmuş sayıyı seçerse uyar ve başa dön
        {
            printf("\nYou already guessed this coordinate, try it again.\n\n");
            ui(matrix, control);
            continue;
        }

        control[guess_1x][guess_1y] = 1; // seçil koordinatı kontrolde değiştir

        ui(matrix, control); // güncel UI'ı yazdır

        printf("Enter X and Y coordinates of your second guess:\n"); // 2. tahmini al
        printf("X = ");
        scanf("%d", &guess_2x);
        if (guess_2x == -1)
            break;
        printf("Y = ");
        scanf("%d", &guess_2y);
        if (guess_2y == -1)
            break;

        if (guess_2x < 0 || guess_2y < 0 || guess_2x > 3 || guess_2y > 3) // girilen koordinat hatalıysa
        {
            printf("İnvalid coordinates! Your guesses must be between 0 and 3!\n\n");
            if (control[guess_1x][guess_1y] == 1)
                control[guess_1x][guess_1y] = 0;
            continue;
        }

        if (control[guess_2x][guess_2y] == 1 || control[guess_2x][guess_2y] == 2) // önceden bulunmuş sayıyı seçerse uyar ve başa dön
        {
            printf("\nYou already guessed this coordinate, try it again.\n\n");
            if (control[guess_2x][guess_2y] == 1)
                control[guess_2x][guess_2y] = 0;
            ui(matrix, control);
            continue;
        }
        control[guess_2x][guess_2y] = 1;

        totalguess++; // .tahmin sayısını arttır

        if (matrix[guess_1x][guess_1y] == matrix[guess_2x][guess_2y]) //.tahmin doğruysa
        {
            control[guess_1x][guess_1y] = 2;
            control[guess_2x][guess_2y] = 2;

            found[toend] = matrix[guess_1x][guess_1y];
            toend++; // bitti mi kontrolünü arttır

            printf("\n-----------------CORRECT GUESS-----------------\n\n");
            printf("Found numbers = ");
            for (i = 0; i < 8; i++)
            {
                if (found[i] != 0)
                    printf("%d - ", found[i]);
            }
            printf("\n");

            ui(matrix, control);
        }
        else //.tahmin yanlışsa
        {
            printf("\n------------------WRONG GUESS------------------\n\n");

            ui(matrix, control);
            control[guess_1x][guess_1y] = 0;
            control[guess_2x][guess_2y] = 0;
        }
    }
    if (toend == 8) // .tüm sayılar bulunmuşsa
    {
        printf("\nCongratulations You Found All The Numbers!!\n");
        printf("Total Number Of Tries:%d\n", totalguess);
    }

    printf("\n*******************GAME OVER*******************");

    getchar();
    getchar();
    return 0;
}