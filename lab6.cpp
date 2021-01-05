/*в действительной квадратной матрице порядка n найти наибольший элемент
получить квадратную матрицу порядка n-1 выбросить строку и столбец */
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
int module(int x);
int main()
{
	setlocale(LC_ALL, "Rus");
	int **ptr;
	int n = 0;		// количество строк
	int m = 0;		// количество столбцов
	int maxi = 0, maxj = 0, i, j, max = 0;
	ptr = (int**)n;
	ptr = (int**)m;
	printf("\n Введите количество строк и столбцов\n");
	scanf_s(" %d %d", &n, &m);
	printf("\n Введите элементы массива\n");
	ptr = (int**)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		ptr[i] = (int*)malloc(n * m * sizeof(int));
		for (int j = 0; j < m; j++) {
			scanf_s("%d", *(ptr + i) + j);
		}
	}
	printf("\n Исходный массив\n");
	for (int i = 0; i < n; i++)
	{
		printf("\n");
		for (int j = 0; j < m; j++)
			printf(" %4d", ptr[i][j]);
	}
	printf("\n");
	max = module(ptr[0][0]);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (max < module(ptr[i][j]))
			{
				max = module(ptr[i][j]);
				maxi = i;
				maxj = j;
				
			}
		}
	}
	printf("Максимальное по модулю число %d, оно находится на координатах %d %d\n\n", max, maxj, maxi);
	printf("\n измененный массив \n");
	for (i = 0; i < n; i++)
	{
		printf("\n");
		if (i == maxi)
			i++;
		
		for (j = 0; j < m; j++) {
			if (j == maxj)
				j++;
			printf(" %4d", ptr[i][j]);
		}
	}	
	return 0;
}
int module(int x)
{
	if (x < 0)
	{
		x *= -1;
	}
	return x;
}
