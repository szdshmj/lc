#include "../inc.h"

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {

	char **ret = NULL;

	*returnSize = 0;	
	if(words == NULL || wordsSize == 0) goto out;

out:
	return ret;
}

int main()
{
	char *s[] = {"This", "is", "an", "example", "of", "text", "justification."}, **words, **f;
	int returnSize;

	words = malloc(sizeof(char *) * sizeof(s) / sizeof(s[0]));
	for(int i = 0; i < sizeof(s) / sizeof(s[0]); i++) words[i] = s[i];

	f = fullJustify(words, sizeof(s) / sizeof(s[0]), 16, &returnSize);

	for(int i = 0; i < returnSize; i++) printf("%s\n", f[i]);

	return 0;
}
