#include <cstdio>
#include <cstring>
int oristr[1010];
int tmpstr[1010];
int matchedo[1010];
int matchedt[1010];
int main(){
	int n=0,game=0;
	while(++game){
		scanf("%d",&n);
		if (!n)
		{
			return 0;
		}
		printf("Game %d:\n", game);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",oristr+i);
		}
		while(1){
			int flag=1,sm=0,wm=0;
			for (int i = 0; i < n; ++i)
			{
				scanf("%d",tmpstr+i);
				if (tmpstr[i]!=0)
				{
					flag=0;
				}
			}
			if (flag)
			{
				break;
			}
			for (int i = 0; i < n; ++i)
			{
				if (tmpstr[i]==oristr[i])
				{
					sm++;
					matchedo[i]=1;
					matchedt[i]=1;
				}
			}
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if (!matchedt[i] && !matchedo[j] && tmpstr[i]==oristr[j])
					{
						wm++;
						matchedo[j]=1;
						matchedt[i]=1;
						break;
					}
				}
			}
			printf("    (%d,%d)\n", sm, wm);
			memset(matchedt,0,sizeof(int)*n);
			memset(matchedo,0,sizeof(int)*n);
		}
	}
	return 0;
}