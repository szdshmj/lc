#include "../inc.h"

int lengthOfLastWord(char* s) {
	
	int len, c = 0;

	if(s == NULL || s[0] == '\0')
		return 0;

	len = strlen(s) - 1;	

	while(len >= 0 && (s[len] == ' ')) len--;

	while(len >= 0) {

		if((s[len] >= 'a' && s[len] <= 'z') || (s[len] >= 'A' && s[len] <= 'Z')) {
			len--;
			c++;
		}
		else
			break;
	}

	return c;	
}

int main() {

	char *s = "   hello ";

	printf("%d\n", lengthOfLastWord(s));

	return 0;
}
