#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int longestValidParentheses(char* s) {

	int len, *dp, max = 0;

	if(!s || s[1] == '\0')
		return 0;

	len = strlen(s);
	dp = calloc(sizeof(int), len);
	
	if(s[0] == '(' && s[1] == ')') {
		dp[1] = 2;
		max = 2;
	}

	for(int i = 2; i < len; i++) {

		if(s[i] == '(')
			continue;
		if(s[i - 1] == '(')//()
			dp[i] = dp[i - 2] + 2;
		else if(s[i - dp[i - 1] - 1] == '('){//))
			dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
		}

		max = (max < dp[i]) ? dp[i] : max; 
	}
	return max;
}

int main()
{
	//char *s = ")()())";
	char *s = "()(())";
	int m = longestValidParentheses(s);
	printf("%d\n", m);
}
