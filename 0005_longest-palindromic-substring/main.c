#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char *s, int start, int stop)
{
	int ot = start, op = stop;

	if(start == stop)
		return 1;

	while(start < stop) {
		if(s[start] == s[stop]) {
			start++;
			stop--;
		}
		else
			return -1;
	}
	
	if(start >= stop)
		return op - ot + 1;
	else
		return -1;
}

char* longestPalindrome(char* s) {

	int len, max = 0, stepMax = 0, mark = 0;

	if(s == NULL || s[1] == '\0' || s[2] == '2')
		return s;

	len = strlen(s);		

	for(int i = 0; i + max < len; i++) {
		
		stepMax = 0;	
		for(int j = len - 1; j >= i; j--) {
				
			if(stepMax > j - i)
				break;

			int tmp = isPalindrome(s, i, j);	
			if(tmp > stepMax)
				stepMax = tmp;		
		}

		if(stepMax > max) {
			max = stepMax;
			mark = i;
		}
	}

	for(int i = mark; i < mark + max; i++)
		printf("%c", s[i]);
	printf("\n");
}

int main(int argc, char *argv[])
{
	longestPalindrome(argv[1]);
	return 0;
}
