#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char map[10][5] = {
		//{' ', '\0', }, 
		{'\0', }, 
		{'\0', }, 
		{'a', 'b', 'c', '\0'}, 
		{'d', 'e', 'f', '\0'}, 
		{'g', 'h', 'i', '\0'}, 
		{'j', 'k', 'l', '\0'}, 
		{'m', 'n', 'o', '\0'}, 
		{'p', 'q', 'r', 's', '\0'}, 
		{'t', 'u', 'v', '\0'}, 
		{'w', 'x', 'y', 'z', '\0'}
};

char ** letterCombinations(char *str, int *n)
{
	int idx;
	char **p = NULL;

	if(str == NULL || str[0] == '\0')
		return p;
	else if(str[1] == '\0') {
		idx = str[0] - '0';
		*n = strlen(map[idx]);
		if(*n > 0) {
			p = (char **) calloc(sizeof(char *), *n);
			for(int i = 0; i < *n; i++) {
				p[i] = (char *) calloc(2, 1);
				p[i][0] = map[idx][i];
			}
		}
		return p;
	}
	else {
		idx = str[0] - '0';
		int nl = strlen(map[idx]), nr = 0;

		if(nl > 0) {
			char **pp = letterCombinations(str + 1, &nr);

			*n = nl * nr;
			p = (char **) calloc(sizeof(char *), *n);
			for(int i = 0; i < nl; i++) {
				for(int j = 0; j < nr; j++) {
					p[i * nr + j] = calloc(strlen(pp[j]) + 2, 1);
					p[i * nr + j][0] = map[idx][i];
					strcat(p[i * nr + j], pp[j]);
				}
			}
			for(int i = 0; i < nr; i++)
				free(pp[i]);
			free(pp);
		}
		else
			p = letterCombinations(str + 1, n);
		return p;
	}
}

int main()
{
	int n;
	char **p = letter("234", &n);
	for(int i = 0; i < n; i++)
		printf("%s\n", p[i]);
}
