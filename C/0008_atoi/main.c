#include "../inc.h"
#include <limits.h>

const int limit = INT_MAX / 10; 
const int limit_p = INT_MAX % 10; 
const int limit_n = 0 - INT_MIN % 10; 
 
int myAtoi(char* str) {

	int op = 1, total = 0;

	if(str == NULL)
		return 0;

	while(str[0] == ' ')
		str++;

	if(str[0] == '-') {

		op = -1;
		str++;
	}
	else if(str[0] == '+')
		str++;

	while(str[0] != '\0') {

		int n = str[0] - '0';

		if((n > 9) || (n < 0)) 
			break;

		if(total > limit)
			return (op == 1) ? INT_MAX : INT_MIN;

		if(total == limit) {
			if((op == 1) && (n > limit_p))
				return INT_MAX;
			else if((op == -1) && (n > limit_n))
				return INT_MIN;
		}

		total *= 10;
		total += n;
		str++;
	}

	if(op == -1 && total != 0)
		return -total;
	else
		return total;
}

int main(int argc, char *argv[])
{
	printf("%d\n", myAtoi(argv[1]));
}
