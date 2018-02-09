#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {

	int len, pos = 0;
	char *c;

	if(s == NULL || numRows == 1 || (len = strlen(s)) <= numRows)
		return s;

	c = calloc(1, len + 1);
	for(int i = 0; i < numRows; i++) {

		for(int j = i; j < len; j += (2 * (numRows -1))) {
			if(j < len) {

				c[pos++] = s[j];
				//printf("%c", s[j]);
			}

			if(i != 0 && i != numRows - 1) {

				int z = j + (2 * (numRows -1)) - 2 * i;
				if(z < len) {
					//printf("%c", s[z]); 
					c[pos++] = s[z];
				}
			}
		}
	}

	//printf("\n");
	return c;
}

int main(int argc, char *argv[])
{
	char *s = convert(argv[1], atoi(argv[2]));

	//char *s = convert("clffrkeecbpdipufhidjcxjhrnxcxmjcxohqanxdrmgzebhnlmwpmhwdvthsfqueeexgrujigskmvrzgfwvrftwa", 70);
	printf("%s\n", s);	
	free(s);
}
