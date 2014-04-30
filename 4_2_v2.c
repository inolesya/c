#include <ctype.h>
#include <stdio.h>

#define MAXLINE 1000

double atof(char source[]);
int getLine(char source[], int max);

main()
{
    double sum;
    char line[MAXLINE];
    while(getLine(line,MAXLINE) > 0)
        sum+=atof(line);
    printf("%0.6g\n",sum);
}

double atof(char s[])
{
    double val, power;
    int i, sign, subsign;
    int subval = 0;
    for (i = 0; isspace(s[i]); i++)
        ;
    sign=(s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val=0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i]-'0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++, power *= 10)
        val = 10.0 * val + (s[i]-'0');

    if (s[i] == 'e' || s[i] == 'E'){
        subsign=(s[++i] == '+') ? 0 : 1;
        while (isdigit(s[++i]))
            subval = subval*10 + (s[i] - '0');
        while (subval != 0){
            power = (subsign) ? (power * 10) : (power / 10);
            subval -=1;
        }
    }
       
    return sign * val / power;
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
