#include <stdio.h>
#include <ctype.h>
#define MAXLEN 50

void expand(char s1[], char s2[]);

int main()
{
	char in[MAXLEN] = "-1-a-a-f-27-g-9-\0";
	char out[MAXLEN];
	printf("s1 = %s\n", in);
	expand(in, out);
	printf("s2 = %s\n", out);
	return 0;
}


void expand(char s1[], char s2[])
{
	int i, j;
	char t;
	for (i = 0, j = 0; s1[i] != '\0'; i++) {
		if ( isdigit(s1[i]) && s1[i+1] == '-' &&
									 isdigit(s1[i+2]) ) {
			for (t = s1[i]; t < s1[i+2]; t++)
					s2[j++] = t;
					i += 1;    
			}
		else if ( islower(s1[i]) && s1[i+1] == '-' &&
                                      islower(s1[i+2]) ) {
			for (t = s1[i]; t < s1[i+2]; t++)
				s2[j++] = t;
				i++;    
			}
		else if ( isupper(s1[i]) && s1[i+1] == '-' &&
                                      isupper(s1[i+2]) ) {
			for (t = s1[i]; t < s1[i+2]; t++)
				s2[j++] = t;
				i++;    
			}
		else
			s2[j++] = s1[i];
	}
	s2[j] = '\0';
}
