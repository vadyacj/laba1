#include<stdio.h>
#include<locale.h>
int main() {
	setlocale(LC_ALL, "Russian");
	char mas[100] = { "Веселый, мим." };
	char k = 0, g;
	int f = 0, i;
	for (i = 0; mas[i]; i++) {
		if (mas[i] != ' ' &&  mas[i] != '.'  && mas[i] != ',') {
			if (f == 0) {
				g = mas[i];
				f = 1;
			}
			k++;
		}
		else {
			if (k != 0  && mas[i - 1] == g) {
				for (int j = i - k; j < i; j++) {
					printf("%c", mas[j]);
				}
			}
			printf(" ");
			f = 0;
			k = 0;
		}
	}
	if (k != 0  && g == mas[i - 1]) {
		for (int j = i - k; j < i; j++) {
			printf("%c", mas[j]);
		}
	}
	return 0;
}
