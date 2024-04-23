/*
(10x3=30 pts) Write C programs that print patterns in Figure 1, Figure 2 and Figure 3 separately.
Note: It is mandatory to use nested loops to generate the patterns.
All asterisks (*) should be printed by a separate printf() statement.
Hint: Patterns require adding appropriate number of blank spaces.
i11            bosluk        11 yıldız
1  **********  boşluk 1 de
2 * *********  boşluk 2 de
3 ** ********  boşluk 3 te
4 *** *******  boşluk 4 te
5 **** ******  boşluk 5 te
6 ***** *****  boşluk 6 da
7 ****** ****  boşluk 7 de
8 ******* ***  boşluk 8 de
9 ******** **  boşluk 9 da
10********* *  boşluk 10 da
11**********   boşluk 11 de
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{

    int x, y, satir; // değişkenler

    satir = 11;

    for (x = 1; x <= satir; x++)
    { // 11 kez tekrar edecek döngü

        for (y = 1; y <= satir; y++)
        { // 11 kez tekrar edecek döngü

            if (y != x)
            { // sütün ve satır sayısı birbirine eşit değilse '*' koy
                printf("*");
            }
            else
            { // sütün ve satır sayısı birbirine eşitse ' ' koy
                printf(" ");
            }
        }
        printf("\n"); // sonraki satıra geç
    }

    getchar();
    getchar();
    return 0;
}