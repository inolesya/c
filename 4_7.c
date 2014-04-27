#include <stdio.h>
#include <string.h>

int getch(void);
void ungetch(int);
void ungets(char []);

#define BUFSIZE 100

char buf[BUFSIZE];    /* буфер для ungetch */
int bufp = 0;         /* след. свободная позиция в буфере */

int getch(void)       /* взять символ */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)   /* вернуть символ на ввод */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: слишком много символов\n");
	else
	buf[bufp++] = c;
}

void ungets(char s[])
{
	int i=strlen(s);

	while (i >= 0) {
		ungetch(s[i--]);
	}
}

int main()
{
	char string[] = "Here you\nare\n\0";
	int c;

	ungets(string);

	while((c = getch()) != EOF) {
		putchar(c);
	}

	return 0;
}
