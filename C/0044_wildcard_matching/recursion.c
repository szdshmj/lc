#include "../inc.h"

bool isMatch(char* s, char* p) {

	if(s[0] == '\0') {

		for(int i = 0; p[i] != '\0'; i++) {
			if(p[i] != '*')
				return false;
		}
		return true;
	}

	if((p[0] != '?' && p[0] != '*'))
		return (p[0] == s[0]) ? isMatch(s + 1, p + 1) : false;
 	else if (p[0] == '?')
		return isMatch(s + 1, p + 1);
	else if(p[0] == '*') {

		int len = strlen(s);	
		while(p[1] == '*')
			p++;

		for(int i = 0; i <= len; i++) {

			if(isMatch(s + i, p + 1) == true) {
				return true;
			}
		}
	}
	return false;
}

int main()
{
	char *test[][2] = {
	
		/*{(char *)"aa",	(char *)"a"},
		{(char *)"aa",	(char *)"aa"},
		{(char *)"aaa", (char *)"aa"},
		{(char *)"aa",	(char *)"*"},
		{(char *)"aa",	(char *)"a*"},
		{(char *)"aa",	(char *)"?*"},
		{(char *)"aab",	(char *)"c*a*b"},
		{(char *)"abefcdgiescdfimde",(char *)"ab*cd?i*de"},
		{(char *)"zacabz",	(char *)"*a?b*"},
		{(char *)"",	(char *)"*"},*/
		{(char *)"aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba",	(char *)"a*****b"},
		{NULL,					NULL}
	};
	bool result[] = {/*false, true, false, true, true, true, false, true, false, true,*/false};

	for(int i = 0; test[i][0] != NULL; i++) {
		if(isMatch(test[i][0], test[i][1]) != result[i]) {
			printf("match %s %s failed, should %s\n", test[i][0], test[i][1], result[i] == true ? "true" : "false");
			return -1;
		}
	}

	printf("all test passed\n");
	return 0;
}
