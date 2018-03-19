#include "../inc.h"

void fill_space(char *src, int len)
{
	for(int i = 0; i < len; i++) src[i] = ' ';
}

char *fill_line(char** words, int wordsSize, int maxWidth, int start, int wordCount, int pureCount)
{
	char *out = (char *)calloc(sizeof(char), (maxWidth + 1));

	if(wordCount == 1 || start + wordCount == wordsSize) {
		
		for(int i = 0; i < wordCount; i++) {
			strcat(out, words[start + i]);
			if(i + 1 < wordCount)
				fill_space(out + strlen(out), 1);
		}
		fill_space(out + strlen(out), maxWidth - strlen(out));
	}
	else {

		int totalSpace = maxWidth - pureCount;
		int ev = totalSpace / (wordCount - 1);
		int extra = totalSpace % (wordCount - 1);

		for(int i = 0; i < wordCount - 1; i++) {
			
			strcat(out, words[start + i]);
			if(extra > 0) {
				fill_space(out + strlen(out), 1);
				extra--;
			}

			fill_space(out + strlen(out), ev);
		}

		strcat(out, words[start + wordCount -1]);
	}

	return out;
}

int eat(char** words, int wordsSize, int maxWidth, int start, int *pureCount)
{
	int lenCount = 0, wordCount = 0, tmp = 0, wlen, i;	
	
	*pureCount = 0;
	wlen = strlen(words[start]);

	if(wlen <= maxWidth) {
	
		tmp += wlen;
		lenCount = tmp;
		*pureCount += tmp;
		wordCount++;
	}

	for(i = start + 1; i < wordsSize && tmp < maxWidth; i++) {

		wlen = strlen(words[i]);
		tmp += (1 + wlen);
		if(lenCount + 1 + wlen <= maxWidth) {
						
			lenCount = tmp;	
			*pureCount += wlen;
			wordCount++;
		}
	}

	return wordCount;
}

char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {

	char **ret = NULL;
	int pureCount;

	*returnSize = 0;	
	ret = (char **)malloc(sizeof(char *) * 100);
	if(words == NULL || wordsSize == 0) goto out;

	for(int i = 0, skip; i < wordsSize; i += skip) {

		skip = eat(words, wordsSize, maxWidth, i, &pureCount);
		ret[(*returnSize)++] = fill_line(words, wordsSize, maxWidth, i, skip, pureCount);
	}

out:
	return ret;
}

int main()
{
	//char *s[] = {"This", "is", "an", "example", "of", "text", "justification."}, sl = 16, **words, **f;
	//char *s[] = {"Listen","to","many,","speak","to","a","few."}, sl = 6, **words, **f;
	//char *s[] = {"What","must","be","shall","be."}, sl = 12, **words, **f;
	char *s[] = {"Imagination","is","more","important","than","knowledge."}, sl = 14, **words, **f;
	int returnSize;

	words = (char **)malloc(sizeof(char *) * sizeof(s) / sizeof(s[0]));
	for(unsigned int i = 0; i < sizeof(s) / sizeof(s[0]); i++) words[i] = s[i];

	f = fullJustify(words, sizeof(s) / sizeof(s[0]), sl, &returnSize);

	for(int i = 0; i < returnSize; i++) printf("%s\n", f[i]);

	return 0;
}
