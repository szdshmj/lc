#include "../inc.h"

char* multiply(char* num1, char* num2) {

	int a, i, j, shift = 0, t1 = strlen(num1), t2 = strlen(num2);
	char *result = calloc(1, t1 + t2 + 1);

	for(i = 0; i < t2; i++) {

		a = num2[t2 - i - 1] - '0';
		shift = 0;
		for(j = 0; j < t1; j++) {

			result[i + j] += (a * (num1[t1 - 1 - j] - '0') + shift);
			if(result[i + j] >= 10) {

				shift = result[i + j] / 10;
				result[i + j] %= 10;
			}
			else if(shift != 0)
				shift = 0;
		}
		if(shift) result[i + j] = shift;
	}

	for(j = t1 + t2 - 1, i = 0; j > 0 && result[j] == 0; j--);
	result[j + 1] = '\0';

	while(i < j) {

		char t = result[i] + '0';
		result[i] = result[j] + '0';
		result[j] = t;
		i++;j--;
	}
	if(i == j) result[i] += '0';

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
	char *s11[] = {"156955557690951899023516531972207095742403628909031", "8406815759751608344580781082398348"};

	/*printf("%s*%s = %s\n", s1[0], s1[1], multiply(s1[0], s1[1]));
	printf("%s*%s = %s\n", s2[0], s2[1], multiply(s2[0], s2[1]));
	printf("%s*%s = %s\n", s3[0], s3[1], multiply(s3[0], s3[1]));
	printf("%s*%s = %s\n", s4[0], s4[1], multiply(s4[0], s4[1]));
	printf("%s*%s = %s\n", s5[0], s5[1], multiply(s5[0], s5[1]));
	printf("%s*%s = %s\n", s6[0], s6[1], multiply(s6[0], s6[1]));
	printf("%s*%s = %s\n", s7[0], s7[1], multiply(s7[0], s7[1]));
	printf("%s*%s = %s\n", s8[0], s8[1], multiply(s8[0], s8[1]));
	printf("%s*%s = %s\n", s9[0], s9[1], multiply(s9[0], s9[1]));
	printf("%s*%s = %s\n", s10[0], s10[1], multiply(s10[0], s10[1]));*/
	printf("%s*%s = %s\n", s11[0], s11[1], multiply(s11[0], s11[1]));

	return 0;
}
