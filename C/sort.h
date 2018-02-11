#ifndef __SORT_H__
#define __SORT_H__
void bubbleSort(int *a, int numsSize)
{
	int ex = 1, last = numsSize - 1;

	for(int i = 0; i < numsSize - 1 && ex; i++) {
		
		ex = 0;
		for(int j = 0; j < last; j++) {
			
			if(a[j + 1] < a[j]) {

				int t = a[j + 1];
				a[j + 1] = a[j];
				a[j] = t;
				ex = j;
			}
		}
		last = ex;
	}

#if 0
	printf("[ ");
	for(int i = 0; i < numsSize; i++)
		printf("%d ", a[i]);
	printf("]\n");
#endif
}
#endif
