//AC Time: 750MS
//Algorithm: BFS
//卧槽成功了！！！
//TLE了整整3天终于成功了
#include <cstdio>
#include <cstring>
int q[1<<16],qf=0,qe=0;
int graph[4][4],tmp[4][4];
void inp(){
	char t;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			scanf(" %c",&t);
			if (t=='-')
			{
				graph[i][j]=1;
			}
		}
	}
}
int process_v(int v){
	memcpy(tmp,graph,16*sizeof(int));
	for (int i = 0; i < 16; ++i)
	{
		if (v&(1<<i))
		{
			int x=i%4;
			int y=i/4;
			for (int j = 0; j < 4; ++j)
			{
				tmp[y][j]=!tmp[y][j];
				tmp[j][x]=!tmp[j][x];
			}
			tmp[y][x]=!tmp[y][x];
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (tmp[i][j]!=1)
			{
				return 0;
			}
		}
	}
	return v;
}

int bfs(){
	int n=q[qf++],nn;
	if (process_v(n))
	{
		return n;
	}
	else
	{
		for (int i = 0; i < 16; ++i)
		{
			if (!((n>>i)&1))
			{
				q[qe++]=n|(1<<i);
			}
			else{
				break;
			}
		}
		return 0;
	}
}

int main(){
	int r,bts=0;
	inp();
	for (int i = 0; i < 16; ++i)
	{
		q[qe++]=1<<i;
	}
	while(!(r=bfs()))
		;
	for (int i = 0; i < 16; ++i)
	{
		if (r&(1<<i))
		{
			bts++;
		}
	}
	printf("%d\n", bts);
	for (int i = 0; i < 16; ++i)
	{
		if (r&(1<<i))
		{
			printf("%d %d\n", i/4+1, i%4+1);
		}
	}
	return 0;
}