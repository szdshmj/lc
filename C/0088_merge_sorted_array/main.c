#include "../inc.h"

void merge(int* nums1, int m, int* nums2, int n) {

	int *tmp = malloc(sizeof(int) * m), i = 0, j = 0, k = 0;

	memcpy(tmp, nums1, sizeof(int) *m);

	while(i < m && j < n) {

		if(tmp[i] < nums2[j]) {
			nums1[k++] = tmp[i++];
		}
		else if(tmp[i] > nums2[j]) {
			nums1[k++] = nums2[j++];
		}
		else {
			nums1[k++] =tmp[i++];
			nums1[k++] = nums2[j++];
		} 
	}

	while(i < m)
		nums1[k++] = tmp[i++];

	while(j < n)
		nums1[k++] = nums2[j++];

	free(tmp);
}
