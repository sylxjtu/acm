//AC Time: 0MS
//Algorithm: primesieve
#include <cstdio>
int primes[10001],pns[2000];
int init(){
	int p=0;
	for (int i = 2; i <= 5000; ++i)
	{
		if (!(primes[i]))
		{
			for (int j = 2; j*i <= 10000; ++j)
			{
				primes[j*i]=1;
			}
		}
	}
	for (int i = 2; i < 10001; ++i)
	{
		if (!primes[i])
		{
			pns[p++]=i;
		}
	}
	return p;
}
int inp(){
	int ret;
	scanf("%d",&ret);
	return ret;
}
void outp(int i){
	printf("%d\n", i);
}
int process(int in,int bnd){
	int t=0,w=0;
	for (int i = 0; pns[i]<=in && i<bnd; ++i)
	{
		t=0;
		for (int j = i; j<bnd; ++j)
		{
			t+=pns[j];
			if (t==in)
			{
				w++;
				break;
			}
			if (t>in)
			{
				break;
			}
		}
	}
	return w;
}
int main(){
	int bnd=init(),t;
	while((t=inp())){
		outp(process(t,bnd));
	}
}