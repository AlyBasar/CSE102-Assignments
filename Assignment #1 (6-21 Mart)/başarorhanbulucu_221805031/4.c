/*
(20 pts) Write a program that takes 10 integer inputs from the user and finds the second highest number. The
second highest number must be printed as output.
Assume the input numbers are: 20, 42, 571, 15, 54, 2, 6, 107, 94, 82, 75
Than a sample output may be as follows: SHN is: 107
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{

	int integers[10], hn, shn, i; // değişkenler

	printf("Please enter 10 integer:\n\n"); // bilgilendirme

	for (i = 0; i < 10; i++)
	{ // kullanıcıdan 10 sayı al
		printf("Number %d : ", i + 1);
		scanf("%d", &integers[i]);
	}

	hn = integers[0]; // değerleri eşitle
	shn = integers[0];

	for (i = 0; i < 10; i++)
	{
		if (integers[i] > hn)
		{ // en büyük sayıyı belirle
			shn = hn;
			hn = integers[i];
		}
		else if (integers[i] > shn && integers[i] != hn)
		{ // ikinci en büyük sayıyı belirle
			shn = integers[i];
		}
	}

	printf("\nSecond highest number is = %d\n\n", shn); // ikinci en büyük sayıyı yazdır

	getchar(); // ekranı beklet
	getchar();
	return 0;
}