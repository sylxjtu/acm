#include <stdio.h>
#include <stdlib.h>

int nums[20];

int intcmp(const void* x1,const void* x2){
	return *((int*)x2)-*((int*)x1);
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 20; ++i)
	{
		scanf(" %d",nums+i);
	}
	qsort(nums,20,sizeof(int),intcmp);
	for (int i = 0; i < 19; ++i)
	{
		printf("%d ", nums[i]);
	}
	printf("%d\n", nums[19]);
	return 0;
}