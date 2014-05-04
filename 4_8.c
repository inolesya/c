#include <stdio.h>

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

	while ((c = getch()) != EOF) {
		if (c == 'a') { /* заменим 'a' на 'A' в строке ввода 
                           странный пример, который не подразумевает необходимость использования buf 
                         подходящая задача - заменить только 'aa' на '*A'
                         */
			ungetch('A');
			putchar(getch());
		}
		else
			putchar(c);
	}

	return 0;
}
