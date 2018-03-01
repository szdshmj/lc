#include "../inc.h"

void newAdd(int b, int *n, char *n1, int t1, int a)
{
	int i, shift = 0;

	for(i = 0; i < t1; i++) {
		n[b + i] += (a * (n1[t1 - 1 - i] - '0') + shift);
		if(n[b + i] >= 10) {
			shift = n[b + i] / 10;
			n[b + i] = n[b + i] % 10;
		}
		else if(shift != 0)
			shift = 0;
	}
	if(shift)
		n[b + i] = shift;
}

char* multiply(char* num1, char* num2) {

	char *result = NULL;
	int a, t1, t2, i, j, shift = 0, *n;

	if(num1 == NULL || num2 == NULL) return result;

	t1 = strlen(num1);
	t2 = strlen(num2);
	n = calloc(sizeof(int), t1 + t2);

	for(i = 0; i < t2; i++) {

		a = num2[t2 - i - 1] - '0';
		shift = 0;
		for(j = 0; j < t1; j++) {
			n[i + j] += (a * (num1[t1 - 1 - j] - '0') + shift);
			if(n[i + j] >= 10) {
				shift = n[i + j] / 10;
				n[i + j] = n[i + j] % 10;
			}
			else if(shift != 0)
				shift = 0;
		}
		if(shift)
			n[i + j] = shift;
	}

	for(i = t1 + t2 - 1; i > 0 && n[i] == 0; i--);
	result = malloc(i + 2); 
	for(int j = i; j > 0; j--)result[i - j] = n[j] + '0';
	result[i] = '0' + n[0];
	result[i + 1] = '\0';
	free(n);

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
	char *s10[] = {"237", "284"};

	printf("%s*%s = %s\n", s1[0], s1[1], multiply(s1[0], s1[1]));
	printf("%s*%s = %s\n", s2[0], s2[1], multiply(s2[0], s2[1]));
	printf("%s*%s = %s\n", s3[0], s3[1], multiply(s3[0], s3[1]));
	printf("%s*%s = %s\n", s4[0], s4[1], multiply(s4[0], s4[1]));
	printf("%s*%s = %s\n", s5[0], s5[1], multiply(s5[0], s5[1]));
	printf("%s*%s = %s\n", s6[0], s6[1], multiply(s6[0], s6[1]));
	printf("%s*%s = %s\n", s7[0], s7[1], multiply(s7[0], s7[1]));
	printf("%s*%s = %s\n", s8[0], s8[1], multiply(s8[0], s8[1]));
	printf("%s*%s = %s\n", s9[0], s9[1], multiply(s9[0], s9[1]));
	printf("%s*%s = %s\n", s10[0], s10[1], multiply(s10[0], s10[1]));

	return 0;
}
