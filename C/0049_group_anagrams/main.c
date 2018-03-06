#include "../inc.h" 

struct Hash_str {
	char *sortedStr;
	int count;
	int *list;
};

void dump(char ***ret, int returnSize, int *columnSizes) {

	for(int i = 0; i < returnSize; i++) {
		
		for(int j = 0; j < columnSizes[i]; j++)
			printf("%s ", ret[i][j]);

		printf("\n");
	}
}

int compare(const void *a, const void *b) { return (*(char *) a - *(char *)b);}

int BKDRHash(char *s, int len)
{
	int seed = 31;
	unsigned long hash = 0;

	while(*s) {
	
		hash = hash * seed + *s;
		s++;
	}
	return hash % len;
}

char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {

	struct Hash_str *hs;
	*returnSize = 0;
	*columnSizes = NULL;

	if(strsSize == 0 || strs == NULL)
		return NULL;

	hs = calloc(sizeof(struct Hash_str), strsSize);
	for(int i = 0; i < strsSize; i++) {

		char *tmp;
		int h;

		tmp = strdup(strs[i]);
		qsort(tmp, strlen(tmp), sizeof(char), &compare);
		h = BKDRHash(tmp, strsSize);// h maybe confilct

		if((hs[h].sortedStr != NULL) && (strcmp(hs[h].sortedStr, tmp) == 0)) {
			free(tmp);
			hs[h].count++;
			hs[h].list = realloc(hs[h].list, hs[h].count);
			hs[h].list[hs[h].count -1] = i;
		}
		else {

			while(hs[h].sortedStr != NULL)	h = (++h) % strsSize;

			hs[h].sortedStr = tmp;
			hs[h].count = 1;
			hs[h].list = malloc(sizeof(int));
			*returnSize++;
			*(hs[h].list) = i;
		}
	}

	char ***ret = malloc(sizeof(char **) * *returnSize);
	for(int i = 0; i < strsSize; i++) {

		if(hs[i].sortedStr == NULL)
			continue;

		printf("%s: ", hs[i].sortedStr);

		for(int j = 0; j < hs[i].count; j++)
			printf("%s ", strs[hs[i].list[j]]);
		printf("\n");
	}
}

int main()
{
	int returnSize, *columnSizes;
	char *str[] = {"eat", "tea", "tan", "ate", "nat", "bat"}, ***ret = groupAnagrams(str, sizeof(str) / sizeof(str[0]), &columnSizes, &returnSize);

	dump(ret, returnSize, columnSizes);
	return 0;
}
