#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int n, m;
	int rootN = 1, rootM = 1;
	int lN = 0, lM = 1, rN = 1, rM = 0;
	int midN, midM;

	scanf("%d %d", &n, &m);

	midN = lN + rN;
	midM = lM + rM;

	while (midN != n || midM != m) {

		if (n * midM < m * midN) {
			printf("L");
			rN = midN;
			rM = midM;
		}
		else {
			printf("R");
			lN = midN;
			lM = midM;
		}
		
		midN = lN + rN;
		midM = lM + rM;
	}
}