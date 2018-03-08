#include "../inc.h"

bool isMatch(char* s, char* p) {

	char *ss = NULL, *pp = NULL;

	while(s[0] != '\0') {

		if(s[0] == p[0] || p[0] == '?')
			s++, p++;
		else if(p[0] == '*')
			ss = s, pp = p++;
		else if(pp != NULL)
			s = ++ss, p = pp + 1;
		else
			return false;
	}

	while(p[0] == '*')	p++;

	return p[0] == '\0';
}

int main()
{
	return 0;
}
