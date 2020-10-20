#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <locale.h>

int main()
{
	int j, i, pr = 1, sum = 0, kol = 0;
	const int m = 2, n = 2;
	int a[m], b[n];
	setlocale(LC_ALL, "Russian");
	printf("Заполните массив\n");
	for (i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
		scanf_s("%d", &b[i]);
	}

	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < m; j++) {
			pr = a[i] * b[j];
			if (pr > 10) {
				kol++;
				printf("\na[%d]  b[%d]", i , j);
				sum += pr;
			}
		}
	}
	printf("\nsum = %d", sum);
	printf("\nkol = %d", kol);
	

	return 0;
}