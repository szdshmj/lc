char roman[4][2] = {{'I', 'V'},{'X','L'}, {'C','D'}, {'M', '\0'}};

char* dump(char *str, int n, int pos) {

	if(n < 4) {
		for(int i = 0; i < n; i++)
			*str++ = roman[pos][0];
	}
	else if(n < 5) {
		*str++ = roman[pos][0];
		*str++ = roman[pos][1];
	}
	else if(n < 9) {
		*str++ = roman[pos][1];
		for(int i = 0; i < n - 5; i++)
			*str++ = roman[pos][0];

	}
	else {
		*str++ = roman[pos][0];
		*str++ = roman[pos + 1][0];
	}
	return str;
}

char* intToRoman(int num) {
	int i = 0, j = 0;
	char *str = NULL, *p;

	if(num < 1 || num > 3999)
		return 0;

	str = (char *)calloc(16, 1);
	p = str;

	for(i = 1000; i != 0; i /= 10)
		p = dump(p, num / i % 10, 3 - j++); 

	return str;
}
