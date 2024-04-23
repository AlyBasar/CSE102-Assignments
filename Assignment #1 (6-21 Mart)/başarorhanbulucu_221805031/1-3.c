/*
(10x3=30 pts) Write C programs that print patterns in Figure 1, Figure 2 and Figure 3 separately.
Note: It is mandatory to use nested loops to generate the patterns.
All asterisks (*) should be printed by a separate printf() statement.
Hint: Patterns require adding appropriate number of blank spaces.
i5           bosluk   yildiz
1 *********  0 boşluk 9 yıldız
2  *******   1 boşluk 7 yıldız
3   *****    2 boşluk 5 yıldız
4    ***     3 bosluk 3 yıldız
5     *      4 bosluk 1 yıldız
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{

    int i, j, yildiz, bosluk;

    yildiz = 9;
    bosluk = 0;

    for (i = 1; i <= 5; i++)
    { // 5 kez tekrar edecek döngü

        for (j = 0; j < bosluk; j++)
        { // boşluk
            printf(" ");
        }
        for (j = 0; j < yildiz; j++)
        { // yildiz
            printf("*");
        }

        printf("\n");
        yildiz -= 2;
        bosluk++;
    }

    getchar();
    getchar();
    return 0;
}