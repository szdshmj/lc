#include "../inc.h"

int minDistance(char* word1, char* word2) {

	int len1 = strlen(word1), len2 = strlen(word2), **dp, min;

	dp = malloc(sizeof(int *) * (len1 + 1));

	for(int i = 0; i < len1 + 1; i++) {
		dp[i]= malloc(sizeof(int), (len2 + 1));
		dp[i][0] = i;
	}

	//for(int i = 0; i < len1 + 1; i++)
	//dp[i][0] = i;

	for(int i = 0; i < len2 + 1; i++)
		dp[0][i] = i;

	for(int i = 1; i < len1 + 1; i++) {
		for(int j = 1; j < len2 + 1; j++) {
			min = ((dp[i - 1][j] < dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1]) + 1;
			dp[i][j] = (word1[i - 1] == word2[j - 1]) ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1;
			if(min < dp[i][j]) dp[i][j] = min;
		}
	}

	min = dp[len1][len2];
	free(dp);
	return min;
}

int main(int argc, char *argv[])
{
	printf("%d\n", minDistance(argv[1], argv[2]));
	return 0;
}
