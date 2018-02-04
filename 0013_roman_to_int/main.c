int romanToInt(char* s) {

	int total = 0, fast = 0, a;

	if(s == NULL)
		return NULL;

	while(s[0] != '\0' && fast == 0) {

		a = 0;
		switch(s[0]) {
			case('I'):
				a = 1;
				if(s[1] != '\0') {

					if(s[1] == 'V') {
						a = 4;
						s++;
					}
					else if(s[1] == 'X') {
						a = 9;
						s++;
					}
					else if(s[1] == 'I') {
						a += 1;
						s++;
					}
				}
				break;

			case('V'):
				a = 5;
				break;

			case('X'):
				a = 10;
				if(s[1] != '\0') {

					if(s[1] == 'L') {
						a = 40;
						s++;
					}
					else if(s[1] =='C') {
						a = 90;
						s++;
					}
					else if(s[1] == 'X') {
						a+= 10;
						s++;
					}
				}
				break;

			case('L'):
				a = 50;
				break;

			case('C'):
				a = 100;
				if(s[1] != '\0') {
					if(s[1] == 'D') {
						a = 400;
						s++;
					}
					else if(s[1] == 'M') {
						a = 900;
						s++;
					}
					else if(s[1] == 'C') {
						a += 100;
						s++;
					}
				}
				break;

			case('D'):
				a= 500;
				break;

			case('M'):
				a = 1000;
				break;

			default:
				fast = 1;
				break;
		}

		total += a;
		s++;
	}

	return total;
}
