#include "../inc.h"

char* simply(char *num1, char s)
{
	printf("%s x %c\n", num1, s);
}

char* multiply(char* num1, char* num2) {

	if(num1 == NULL || num2 == NULL)
		return NULL;
	
	for(int i = 0 ; i < strlen(num2); i++) {
		
		simply(num1, num2[i]);
	}

	return NULL;
}

int main()
{
	char *s1="12";	
	char *s2="34";

	printf("%s*%s = %s\n", s1, s2, multiply(s1, s2));

	return 0;
}
