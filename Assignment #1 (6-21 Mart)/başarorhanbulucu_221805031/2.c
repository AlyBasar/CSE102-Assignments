/*
(10 pts) Write a program that takes a positive integer number n from the user and prints the numbers from 1 to
n. Then prints one time left shifted version of the numbers in a new line as shown in Figure 4 and Figure 5.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{

    int integer, i, j; // değişkenler

    printf("Please enter a integer: "); // kullancıdan integer al
    scanf("%d", &integer);

    for (i = 1; i <= integer; i++)
    { // 1 den integer'a kadar yaz

        for (j = i; j <= integer + i - 1; j++)
        {                                                    // kaydırma işlemini yap
            printf("%d", (j > integer) ? (j - integer) : j); //! değer doğruysa ilkini yanlışsa ikinciyi uygular
        }
        printf("\n");
    }

    getchar();
    getchar();
    return 0;
}