#include "../inc.h"

int rang(char *s, int start, int end)
{
	for(int i = start; i < end; i++) {
		if(s[end] == s[i])
			return 1;
	}
	return 0;
}

int lengthOfLongestSubstring(char* s) {

    int i, j, len;//, c;
    int max = 0, diff;// m[64][2] = {0, }, mi;

    if(s == NULL)
        return 0;

    if(s[1] == '\0')
        return 1;

    len = strlen(s);
    for(i = 0; i < len; i++) {

        /*if(s[i] >= 'a' && s[i] <= 'z')
            c = s[i] - 'a';
        if(s[i] >= 'A' && s[i] <= 'Z')
            c = s[i] - 'a' + 26;*/
        j = i + 1;
        while(rang(s, i, j) == 0 && j < len) j++;

        diff = j - i;
        //printf("diff %d %d\n", c, diff);
        //if(diff > m[c][1]) {
          //  m[c][0] = i;
         //   m[c][1] = diff;
       // }
        if(diff > max)
            max = diff;
    }

    /*for(int i = 0; i < 64; i++) {
        if(m[i][1] > max) {
            max = m[i][1];
            mi = i;
        }
    }*/

    //for(int i = m[mi][0]; i < max + m[mi][0]; i++)
       // printf("%c", s[i]);
    return max;
}

int main()
{
	int i = lengthOfLongestSubstring("dvdf");
	printf("  %d\n", i);
	return 0;
}
