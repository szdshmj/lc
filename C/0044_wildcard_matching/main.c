#include "../inc.h"

bool isMatch(char* s, char* p) {

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
		{(char *)"aab", (char *)"c*a*b"},
		{(char *)"ab",	(char *)".*c"},
		{(char *)"bccaabcacbacaccca", (char *)"b*.*baa*b*.a*bc*c"},
		{NULL,					NULL}
	};

	for(int i = 0; test[i][0] != NULL; i++)
		printf("match %d\n", isMatch(test[i][0], test[i][1]));

	return 0;
}
