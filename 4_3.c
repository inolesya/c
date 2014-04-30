#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>

#define MAXOP 100 //мах. размер операнда 
#define NUMBER '0' //признак числа
#define BUFSIZE 100
#define MAXVAL 100 //мах. глубина стека

int getop (char []);
void push (double f);
double pop (void);

int main()
{
	int type;
	double op1, op2;
	char s[MAXOP];

	while ((type = getop (s)) != EOF) {
		switch (type) {
		case NUMBER:
			push (atof(s));
			break;
		case '+':
			push (pop() + pop());
			break;
		case '*':
			push (pop() * pop());
			break;
		 case '-':
			op2 = pop();
			push (pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push (pop() / op2);
			else
				printf("error: /0\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0) {
				op1 = pop();
				if (op1 > op2)
					push ( op1 - op2 * (int) (op1 / op2) );
				else
					push (op1);
			}
			else
				printf("error: /0\n");
			break;   
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown operation %s\n", s);
			break;
		}
	}
    
	return 0;
}

int sp = 0;
double val[MAXVAL]; 


void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stek is ful, %g doesn't have any place\n", f);
}

//рор - взять с вершины стека и выдать за результат
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf ("error: stek is empty\n");
	return 0.0;
	}
}


int getch(void);
void ungetch(int);

int getop(char s[])
{
	int i=0, c, t;
	while ((s[i] = c = getch()) == ' ' || c == '\t');
	if (!isdigit(c) && c != '.'){
		if (c == '-') {
			if (isdigit(t = getch()) || t == '.') {
				c = t;
				s[++i] = c;
			}
			else {
				ungetch(t);
				return c;  
			}
		}
		else {
			return c;      	
		}
	}
	if (isdigit(c)) 
		while (isdigit(s[++i] = c = getch()));
	if (c =='.')    
		while (isdigit(s[++i] = c = getch()));
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

char buf[BUFSIZE];  
int bufp = 0;      

int getch(void)       
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)   
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many symbols\n");
	else
		buf[bufp++] = c;
}
