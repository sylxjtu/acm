//AC Time: 0MS
//Algorithm: I don't know
#include <cstdio>
int kase;
int buf[300][2],n;

int move();

void init(){
	scanf("%d",&kase);
}
int inp(){
	if (!kase)
	{
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		buf[i][0]=0;
		buf[i][1]=0;
	}
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d",buf[i],buf[i]+1);
	}
	kase--;
	return 1;
}
void outp(int i){
	printf("%d\n", i);
}
int process(){
	int r=0;
	while(move()){
		r+=10;
	}
	return r;
}
int move(){
	int ok=1;
	for (int i = 0; i < n; ++i)
	{
		if (buf[i][0])
		{
			ok=0;
			break;
		}
	}
	if (ok)
	{
		return 0;
	}
	int amin=0,min=201,cmin,mini,brk=0;
	while(!brk){
		brk=1;
		for (int i = 0; i < n; ++i)
		{
			if (!buf[i][0])
			{
				continue;
			}
			cmin=(buf[i][0]+1)/2 < (buf[i][1]+1)/2 ? (buf[i][0]+1)/2 : (buf[i][1]+1)/2;
			if (cmin > amin && cmin < min)
			{
				mini=i;
				min=cmin;
				brk=0;
			}
		}
		amin=(buf[mini][0]+1)/2 > (buf[mini][1]+1)/2 ? (buf[mini][0]+1)/2 : (buf[mini][1]+1)/2;
		buf[mini][0]=0;
		buf[mini][1]=0;
		min=201;
	}
	return 1;
}
int main(){
	init();
	while(inp()){
		outp(process());
	}
}