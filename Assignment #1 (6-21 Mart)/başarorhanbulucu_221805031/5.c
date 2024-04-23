/*
(20 pts) In computer architecture, Amdahl's law is a formula which gives the theoretical speedup in latency
of the execution of a task at fixed workload that can be expected of a system whose resources are improved.
Where
s is the speedup of the part of the task that benefits from improved system resources;
p is the proportion of execution time that the part benefiting from improved resources originally occupied.
Write a program that takes positive numbers p and s from the user and then finds the (s) according to
equation You must print the resulting number as output.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{

	float s, p, slat; // değişkenler

	printf("-----Speedup Calculator: Amdahl's Law Program-----\n\n"); // başlık

	do
	{ // kulllanıcıdan pozitif S değeri al
		printf("Please enter a positive S value: ");
		scanf("%f", &s);
		if (s < 0) // negatifse uyarı ver
			printf("Error: S value must be positive!\n\n");
	} while (s < 0); //! koşul yanlış olduğu sürece başa döner

	do
	{ // kulllanıcıdan pozitif P değeri al
		printf("\nPlease enter a positive P value: ");
		scanf("%f", &p);
		if (p < 0)
			printf("Error: P value must be positive!\n");
	} while (p < 0); // negatifse uyarı ver

	slat = (1 / ((1 - p) + (p / s)));				   // sonucu hesapla
	printf("\nTheoretical Speedup is = %.3f\n", slat); // sonucu yazdır

	getchar(); // ekranı beklet
	getchar();
	return 0;
}