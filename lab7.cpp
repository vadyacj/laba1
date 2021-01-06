/*Даны натуральное число n и символы s1,…,sn. Строку s1,…,sn обработать так,
чтобы все слова, состоящие только из цифр, были удалены, их сумма стояла последним словом в строк*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	char* str;
	int n = 0, i, sum = 0;
	printf("введите длину строки ");
	scanf_s("%d", &n);
	str = (char*)calloc(n, sizeof(char));
	printf("введите строку символов ");
	rewind(stdin); // чистка входного буффера
	fgets(str, n, stdin);
	for (i = 0; i < n; i++)
		if (*(str + i) == '\n')
			*(str + i) = '\0';
	printf("\nИсходная строка символов : %s", str);
	for (i = 0; *(str + i) != '\0'; i++) {
		if (str[i] == '1' || str[i] == '0' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9') {
			int ia = (int)str[i];
			sum += ia - 48;
			str[i] = ' ';
		}
	}
	printf_s("\n");
	puts(str);
	printf_s("%d", sum);
	return 0;
}