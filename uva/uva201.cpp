#include <cstdio>
#include <iostream>
#include <cstring>
int conn[2][10][10];
char connChar[2]={'H','V'};

int isok(int i, int j, int k){
	for (int l = j; l < j+i; ++l)
	{
		if (!conn[0][k][l])
		{
			return false;
		}
		if (!conn[0][k+i][l])
		{
			return false;
		}
	}
	for (int l = k; l < k+i; ++l)
	{
		if (!conn[1][j][l])
		{
			return false;
		}
		if (!conn[1][j+i][l])
		{
			return false;
		}
	}
	return true;
}

int main(){
	int n,cnt;
	int kase=0;
	while(scanf("%d%d",&n,&cnt)==2){
		kase++;
		if (kase!=1)
		{
			printf("\n**********************************\n\n");
		}
		printf("Problem #%d\n\n", kase);
		for (int i = 0; i < cnt; ++i)
		{
			char a;
			int b,c;
			scanf(" %c%d%d",&a,&b,&c);
			for (int j = 0; j < 2; ++j)
			{
				if (a==connChar[j])
				{
					conn[j][b-1][c-1]=1;
				}
			}
		}
		int flag=0;
		for (int i = 1; i <= n-1; ++i)
		{
			int blockcnt=0;
			for (int j = 0; j+i <= n-1; ++j)
			{
				for (int k = 0; k+i <= n-1; ++k)
				{
					if (isok(i,j,k))
					{
						blockcnt++;
					}
				}
			}
			if (blockcnt)
			{
				printf("%d square (s) of size %d\n", blockcnt, i);
				flag=1;
			}
		}
		if (!flag)
		{
			printf("No completed squares can be found.\n");
		}
		memset(conn,0,sizeof(conn));
	}
	return 0;
}