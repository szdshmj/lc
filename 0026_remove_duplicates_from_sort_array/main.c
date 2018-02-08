#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeDuplicates(int* nums, int numsSize) {

	int skip, pos;

	if(nums == NULL || numsSize == 0)
		return 0;
	else if(numsSize == 1)
		return 1;
	else {
		
		for(int start = 1; start <= numsSize - 1; start ++) {
			skip = 0;
			
			pos = start;
			while(nums[pos] == nums[pos - 1] && pos <= numsSize - 1) {pos++; skip++;}
			
			if(skip > 0) {

				for(int i = pos; i <= numsSize -1; i++) {
					nums[start + i - pos] = nums[i];
				}
				numsSize -= skip;
			}
		}
		return numsSize;
	}
}

void printfArray(int A[], int n) {
    printf("{ ");
    for (int i=0; i<n; i++){
        printf("%d ", A[i]);
    }
    printf("}\n");
}

void testSuite(int a[], int n){
	printfArray(a, n);
	n = removeDuplicates(a, n);
	printfArray(a, n);
	printf("------------------\n");
}
#define TEST(a) testSuite(a, sizeof(a)/sizeof(int))

int main()
{
	int a0[] = {1, 2, 3, 4, 5};
	TEST(a0);
	int a1[] = {1, 1, 1};
	TEST(a1);
	int a2[] = {1, 2, 2};
	TEST(a2);
	int a3[] = {1, 1, 2};
	TEST(a3);
	int a4[] = {1, 1, 1, 1};
	TEST(a4);
	int a5[] = {1, 1, 1, 2};
	TEST(a5);
	int a6[] = {1, 2, 2, 2};
	TEST(a6);
	int a7[] = {1, 2, 2, 2, 3 };
	TEST(a7);
	int a8[] = {1, 2, 2, 2, 3, 3};
	TEST(a8);
	int a9[] = {1,1,1,2,2,3};
	TEST(a9);
	int a10[] = {1,1,1,2,2,2};
	TEST(a10);
	int a11[] = {1,1,1,1,3,3};
	TEST(a11);
	return 0;
}
