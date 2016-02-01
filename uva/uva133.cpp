#include <iostream>
#include <cstdio>

using namespace std;

int appli[20];

int main(){
	int n, ls, rs;
	while(1){
		cin >> n >> ls >> rs;
		if (!n && !ls && !rs)
		{
			return 0;
		}
		int curP=n;
		for (int i = 0; i < n; ++i)
		{
			appli[i]=1;
		}
		int pp1=0,pp2=n-1;
		while(curP){
			if (curP!=n)
			{
				printf(",");
			}
			int rm1=ls,rm2=rs;
			while(rm1){
				if (appli[(pp1++)%n])
				{
					rm1--;
				}
			}
			pp1--;
			pp1%=n;
			while(rm2){
				if (pp2==-1)
				{
					pp2=n-1;
				}
				if (appli[(pp2--)%n])
				{
					rm2--;
				}
			}
			pp2++;
			pp2%=n;

			appli[pp1]=0;
			appli[pp2]=0;

			if (pp1==pp2)
			{
				printf("%3d", pp1+1);
				curP--;
			}
			else
			{
				printf("%3d%3d", pp1+1, pp2+1);
				curP-=2;
			}
		}
		printf("\n");
	}
	return 0;
}
