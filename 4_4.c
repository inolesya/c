#include <stdio.h>
#include <stdlib.h> /* для atof() */
#include <ctype.h>

#define MAXOP 100  /* макс. размер операнда или оператора */
#define NUMBER '0' /* признак числа */
#define BUFSIZE 100
#define MAXVAL 100 /*макс. глубина в стеке*/
int getop (char []);
void push (double);
double pop (void);
double tail (void); // t напечатать только верхний элемент стека
void duplicate(void); // d дублировать верхний элемент стека
void printstack(void); // p напечатать стек
void swap(void); // s поменять местами два верхних элемента стека
void clear(void); // c очистка стека

/* калькулятор с обратной польской записью */
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
					push (0.0);
			}
			else
				printf("error: /0\n");
			break;   
		case 't':
			printf("Highest element of stack is: %.8g\n", tail());
			break;
		case 'd':
			duplicate();
			break;
		case 'p':
			printstack();
			break;
		case 's':
			swap();
			break;
		case 'c':
			clear();
			break;        
		case '\n':
			printf("Result: \t%.8g\n", pop());
			break;            
		default:
			printf("error: unknown operation %s\n", s);
			break;
		}
	}

	return 0;
}

int sp = 0;         
double val[MAXVAL]; // стек 

/* push: положить значение f в стек */ 
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack is full, %g hasn't got any place\n", f);
}

/* pop: взять с вершины стека и выдать в качестве результата */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf ("error: stack is empty\n");
		return 0.0;
	}
}

/* tail: взять с вершины стека и выдать в качестве результата */
double tail(void)
{
	if (sp > 0)
		return val[sp-1];
	else {
		printf ("error: stack is empty\n");
		return 0.0;
    }
}

/* duplicate: дублировать элемент с вершины стека */
void duplicate(void)
{
    if (sp <= 0)
		printf ("error: stack is empty\n");
    else if (sp > MAXVAL)
		printf("error: stack is full, new element hasn't got any place\n");
    else{
	    val[sp] = val[sp-1];
	    ++sp;
    }
}

/* printstack: печать содержимого стека */
void printstack(void)
{
	int i;
	if (sp > 0) {
		for (i = 0; i < sp; ++i)
			printf ("%.8g\t", val[i]);
	    printf ("\n");
	}
	else {
		printf ("error: stack is empty\n");
	}
}

/* swap: обмен содержимым двух верхних ячеек стека */
void swap(void)
{
    double t;
    // подумал, что лучше использовать операцию xor, но же double((
	if (sp > 1) {
        t = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = t;
	}
	else {
		printf ("error: need more elements for swap\n");
	}
}

/* clear: очистка содержимого стека */
void clear(void)
{
	sp = 0;
}

int getch(void);
void ungetch(int);

/* getop: получает следующий оператор или операнд */
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
