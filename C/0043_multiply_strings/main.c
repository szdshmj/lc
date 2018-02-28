#include "../inc.h"

char* simply(char *tmp, int tlen, char *num1, int a)
{
	int m, t, shift = 0, pos = 0;

	memset(tmp, 0, tlen);
	for(int i = strlen(num1) - 1; i >= 0 ; i--) {
		
		m = (num1[i] - '0') * a + shift;
		shift = 0;

		if(m > 9) {
			shift = m / 10;
			m = m % 10;
		}

		tmp[(tlen - 1) - pos++] = m;
	}

	if(shift) {
		tmp[(tlen - 1) - pos++] = shift;
		return tmp;
	}
	else
		return tmp + 1;
}

void add(int i, char *result, char *tmp, int tlen)
{
	int shift = 0;

	for(int j = tlen - 1; j >= 0; j--) {

		if(result[i + j] == '.')
			result[i + j] = 0;
		result[i + j] += (tmp[j] + shift);
		shift = 0;
		if(result[i + j] >= 10) {
			result[i + j] -= 10;
			shift = 1;
		}
	}

	if(shift && i > 0)
		result[i - 1]++;
}

char* multiply(char* num1, char* num2) {
	
	char *result = NULL, *tmp = NULL;
	int tlen, rlen, isZero = 1;

	if(num1 == NULL || num2 == NULL)
		return result;
		
	tlen = strlen(num1) + 1;
	rlen = strlen(num1) + strlen(num2) + 1;

	tmp = malloc(tlen);
	result = malloc(rlen);
	memset(result, '.', rlen);
	result[rlen - 1] = '\0';

	for(int i = 0 ; i < strlen(num2); i++) {
		
		char *t = simply(tmp, tlen, num1, num2[i] - '0');
		add(i, result, t, t == tmp ? tlen : tlen - 1);

		for(int j = 0; j < rlen; j++)
			if(result[j] != '.')
			printf("%d", result[j]);
			printf("\n");
	}
	free(tmp);

	for(int i = 0; i < rlen - 1; i++)
		if(result[i] == '.')
			result[i] = '\0';
		else {
			if(result[i] != 0)
				isZero = 0;
			result[i] += '0';
		}

	if(isZero == 1)
		result[1] = '\0';
	return result;
}

int main()
{
	/*char *s1[] = {"12", "34"};	
	char *s2[] = {"67", "89"};
	char *s3[] = {"99", "99"};
	char *s4[] = {"9999", "9999"};
	char *s5[] = {"0", "9999"};
	char *s6[] = {"9999", "0"};*/
	char *s7[] = {"123456789", "987654321"};

	/*printf("%s*%s = %s\n", s1[0], s1[1], multiply(s1[0], s1[1]));
	printf("%s*%s = %s\n", s2[0], s2[1], multiply(s2[0], s2[1]));
	printf("%s*%s = %s\n", s3[0], s3[1], multiply(s3[0], s3[1]));
	printf("%s*%s = %s\n", s4[0], s4[1], multiply(s4[0], s4[1]));
	printf("%s*%s = %s\n", s5[0], s5[1], multiply(s5[0], s5[1]));
	printf("%s*%s = %s\n", s6[0], s6[1], multiply(s6[0], s6[1]));
	*/printf("%s*%s = %s\n", s7[0], s7[1], multiply(s7[0], s7[1]));

	return 0;
}
