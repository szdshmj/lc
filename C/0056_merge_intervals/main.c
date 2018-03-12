#include "../inc.h"

struct Interval {
	int start;
	int end;
};

void dump(struct Interval* intervals, int intervalsSize)
{
	if(intervals == NULL) return;

	for(int i = 0; i < intervalsSize; i++) {

		struct Interval *it = intervals + i;
		printf("[%d, %d]\n", it->start, it->end);
	}
	printf("\n");
}

int compare(const void *a, const void *b) { 
	
	return ((struct Interval *) a)->start > ((struct Interval *) b)->start;
}

struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
	
	struct Interval *ret;
	int j, count = 0, right;

	*returnSize = 0;
	if(intervals == NULL || intervalsSize < 1) return NULL;

	ret = malloc(sizeof(struct Interval) * intervalsSize);
	qsort(intervals, intervalsSize, sizeof(struct Interval), &compare);

	dump(intervals, intervalsSize);
	for(int i = 0 ; i < intervalsSize; i = j) {
		
		j = i + 1;
		right = intervals[i].end;

		while(j < intervalsSize && intervals[j].start <= right) {
			
			if(intervals[j].end > right)
				right = intervals[j].end;
			j++;
		}

		ret[(*returnSize)].start = intervals[i].start;
		ret[(*returnSize)++].end = right;
	}
	return ret;
}

int main()
{
#if 0
	struct Interval intervals[] = {
		{.start = 1,
		 .end = 3,},
		{.start = 2,
		 .end = 6,},
		{.start = 8,
		 .end = 10,},
		{.start = 15,
		 .end = 18,}
	};
	#else
	struct Interval intervals[] = {
		{.start = 1,
		 .end = 4,},
		{.start = 4,
		 .end = 5,},
	};
	#endif

	int returnSize;

	struct Interval *m = merge(intervals, sizeof(intervals) / sizeof(intervals[0]), &returnSize);
	dump(m, returnSize);
	return 0;
}
