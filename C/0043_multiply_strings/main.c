#include "../inc.h"

char* simply(char *tmp, int tlen, char *num1, char s)
{
	memset(tmp, 0, tlen);
	for(int i = 0; i < strlen(num1); i++) {
		
	}

	printf("%s x %c\n", num1, s);
}

char* multiply(char* num1, char* num2) {
	
	char *result = NULL, *tmp = NULL;
	int tlen;

	if(num1 == NULL || num2 == NULL)
		return NULL;
		
	tlen = strlen(num1) + 2;
	tmp = malloc(tlen);

	for(int i = 0 ; i < strlen(num2); i++) {
		
		simply(tmp, tlen, num1, num2[i]);
	}

	return result;
}

int main()
{
	char *s1="12";	
	char *s2="34";

	char *s3="67";	
	char *s4="89";

	printf("%s*%s = %s\n", s1, s2, multiply(s1, s2));

	return 0;
}
