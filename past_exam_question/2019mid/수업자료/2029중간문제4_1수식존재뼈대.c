// 01:02~
#include <stdio.h>
#include <stdlib.h>
int pick( int *items, int itemSize, int* bucket, int bucketSize, int k, int N) { 
	int i, lastIndex, smallest;
	int total = 0;
	int found;

	if(k == 0 ) {
	







	} 

	lastIndex = bucketSize - k - 1; // 가장 최근에 뽑힌 수가 저장된 위치 i

	smallest = 0; // 중복순열	
	//중복순열
	found = 0;
	for(i = smallest; i < itemSize; i++) {
		bucket[lastIndex + 1] = items[i]; // 중복수열은 bucket에 아이템을 *쉽게* 직접 넣어서 풀수있다
		found = found || pick(items, itemSize, bucket, bucketSize, k - 1, N);
	}
	return found;
}

int main(void)
{
	int items[] = {1, -1};
	int *bucket;
	int n;
	int N;
	

	//printf("수를 입력");
	scanf("%d %d", &n, &N);

	bucket = (int *)malloc(sizeof(int) * n);
	printf("%d\n", pick(items, 2, bucket, n, n, N));

}
