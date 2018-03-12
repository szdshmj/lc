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

int compare(const void *a, const void *b) { return ((struct Interval *) a)->start > ((struct Interval *) b)->start;}

struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
	
	struct Interval *ret = NULL;

	if(intervals == NULL || intervalsSize < 1) {

		ret = malloc(sizeof(struct Interval));
		memcpy(ret, &newInterval, sizeof(struct Interval));
		*returnSize = 1;
		return ret;
	}

	*returnSize = 0;

}

int main()
{
	int returnSize;
#if 0
	struct Interval intervals[] = {
		{.start = 1, .end = 3,},
		{.start = 6, .end = 9,},
	};
	struct Interval newInterval = {.start = 2, .end = 5};
#else
	struct Interval intervals[] = {
		{.start = 1, .end = 2},
		{.start = 3, .end = 5},
		{.start = 6, .end = 7},
		{.start = 8, .end = 10},
		{.start = 12, .end = 16},
	};
	struct Interval newIntervals = {.start = 4, .end = 9};
#endif

	struct Interval *m = insert(intervals, sizeof(intervals) / sizeof(intervals[0]), newIntervals, &returnSize);

	dump(m, returnSize);
	return 0;
}
