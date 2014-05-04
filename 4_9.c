#include <stdio.h>
/* Проверено */
int getch(void);
void ungetch(int);

int buf = 0;          /* переменная-буфер */

int getch(void)       /* взять символ */
{
	int t;
	if (buf != EOF){
		t = buf;
		buf = EOF;
	}
	else
		t = getchar();
	return t;
}

void ungetch(int c)   /* вернуть символ на ввод */
{
	if (buf == EOF)
		buf = c;
	else
		printf("ungetch: слишком много символов\n");
}
int main()
{
	int c;

	do {
		c = getch();
			if (c == 'a') { /* заменим 'a' на 'A' в строке ввода */
			ungetch('A');
			putchar(getch());
			}
			else
			putchar(c);
		} while (c != EOF);
	return 0;
}
