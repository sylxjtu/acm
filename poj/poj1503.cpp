//AC Time: 0MS
//Algorithm: None
#include <cstdio>
#include <cstring>
int s[120],bufi[120];
char bufc[120];
int inp(){
	int i,j;
	scanf(" %s",bufc);
	if (bufc[0]=='0' && bufc[1]==0)
	{
		return 0;
	}
	for (i=strlen(bufc)-1,j=0 ; i >= 0; --i,++j)
	{
		bufi[j]=bufc[i]-'0';
	}
	return j-1;
}
void outp(){
	int r;
	for (int i = 119; i >= 0; --i)
	{
		if(s[i]){
			r=i;
			break;
		}
	}
	for (int i = r; i >= 0; --i)
	{
		printf("%d", s[i]);
	}
	printf("\n");
}
void process(int r){
	for (int i = 0; i <= r; ++i)
	{
		s[i]+=bufi[i];
	}
}
void process_fini(){
	for (int i = 0; i < 119; ++i)
	{
		s[i+1]+=s[i]/10;
		s[i]=s[i]%10;
	}
}
int main(){
	int t;
	while((t=inp())){
		process(t);
	}
	process_fini();
	outp();
	return 0;
}