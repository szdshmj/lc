#include "../inc.h"
#include <limits.h>


char* minWindow(char* s, char* t) {

	char *result;
	int count = 0, dt = 0, start = -1, size = INT_MAX, tmp, m[256] = {0, }, n[256] = {0, };

	for (int i = 0; t[i] != '\0'; i++) {
		m[t[i]]++;
		dt++;
	}

	for(int i = 0, begin = 0; s[i] != '\0'; i++) {

		if(m[s[i]] == 0) continue;
		if(++n[s[i]] <= m[s[i]]) count++;
		if(count < dt) continue;

		while(m[s[begin]] == 0 || (n[s[begin]] > m[s[begin]])) {

			if(n[s[begin]] > m[s[begin]]) n[s[begin]]--;

			begin++;
		}

		tmp = i - begin + 1;

		if(tmp < size) {
			size = tmp;
			start = begin;
		}
	}

	if(size == INT_MAX) size = 0;

	result = malloc(size + 1);

	if(size != 0) memcpy(result, s + start, size);

	result[size] = '\0';

	return result;
}

int main(int argc, char *argv[])
{
	char *s = "ADOBECODEBANC", *t = "ABC";

	printf("%s\n", minWindow(argv[1], argv[2]));
} 
