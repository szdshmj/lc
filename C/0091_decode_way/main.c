#include "../inc.h"

int numDecodings(char* s) {

	int n = 1;

	if(!s) return n;
	
	while(*s) {
		if(*s == '1') {
			if(s[1] != '\0') {
				n *= 2;
			}
		}
		else if(*s == '2') {

			if(s[1] > '0' && s[1] < '7') {
				n *= 2;
			}
		}
		s++;
	}
	return n;
}

int main(int argc, char **argv)
{
	printf("%d\n", numDecodings(argv[1]));
}
