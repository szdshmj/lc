int numTrees(int n) {

	int a[n + 1];

	a[0] = 1;

	for(int i = 1; i <= n; i++) {

		a[i] = 0;

		for(int j = 0; j < i; j++)
			a[i] += a[j] * a[i - 1 -j];
	}
	return a[n];
}
