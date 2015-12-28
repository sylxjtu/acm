//AC Time: 360MS
//Algorithm: Binary search
#include <cstdio>
#include <algorithm>

int primes[1000000],pns[100000],pnn,rt[3];
void init(){
	for (int i = 2; i < 500000; ++i)
	{
		if (!primes[i])
		{
			for (int j = 2; j*i < 1000000; ++j)
			{
				primes[j*i]=1;
			}
		}
	}
	for (int i = 3; i < 1000000; ++i)
	{
		if (!primes[i])
		{
			pns[pnn++]=i;
		}
	}
}
int inp(){
	if(!scanf("%d",rt))
		return 0;
	return rt[0];
}
void outp(){
	printf("%d = %d + %d\n", rt[0], rt[1], rt[2]);
}
void process(){
	for (int i = 0; i < pnn; ++i)
	{
		if (std::binary_search(pns,pns+pnn,rt[0]-pns[i]))
		{
			rt[1]=pns[i];
			rt[2]=rt[0]-pns[i];
			return;
		}
	}
}
int main()
{
	init();
	while(inp()){
		process();
		outp();
	}
	return 0;
}