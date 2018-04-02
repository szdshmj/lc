#include "../inc.h"

void fetchIP(int level, char *start, char **str, char *tmp, char *s, int *returnSize)
{
	unsigned int sum = 0;

	if(level == 4) {
		if(s[0] == '\0') {
			tmp--;
			tmp[0] = '\0';
			if(*returnSize == 0 || strcmp(start, str[*returnSize - 1]) != 0) /////?????????
				str[(*returnSize)++]= strdup(start);
		}
		return;
	}

	for(int i = 0; i < 3; i++) {
		
		sum = sum * 10 + (s[i] - '0');

		if(sum < 256) {
			tmp[i] = s[i];
			tmp[i + 1] = '.';

			if(tmp[0] == '0' && tmp[1] != '.')
				break;

			fetchIP(level + 1, start, str, tmp + i + 2, s + i + 1, returnSize);
		}
	}
}

char** restoreIpAddresses(char* s, int* returnSize) {

	char tmp[16];
	char **str = malloc(sizeof(char *) * 1000);

	*returnSize =0;
	fetchIP(0, tmp, str, tmp, s, returnSize);

	return str;
}

int main(int argc, char **argv)
{
	int returnSize;
	char **str;

	str = restoreIpAddresses(argv[1], &returnSize);

	for(int i = 0; i < returnSize; i++) {
		printf("%s\n", str[i]);
		free(str[i]);
	}
	free(str);

	return 0;
}
