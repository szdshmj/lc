#include "../inc.h"

bool isMatch(char* s, char* p) {

    if(p[0] == '\0')
        return s[0] == '\0';
    else if(p[1] != '*') 
        return (s[0] != '\0' && (s[0] == p[0] || p[0] == '.')) ? isMatch(s + 1, p + 1) : false;
    
    //p[1] == '*'
    while((p[0] == s[0]) || (p[0] == '.' && s[0]!='\0')) {

        if(isMatch(s++, p + 2) == true)
            return true;
    }

    return isMatch(s, p + 2);
}

int main()
{
	char *test[][2] = {
		{(char *)"aa",	(char *)"a"},
		{(char *)"aa",	(char *)"aa"},
		{(char *)"aaa",	(char *)"aa"},
		{(char *)"aa",	(char *)"a*"},
		{(char *)"aa",	(char *)".*"},
		{(char *)"ab",	(char *)".*"},
		{(char *)"aab",	(char *)"c*a*b"},
		{(char *)"ab",  (char *)".*c"},
		{(char *)"bccaabcacbacaccca", (char *)"b*.*baa*b*.a*bc*c"},
		{NULL,			NULL}
	};

	for(int i = 0; test[i][0] != NULL; i++)
		printf("match %d\n", isMatch(test[i][0], test[i][1]));

	return 0;
}
