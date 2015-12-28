//AC Time: 329MS
//Algorithm: None
#include <cstdio>
int primes[1000000],pns[100000],pnn,a,d,n;
void init(){
	for (int i = 2; i < 500000; ++i){
		if (!primes[i]){
			for (int j = 2; i*j < 1000000; ++j){
				primes[i*j]=1;
			}
		}
	}
	for (int i = 2; i < 1000000; ++i)
	{
		if (!primes[i])
		{
			pns[pnn++]=i;
		}
	}
}
int inp(){
	scanf("%d%d%d",&a,&d,&n);
	if (!(a||d||n))
	{
		return 0;
	}
	return 1;
}
int process(){
	int i;
	for (i = 0; i < pnn && n!=0 ; ++i)
	{
		if (pns[i]>=a && (pns[i]-a)%d==0)
		{
			n--;
		}
	}
	return pns[i-1];
}
void outp(int i){
	printf("%d\n", i);
}
int main(void){
	init();
	while(inp()){
		outp(process());
	}
	return 0;
}