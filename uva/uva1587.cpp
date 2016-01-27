#include <cstdio>
int buf[6][2];
int main(){
	while(1){
		for (int i = 0; i < 6; ++i)
		{
			if(scanf("%d%d",buf[i],buf[i]+1)!=2){
				return 0;
			}
		}
		int h=buf[0][0],w=buf[0][1],d=0;
		int a=0,b=0,c=0;
		for (int i = 0; i < 6; ++i)
		{
			if (buf[i][0]==buf[i][1] && h!=w)
			{
				d=buf[i][0];
				break;
			}
			for (int j = 0; j < 2; ++j)
			{
				if (buf[i][j]!=h && buf[i][j]!=w)
				{
					d=buf[i][j];
					break;
				}
			}
			if (d)
			{
				break;
			}
		}
		if (!d)
		{
			if (h==w)
			{
				printf("POSSIBLE\n");
			}
			else
			{
				printf("IMPOSSIBLE\n");
			}
			continue;
		}
		for (int i = 0; i < 6; ++i)
		{
			if ( (buf[i][0]==h && buf[i][1]==w) || (buf[i][1]==h && buf[i][0]==w) )
			{
				if (a<2)
				{
					a++;
					continue;
				}
			}
			if ( (buf[i][0]==h && buf[i][1]==d) || (buf[i][1]==h && buf[i][0]==d) )
			{
				if (b<2)
				{
					b++;
					continue;
				}
			}
			if ( (buf[i][0]==w && buf[i][1]==d) || (buf[i][1]==w && buf[i][0]==d) )
			{
				if (c<2)
				{
					c++;
					continue;
				}
			}
			printf("IMPOSSIBLE\n");
			goto bigbreak;
		}
		printf("POSSIBLE\n");
		bigbreak:;
	}
}