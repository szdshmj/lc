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
	
	char ***ret = NULL;
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

		printf("tmp %s, h %d, %s\n", tmp, h, hs[h].sortedStr);

		while(hs[h].sortedStr != NULL && strcmp(hs[h].sortedStr, tmp) != 0)	h = (++h) % strsSize;

		if((hs[h].sortedStr != NULL) && (strcmp(hs[h].sortedStr, tmp) == 0)) {
			free(tmp);
			hs[h].count++;
			hs[h].list = realloc(hs[h].list, hs[h].count);
			hs[h].list[hs[h].count -1] = i;
		}
		else {

			hs[h].sortedStr = tmp;
			hs[h].count = 1;
			hs[h].list = malloc(sizeof(int));
			(*returnSize)++;
			*(hs[h].list) = i;
		}
	}

	ret = malloc(sizeof(char **) * *returnSize);
	*columnSizes = malloc(sizeof(int) * *returnSize);

	for(int i = 0, acc = -1; i < strsSize; i++) {

		if(hs[i].sortedStr == NULL)
			continue;

		(*columnSizes)[++acc] = hs[i].count;
		ret[acc] = malloc(sizeof(char *) * hs[i].count);

		for(int j = 0; j < hs[i].count; j++) {
			ret[acc][j] = strdup(strs[hs[i].list[j]]);
		}
	}
	return ret;
}

int main()
{
	int returnSize, *columnSizes;
	//char ***ret, *str[] = {"eat", "tea", "tan", "ate", "nat", "bat"}; 
	char ***ret, *str[] = {"sat","lea","arm","sin","the","nod","guy","ins","rod"}; 
	
	ret = groupAnagrams(str, sizeof(str) / sizeof(str[0]), &columnSizes, &returnSize);

	dump(ret, returnSize, columnSizes);
	return 0;
}
