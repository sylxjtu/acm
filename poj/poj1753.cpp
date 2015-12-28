//AC Time: 469MS
//Algorithm: brute-force
#include <cstdio>
#include <cstring>
int graph[4][4];
int tmp[4][4];

void inp(){
	char t;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			scanf(" %c",&t);
			if (t=='b')
			{
				graph[i][j]=1;
			}
		}
	}
}

int flip(int v){
	memcpy(tmp,graph,16 * sizeof(int));
	for (int i = 0; i < 16; ++i,v=v>>1)
	{
		if(v&1){
			int x=i%4;
			int y=i/4;
			for (int dx = -1; dx <= 1; ++dx)
			{
				if (x+dx>=0 && x+dx < 4)
				{
					tmp[y][x+dx]=!tmp[y][x+dx];
				}
			}
			for (int dy = -1; dy <= 1; ++dy)
			{
				if (y+dy>=0 && y+dy < 4)
				{
					tmp[y+dy][x]=!tmp[y+dy][x];
				}
			}
			tmp[y][x]=!tmp[y][x];
		}
	}
	for (int i = 0; i < 16; ++i)
	{
		if (tmp[i/4][i%4]!=tmp[0][0])
		{
			return 0;
		}
	}
	return 1;
}

int main(){
	int c=0;
	int min=17;
	inp();
	for (int i = 0; i < 1<<16; ++i)
	{
		if (flip(i))
		{
			c=0;
			int t=i;
			for (int j = 0; j < 16; ++j,t=t>>1)
			{
				if (t&1)
				{
					c++;
				}
			}
			min=c<min?c:min;
		}
	}
	if (min!=17)
	{
		printf("%d\n", min);
		return 0;
	}
	printf("Impossible\n");
	return 0;
}