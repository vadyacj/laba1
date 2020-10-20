//Дана квадратная матрица порядка n.
//Выполнить транспонирование матрицы относительно главной диагонали.
//Вывести на экран исходную и транспонированную матрицу.
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
	int n, i, j, mas[20][20], tmp;
	setlocale(LC_ALL, "Rus");
	printf("Введите размер массива n*n:");
	scanf_s("%d", &n);
	printf("\nЗаполните массив");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf_s("%d", &mas[i][j]);
		}
	}
	system("CLS");
	for (i = 0; i < n; i++) {
		printf("\n");
		for (j = 0; j < n; j++) {
			printf("%4d", mas[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++) {
			tmp = mas[i][j];
			mas[i][j] = mas[j][i];
			mas[j][i] = tmp;
		}	
	}
	printf("\n");
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("\n");
		for (j = 0; j < n; j++) {
			printf("%4d", mas[i][j]);
		}
		printf("\n");
	}
	return 0;
}