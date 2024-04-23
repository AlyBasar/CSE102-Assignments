/*
(10x3=30 pts) Write C programs that print patterns in Figure 1, Figure 2 and Figure 3 separately.
Note: It is mandatory to use nested loops to generate the patterns.
All asterisks (*) should be printed by a separate printf() statement.
Hint: Patterns require adding appropriate number of blank spaces.
i11            bosluk             11 yıldız
1  *********   boşluk 1 ve 11 de
2 * ******* *  boşluk 2 ve 10 da
3 ** ***** **  boşluk 3 ve 9 da
4 *** *** ***  boşluk 4 ve 8 de
5 **** * ****  boşluk 5 ve 7 de
6 ***** *****  boşluk 6 da
7 **** * ****  boşluk 5 ve 7 de
8 *** *** ***  boşluk 4 ve 8 de
9 ** ***** **  boşluk 3 ve 9 da
10* ******* *  boşluk 2 ve 10 da
11 *********   boşluk 1 ve 11 de
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{

    int i, j, satir; // değişkenler

    satir = 10;

    // birinci desen
    for (i = 0; i <= 5; i++)
    { // 6 kez tekrar edecek döngü

        for (j = 0; j <= satir; j++)
        { // 11 kez tekrar edecek döngü

            if (i == j || ((i + j) == 10)) // satir ve sütun eşitse veya satir + sütun 10'a eşitse
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }

    // ikinci desen
    for (i = 0; i < 5; i++)
    { // 5 kez tekrar edecek döngü

        for (j = 0; j <= satir; j++)
        { // 11 kez tekrar edecek döngü

            if ((j - i) == 6 || (i + j) == 4) // satir - sütun 6'ya eşitse veya satir + sütun 4'e eşitse
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }

    getchar();
    getchar();
    return 0;
}