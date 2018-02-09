#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* s) {

	int top = -1, i = 0, len;
	char *stack;
	bool ret;

	if(s == NULL || s[1] == '\0')    
		return false;

	len = strlen(s);
	if(len % 2 == 1)
		return false;

	stack = (char *)calloc(1, len);

	while(s[i] != '\0') {
		switch(s[i]) {
			case '(':
			case '[':
			case '{':
				stack[++top] = s[i];
				break;
			case(')'):
				if(stack[top--] !='(') {
					ret = false;
					goto fin;
				}
				break;
			case(']'):
				if(stack[top--] !='[') {
					ret = false;
					goto fin;
				}
				break;
			case('}'):
				if(stack[top--] !='{') {
					ret = false;
					goto fin;
				}
				break;
			derault:
				ret = false;
				goto fin;
		}
		if(top < -1) {
			ret = false;
			goto fin;
		}
		i++;
	}

	if(top == -1)	
		ret = true;
	else
		ret = false;

fin:
	free(stack);
	return ret;
}

int main()
{
	char *s = "([])";
	printf("%d\n", isValid(s));
}
