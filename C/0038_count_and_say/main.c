#include "../inc.h"

void update(char *src, char *dst)
{
	char *p = src;
	int count = 0, posd = 0;
	
	while(p[0] != '\0') {
		
		while(p[0] == p[1]) {
			count++;
			p++;
		}
		dst[posd++] = (count + 1) + '0';
		dst[posd++] = p[0];

		count = 0;
		p++;
	}
	dst[posd] = '\0';
}

char* countAndSay(int n) 
{
	char *odd, *even, *src, *dst, *p;
	int count = 0, posd = 0;

	odd = (char *)malloc(8192);
	even = (char *)malloc(8192);
	odd[0] = '1';
	odd[1] = '\0';
	even[0] = '1';
	even[1] = '1';
	even[2] = '\0';

	if(n == 1)
		return odd;

	if(n == 2)
		return even;

	for(int i = 3; i <= n; i++) {
		if(i % 2 == 1) {
			src = even;
			dst = odd;
		}
		else {
			src = odd;
			dst = even;
		}

		p = src;
		count = 0;
		posd = 0;

		while(p[0] != '\0') {

			while(p[0] == p[1]) {
				count++;
				p++;
			}
			dst[posd++] = (count + 1) + '0';
			dst[posd++] = p[0];

			count = 0;
			p++;
		}
		dst[posd] = '\0';
	}
	return dst;
}

int main(int argc, char *argv[])
{
	char *s = countAndSay(atoi(argv[1]));
	printf("%s\n", s);
	return 0;
}
