#include "../inc.h"

void print(char *path, int a)
{
	for(int i = 0; i < a; i++) printf("%c", path[i]);

	printf("\n");
}

int check(char *path, int a)
{
	if(a == 1 && (path[0] == '.'))
		return -1; 
	else if(a == 2 && path[0] == '.' && path[1] == '.')
		return -2;
	else
		return 0;
}

char* simplifyPath(char* path) {
	
	char *str = NULL, *oo = path;
	int len, ia = 0, ib = 0, p = 0;

	if(path == NULL) return NULL;

	len = strlen(path);
	str = (char *)calloc(len + 1, 1);

	while(*path == '/' || *path == '.') {
		if(*path == '/' && *(path + 1) != '\0')
			oo = path;
		path++;
	}
	if(*path == '\0') {

		strcpy(str, oo);

		if((strlen(str) > 1) && (str[strlen(str) -1] == '/'))
			str[strlen(str) -1] = '\0';

		if(str[1] == '.' && str[2] == '\0') 
			str[1] = '\0';
		else {
			if(str[1] == '.' && str[2] == '.' && str[3] == '\0') 
				str[1] = '\0';
		}
		return str;
	}

	str[p++] = '/';
	if(*(path - 1) != '/') {
		while(*(path - 1) != '/')
			path--;

		while(*(path + 1) == '.') {
			str[p++] = *path;
			path++;
		}
	}

	while(*path != '\0') {
		ia = 0;
		if(*path == '/'){ 
			if(str[p - 1] != '/') {
				str[p++] = '/';
				str[p]= '\0';
			}
			path++;
			if(*path == '\0')
				break;
		}

		while(path[ia] != '/' && path[ia] != '\0') ia++;
		if(ia == 0) {path++; continue;}

		int t = check(path, ia);

		switch(t) {
			case(-2) :
				p--;
				while(p > 0 && str[p - 1] != '/') p--;
				if(p != 0)
					str[p] = '\0';
				break;
			case(-1):
				break;
			default:
				for(int i = 0; i < ia; i++)
					str[p++] = path[i];
				str[p] = '\0';
		}

		path += ia;
	}

	len = strlen(str);
	if(len > 1 && str[len - 1] == '/') str[len - 1] = '\0';

	return str;
}

int main(int argc, char *argv[])
{
	char *a = "/home/";
	char *b = "/a/./b/../../c/";
	char *c = "/home/./ff/../../abc";
	char *d = "/../vLHjV/..///kJIUFFGIKiRx/./RQcjWKMeRTqAiXIxXCoB/.///..///..///.///qNiqHnXgtuOnV///..///zCuLznDGGVKoAHf/./../WsqYCENSj/./../../XeMlhPSwsNSdHAoi/.///J/./bdBdFNDaDf/rEGottNudXxldW/UHhQvv/..///brRIjSXsmvoKTiRVLe/nUa/LyGkYwJogagzxK/EtOSD/iSeCvWa///xsYeyInWUHCmPxYMdzO/../../TaYzVAUtdROxhZTyoBf/ssbyb/tXqmHsoPcBfNTseCCp/dEuFgdxGseYXeN///././//../DdNJ/pmbCjUQAc/Ge/RxqOBnntLS/..///../../vQcCwibUoqojHNpGf/../pijieuc/hE///DbJSQjdNNtHoOdfL///./.././HIuy/KiBLUj/CWAG/mwXPGfpAuyYWJATPL/xb/..///xrM///azpgxlfpOBEkwgEFbRBF/cLxVbwOzmpZmz/sI/gmSaqSXyit/BhPqYfM/gLZDXrtVMz/../COTozRwdivH///DAKgkm/KudvcwrJmkRcMl///WDVVsbY/bkyLXJNraxFBUTNU///MiJSxkDQKKW/BJocXq/oTXWUpFHbfVwtuQ/ESwIqKltMoibnycx/aFjoRWJZRsdyODHrL/./zJgBBZhndtnvjxmoXxJe///DAt/RpNWmaHvANFm/////sNTTPyfUGMRB/Kj/TmqywKmvXcP/midTUVh/oOAznoA///./TbqOnFpZGIPGuTLc/zwrtDqU/./CgbGSpQF///./////TqDGrzkQmwHtNjv/hbuzndcNvbYXcAYVfO/../B/qauBVbisxDEUvHO///./N/./IAB/xRQwqBvyHa/LJuvnfFZNQgY/jbJuS/jDidnyfyGibNNvgAO///./////VwXEWsEN/./hnHiZUUYDfTevV/cvFHcMJblQqmzwd///../ErPJmsxjV/../.././//RWKfqnjK/./ULNpthBQIjVgYCyxr///////RhtyjrvEkFEU/././UZGI///vdEnJmZg/./zaJfYjVLmWSvC/Iql/P/pdAwVwyAIbcmfX///rsRLlhDVtvinVcI/../JNN/GjtSgRDfCBxHo/FxJVzLidpMAwSqjLb/../fqMa///ZTNsULKAtGxGZNabDsAu/////HqwDCBISxIhu/ZFyIvFbawNemimFCuw/dBJBLoNBZSaCTdUjRab/../J/B/./OtrrVeYnxCYiVZuhcI///rWQWcgtXlOByJNOlI/./.././//./vagPbbLhABYCppbqMhjM//";
	char *e = "/..hidden";
	char *f = "/home//foo/";
	char *g = "/home/of/foo/../../bar/../../is/./here/.";

	//printf("%s\n", simplifyPath(a));
	//printf("%s\n", simplifyPath(b));
	//printf("%s\n", simplifyPath(c));
	//printf("%s\n", simplifyPath(d));
	//printf("%s\n", simplifyPath(e));
	//printf("%s\n", simplifyPath(f));
	printf("%s\n", simplifyPath(g));

	//printf("%s\n", simplifyPath(argv[1]));

	return 0;
}
