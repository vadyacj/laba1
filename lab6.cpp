/*в действительной квадратной матрице порядка n найти наибольший элемент
получить квадратную матрицу порядка n-1 выбросить строку и столбец */
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
	int n, i, j, mas[20][20], tmp, b1 = 0, b2 = 0;
	setlocale(LC_ALL, "Rus");
	printf("Введите размерность n*n:");
	scanf_s("%d", &n);
	printf("Заполните масиив \n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf_s("%d", &mas[i][j]);
		}
	}
	system("CLS");
	for (i = 0; i < n; i++) {
		printf("\n");
		for (j = 0; j < n; j++) {
			printf("%3d", mas[i][j]);
		}
	}
	printf("\n");
	tmp = mas[0][0];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (mas[i][j] < 0) {
				mas[i][j] *= (-1);
				if (mas[i][j] > tmp) {
					tmp = mas[i][j];
					b1 = i;
					b2 = j;
				}
			}
			if (mas[i][j] > tmp) {
				tmp = mas[i][j];
				b1 = i;
				b2 = j;
			}
		}
	}
	printf("Наибольший элемент: %d, его строка: %d, столбец: %d", tmp, b1, b2);
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("\n");
		for (j = 0; j < n; j++) {
			if (i != b1 && j != b2) {
				printf("%3d", mas[i][j]);
			}
		}
	}
	return 0;
}
