#include <stdio.h>
#define MAXLINE 1000 

int getlin(char line[], int max);
int strindex(char source[], char searchfor[]);
char pattern[] ="ould"; /* образец для поиска */

 
int main()
{
	char line[MAXLINE];
	int found = 0;
	int rind;
	while (getlin(line, MAXLINE) > 0)
		if ((rind = strindex(line, pattern)) >= 0) {
			printf ("%d\t%s", rind, line);
			found++;
		}
	return found;
}

  
int getlin(char s[], int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
		s[i] = '\0';
	return i;
  }

 
int strindex (char s[], char t[])
{
	int i, h, k;
	int tmp = -1;

	for (i = 0; s[i] != '\0'; i++) {
		for (h = i, k = 0; t[k] != '\0' && s[h] == t[k]; h++, k++);
		if (k > 0 && t[k] == '\0' && i > tmp)
			tmp = i;
	}
	return tmp;
}
