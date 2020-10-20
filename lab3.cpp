#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <locale.h>

int main()
{
	int n = 0;
	do {
		n++;
	} while ((7 * n * n * n + 81 * n * n - 1000000) < 0);
	printf("%d", n);
	return 0;
}