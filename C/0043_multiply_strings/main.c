#include "../inc.h"

int simply(int *tmp, char *n1, int t1, int n2)
{
	int i, m, shift = 0;

	for(i = 0; i < t1; i++) {

		m = (n1[t1 - 1 - i] - '0') * n2 + shift;

		if(m >= 10) {
			shift = m / 10;
			m = m % 10;
		}
		else if(shift != 0)
			shift = 0;

		tmp[i] = m;
	}

	if(shift > 0)
		tmp[i++] = shift;

#if 1
	for(int j = 0; j < i; j++)
		printf("%d", tmp[j]);
	printf("\n");
#endif
	return i;
}

void add(int b, int *n, int *tmp, int tlen)
{
}

char* multiply(char* num1, char* num2) {
	
	char *result = NULL;
	int t1, t2;
	int *n, *tmp;

	if(num1 == NULL || num2 == NULL)
		return result;
	
	t1 = strlen(num1);
	t2 = strlen(num2);
	n = calloc(sizeof(int), t1 + t2);
	tmp = calloc(sizeof(int) ,t1 + 1);

	for(int i = 0; i < t2; i++) {
	
		simply(tmp, num1, t1, num2[t2 - i - 1] - '0');
		add(i, n, tmp, t1 + 1);
	}
		
	return result;
}

int main()
{
	char *s1[] = {"12", "34"};
	char *s2[] = {"67", "89"};
	char *s3[] = {"99", "99"};
	char *s4[] = {"9999", "9999"};
	char *s5[] = {"0", "9999"};
	char *s6[] = {"9999", "0"};
	char *s7[] = {"9999", "9"};
	char *s8[] = {"123456789", "9"};
	char *s9[] = {"123456789", "987654321"};

	printf("%s*%s = %s\n", s1[0], s1[1], multiply(s1[0], s1[1]));
	printf("%s*%s = %s\n", s2[0], s2[1], multiply(s2[0], s2[1]));
	printf("%s*%s = %s\n", s3[0], s3[1], multiply(s3[0], s3[1]));
	printf("%s*%s = %s\n", s4[0], s4[1], multiply(s4[0], s4[1]));
	printf("%s*%s = %s\n", s5[0], s5[1], multiply(s5[0], s5[1]));
	printf("%s*%s = %s\n", s6[0], s6[1], multiply(s6[0], s6[1]));
	printf("%s*%s = %s\n", s7[0], s7[1], multiply(s7[0], s7[1]));
	printf("%s*%s = %s\n", s8[0], s8[1], multiply(s8[0], s8[1]));
	printf("%s*%s = %s\n", s9[0], s9[1], multiply(s9[0], s9[1]));

	return 0;
}
