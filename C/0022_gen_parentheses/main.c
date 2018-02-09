#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void generateParenthes(char **p, char *tmp, int left, int right, int *returnSize)
{
	int len = strlen(tmp);

	if(left	== 0 && right == 0) {

		p[(*returnSize)] = calloc(tmp + 1, 1);
		strcpy(p[(*returnSize)++], tmp);
		return;
	}

	if(left > 0) {
		tmp[len] = '(';	
		generateParenthes(p, tmp, left - 1, right, returnSize);
		tmp[len] = '\0';
	}
	if(right > 0 && left < right) {
		tmp[len] = ')';	
		generateParenthes(p, tmp, left, right - 1, returnSize);
		tmp[len] = '\0';
	}	
}

char** generateParenthesis(int n, int* returnSize) {

	char *tmp = (char *) calloc(1, 2 * n + 1);
	char **p = (char **) malloc(1000000);

	generateParenthes(p, tmp, n , n, returnSize);
	return p;
}

int main(int argc, char *argv[])
{
	int n = 0;

	char **p = generateParenthesis(atoi(argv[1]), &n);

	for(int i = 0; i < n; i++)
		printf("%s\n", p[i]);

	return 0;
}
