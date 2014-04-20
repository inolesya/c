#include <stdio.h>
#define MAXLEN 100

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
	char input[MAXLEN] = "la\tla\tta\n";
	char output[MAXLEN];
	printf("Original   = %s\n", input);
	escape(output, input);
	printf("Escaped    = %s\n", output);
	unescape(input, output);
	printf("Unescaped  = %s\n", input);
	printf("The End\n");
	return 0;
}
	void escape(char s[], char t[])
	{
		int i, j;
		for (i = 0, j = 0; s[i]; i++, j++)
			switch (t[i]) {
				case '\t':
					s[j++] = '\\';
					s[j] = 't';
					break;
				case '\n':
					s[j++] = '\\';
					s[j] = 'n';
					break;
				default:
					s[j] = t[i];
					break;
			}
		s[j] = t[i];  // \0  !
	}
	void unescape(char s[], char t[])
	{
		int i, j;
		for (i = 0, j = 0; s[i]; i++, j++)
			switch (t[i]) {
				case '\\':
			switch (t[++i]) {
				case 't':
					s[j] = '\t';
					break;
				case 'n':
					s[j] = '\n';
					break;
				}
			break;
			default:
			s[j] = t[i];
			break;
		}
      s[j] = t[i];
	}

