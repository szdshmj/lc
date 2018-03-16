#include "../inc.h"

struct Ncase {
	char *s;
	int result;
};

bool isValidC(char s, int *has_n, int *has_dot, int *has_e)
{
	if(s >= '0' && s <= '9') {
		if(*has_n == -1)
			*has_n = s - '0';
		return true;	
	}
	
	if(*has_dot == 0 && s == '.' && *has_e == 0) {
		*has_dot = 1;
		return true;
	}
		
	if(*has_e == 0 && s == 'e') {

		if(*has_n == -1)
			return false;
		*has_e = 1;

		return true;
	}

	return false;
}

bool isNumber(char* s) {

	int i = 0, has_n = -1, has_e = 0, has_dot = 0, l;

	while(s[0] == ' ')	s++;

	if(s[0] == '-') s++;
	else if(s[0] == '+') s++;

	l = strlen(s) - 1;

	if(l < 0) return false;
	if(s[0] == 'e') return false;

	while(l >= 0 && s[l] == ' ') l--;

	while(i <= l && s[i] != '\0') {

		if(isValidC(s[i++], &has_n, &has_dot, &has_e) == false)
			return false;

		if(s[i - 1] == 'e') {
			if(s[i] == '+' || s[i] == '-')
				i++;
			if(s[i] == '\0')return false;
		}
	}

	if((s[l] == '.') && (has_n < 0)) return false;
	if((s[l] == 'e')) return false;

	return true;
}

int main()
{
	struct Ncase tcase[] = {
		{"e9", false},
		{" ", false},
		{"3.", true},
		{"e", false},
		{"0e", false},
		{"0", true},
		{" 0.1 ", true},
		{"abc", false},
		{"1 a", false},
		{"2e10", true},
		{"0e1", true},
		{"1e.", false},
		{".e1", false},
		{"1.", true},
		{"-1.", true},
		{"46.e3", true},
		{".2e81", true},
		{" 005047e+6", true},
		{"4e+", false},
	};

	for(int i = 0; i < sizeof(tcase) / sizeof(tcase[0]); i++) {

		if(tcase[i].result != isNumber(tcase[i].s)) {
			printf("test [%d] '%s' failed\n", i, tcase[i].s);
			return -1;
		}
	}

	printf("all passed\n");
	return 0;
}
