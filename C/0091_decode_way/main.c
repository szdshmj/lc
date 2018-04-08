#include "../inc.h"

int numDecodings(char* s) {

	int len = strlen(s);

	if(len == 0) return 0;

	int dp[len + 1];
	memset(dp, 0, sizeof(int) * (len + 1));

	dp[0] = 1;
	dp[1] = s[0] == '0' ? 0 : 1;

	for(int i = 2; i < len + 1; i++) {
		
		if(s[i - 1] != '0')
			dp[i] = dp[i - 1];

		int n = (s[i - 2] - '0') * 10 + s[i - 1] - '0';

		if(n >= 10 && n <= 26)
			dp[i] += dp[i - 2];
	}

	return dp[len];
}
