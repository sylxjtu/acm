#include <cstdio>
#include <cstring>
int mp[20][20];
int visited[20][20];
int w,h,sw,sh;
int inp(){
	memset(visited,0,sizeof(visited));
	int wt,ht;
	char tmp;
	scanf(" %d %d",&wt,&ht);
	if (!wt || !ht)
	{
		return 0;
	}
	w=wt,h=ht;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			scanf(" %c",&tmp);
			switch(tmp){
				case '.':
				mp[i][j]=1;
				break;
				case '#':
				mp[i][j]=0;
				break;
				case '@':
				sw=j,sh=i;
				mp[i][j]=1;
			}
		}
	}
	return 1;
}
void outp(int a){
	printf("%d\n", a);
}
int dfs(int sw,int sh){
	int ret=1;
	visited[sh][sw]=1;
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			if (sh+i>=0 && sh+i<h && sw+j>=0 && sw+j<w && !(i&&j))
			{
				if (!(visited[sh+i][sw+j]) && mp[sh+i][sw+j])
				{
					ret+=dfs(sw+j,sh+i);
				}
			}
		}
	}
	return ret;
}
int main()
{
	while(inp()){
		outp(dfs(sw,sh));
	}
	return 0;
}