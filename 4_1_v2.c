#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int max);
int strindex(char source[], char searchfor[], int lengthOfSource);

char pattern[] = "ould";

main()
{
    char line[MAXLINE];
    int found = 0;
    int l;
    while ((l = getLine(line,MAXLINE))>0)
        if ((l = strindex(line, pattern, l)) >= 0){
            printf("%s\t%d\n",line,l);
            found++;
        }
    return found;
}


int getLine(char s[], int lim)
{
    int i, c;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i]='\0';
    return i;
}

int strindex(char s[], char t[], int lenS)
{
    int i, j, k;
    for (i = lenS; i>0; i--){
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k>0 && t[k] == '\0')
            return i;
    }
    return -1;
}
