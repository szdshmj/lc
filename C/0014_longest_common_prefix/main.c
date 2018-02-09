char* longestCommonPrefix(char** strs, int strsSize) {

	int pos = 0;
	bool loop = true;

	if(strs == NULL || strsSize < 1)
		return "";

	if(strsSize == 1)
		return strs[0];

	for(int i = 0; i < strsSize; i++)
		if(strs[i] == NULL)
			return "";

	while(strs[0][pos] != '\0') {

		for(int i = 1; i < strsSize; i++) {
			if(strs[i][pos] != strs[0][pos] ) {

				loop = false;
				break;
			} 
		}
		if(loop == false)
			break;
		pos++;
	}

	if(pos == 0)
		return "";

	strs[0][pos] = '\0';
	return strs[0];
}
