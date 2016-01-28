#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int gensum(int n);

int main(){
	int kase;
	scanf("%d",&kase);
	for (int i = 0; i < kase; ++i)
	{
		int dest;
		scanf("%d",&dest);
		for (int j = max( dest-9*int(log(dest)/log(10) + 1) , 0); j < dest; ++j)
		{
			if (gensum(j)==dest)
			{
				printf("%d\n", j);
				goto found;
			}
		}
		printf("%d\n", 0);
		found:;
	}
	return 0;
}

int gensum(int n){
	int ret=n;
	while(n){
		ret+=n%10;
		n/=10;
	}
	return ret;
}
