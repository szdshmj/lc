#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(char *s, char *w, int wlen)
{
	for(int i = 0; i < wlen; i++) {
		if(s[i] != w[i])
			return -1;
	}

	return 0;
}

int compares(char* s, int slen, int wlen, char** words, int wordsSize, int *flag)
{
	int match = 0, find = 1;
	
	for(int i = 0; i < wordsSize; i++) flag[i] = 0;

	for(int i = 0; i < slen && find; i += wlen) {
		
		find = 0;
		for(int j = 0; j < wordsSize; j++) {

			if(flag[j] != 0)
				continue;

			if (compare(s + i, words[j], wlen) == 0) {
				flag[j] = 1;
				find = 1;
				break;
			}
		}
	}

	for(int i = 0; i < wordsSize; i++) {
		if(flag[i] == 0) {
			match = -1;
			break;
		}
	}

	return match;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {

	int slen, wlen, tlen, *pos = NULL, *flag;

	if(s == NULL || words == NULL || wordsSize < 1){
		*returnSize = 0;
		return NULL;
	}

	*returnSize = 0;
	slen = strlen(s);
	wlen = strlen(words[0]);
	tlen = wlen * wordsSize;
	flag = calloc(sizeof(int), wordsSize);

	for(int i = 0; i + tlen <= slen; i++) {
		
		if(compares(s + i, tlen, wlen, words, wordsSize, flag) == 0) {
			if(!pos)
				pos = malloc(sizeof(int) * 32);
			pos[(*returnSize)++] = i;
		}
	}
	free(flag);

	return pos;
}

int main()
{
	//char *s = "barfoothefoobarman";
	//char *words[] = {"foo", "bar"};

	char *s = "pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmyxgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoadfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjycttprkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwajrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhducesctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtraxrlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabejifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtqkscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyrdtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkpuuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjhzadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrowzljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrdhvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefgvimwbxcbzvaibspdjnrpqtyeilkcspknyylbwndvkffmzuriilxagyerjptbgeqgebiaqnvdubrtxibhvakcyotkfonmseszhczapxdlauexehhaireihxsplgdgmxfvaevrbadbwjbdrkfbbjjkgcztkcbwagtcnrtqryuqixtzhaakjlurnumzyovawrcjiwabuwretmdamfkxrgqgcdgbrdbnugzecbgyxxdqmisaqcyjkqrntxqmdrczxbebemcblftxplafnyoxqimkhcykwamvdsxjezkpgdpvopddptdfbprjustquhlazkjfluxrzopqdstulybnqvyknrchbphcarknnhhovweaqawdyxsqsqahkepluypwrzjegqtdoxfgzdkydeoxvrfhxusrujnmjzqrrlxglcmkiykldbiasnhrjbjekystzilrwkzhontwmehrfsrzfaqrbbxncphbzuuxeteshyrveamjsfiaharkcqxefghgceeixkdgkuboupxnwhnfigpkwnqdvzlydpidcljmflbccarbiegsmweklwngvygbqpescpeichmfidgsjmkvkofvkuehsmkkbocgejoiqcnafvuokelwuqsgkyoekaroptuvekfvmtxtqshcwsztkrzwrpabqrrhnlerxjojemcxel";
	char *words[] = {"dhvf","sind","ffsl","yekr","zwzq","kpeo","cila","tfty","modg","ztjg","ybty","heqg","cpwo","gdcj","lnle","sefg","vimw","bxcb"};

	//char *s = "wordgoodgoodgoodbestword";
	//char *words[] = {"word","good","best","good"};
	int returnSize = 0;

	int *n = findSubstring(s, words, sizeof(words) / sizeof(words[0]), &returnSize);

	for(int i = 0; i < returnSize; i++) {
		printf("%d\n", n[i]);
	}

	return 0;
}
