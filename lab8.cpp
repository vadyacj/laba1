//Выделить слова из строк и записать их в массив.
//Необходимо рассортировать массив слов по их длинам.
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void tolower(char* text, int n);
void tohigher(char* text, int i);
int main()
{
	system("chcp 1251");
	system("cls");
	int i = 0, j = 0, n, k = 0, t, kk = 0, start = 0, flag = 0, finish = 0;
	char temp, * mas, * mas2;
	mas = (char*)calloc(1, sizeof(char)); // создание массивов
	printf("Введите предложения (в конце строки поставьте точку)\n");
	while (1)
	{
		scanf_s("%c", &temp); //подготовка символа
		if (temp == '\n')
		{
			break; // выход тут
		}
		mas = (char*)realloc(mas, (j + 1) * sizeof(char)); //увеличить массив для ведения переменной
		mas[j] = temp; //ввод новой переменной
		j++; //подготовка следующего элемента
	}
	if (mas[j - 1] != ' ' || mas[j - 1] != '.')
	{
		mas = (char*)realloc(mas, (j + 1) * sizeof(char)); //если в конце не поставили точку, то ставим ее сами
		mas[j] = '.';
		j++;
	}
	n = j; //узнаем сколько всего символов
	mas2 = (char*)malloc(j * sizeof(char));
	printf("\n");
	for (i = 0; i < n; i++)
	{
		if (mas[i] == '.')
		{
			mas2[k] = ' ';      //заменяем точки на пробелы между слов
			k++;
		}
		else
		{
			mas2[k] = mas[i];
			k++;
		}
	}
	for (j = 0; j < n; j++)
	{
		if (mas2[j] == ' ' && mas2[j + 1] == ' ')
		{
			t = j + 1;
			for (t; t < n; t++)            //в этом цикле мы убираем пробелы, если их несколько подряд
			{
				mas2[t] = mas2[t + 1];
			}
			n--;
		}
	}
	mas2 = (char*)realloc(mas2, n * sizeof(char));  //сокращаем строку, этим убирая лишние пробелы

	for (i = 0; i < n; i++)
	{
		mas[i] = ' ';           //заполняем пробелами весь первый массив, чтобы не ставить пробелы между слов потом
	}
	for (j = 0; j < n; j++)
	{
		if (mas2[j] == ' ')    //считаем кол-во пробелов, чтобы знать кол-во слов
			flag++;
	}
	temp = 0;
	t = 0;
	for (k = 0; k < flag; k++)   //проходимся столько раз сколько слов в строке
	{
		for (j = 0; j < n; j++)
		{
			if (mas2[j] == ' ')
			{
				if (kk > temp)
				{
					start = j - kk;     //запоминаем начало,конец и длину слова
					finish = j;
					temp = kk;
				}
				kk = 0;    //обнуляем если пробел есть
			}
			else
			{
				kk++; //наращиваем длину
			}
		}
		for (start, t; start < finish; start++, t++)
		{
			mas[t] = mas2[start];  //переписываем самое длиное слово в пустой массив
			mas2[start] = ' ';      //заменяем его пробелами в другом массиве, чтобы слово не повторялось
		}
		t++; //пропускаем символ (типо пробел)
		temp = 0;     //обнуляем максимальную длину слова
	}
	mas[n - 1] = '.';
	for (i = 0, t = 0; i < n; i++, t++)
	{
		mas2[t] = mas[i];               //переписываем все во второй массив по усл
	}
	tolower(mas2, n);            //нижний регистр
	tohigher(mas2, 0);
	printf("Отсортированная строка по убыванию:\n");
	for (k = 0; k < n; k++)
	{                             
		printf("%c", mas2[k]);
	}
	printf("\n");
	free(mas);
	free(mas2);
	return 0;
}


void tolower(char* text, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (text[i] >= 'A' && text[i] <= 'Z')         //в нижний регистр
			text[i] += 'z' - 'Z';
		if (text[i] >= 'А' && text[i] <= 'Я')
			text[i] += 'я' - 'Я';
	}
}

void tohigher(char* text, int i)
{
	if (text[i] >= 'a' && text[0] <= 'z')                 //в верхний регистр
		text[i] += 'Z' - 'z';
	if (text[i] >= 'а' && text[0] <= 'я')
		text[i] += 'Я' - 'я';
}
