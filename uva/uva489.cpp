#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;
int orialpha[26];

int main(){
	int rnd;
	while(1){
		string ori,guess;
		cin >> rnd;
		if (rnd==-1)
		{
			break;
		}
		printf("Round %d\n", rnd);
		cin >> ori >> guess;
		memset(orialpha,0,sizeof(orialpha));
		int fail=0,ccount=0;
		for(auto i: ori){
			if(!orialpha[i-'a']){
				orialpha[i-'a']=1;
				ccount++;
			}
		}
		for(auto i: guess){
			if (orialpha[i-'a'])
			{
				ccount--;
				if (!ccount)
				{
					break;
				}
				orialpha[i-'a']=0;
			}
			else{
				fail++;
				if (fail==7)
				{
					break;
				}
			}
		}
		if (ccount==0)
		{
			printf("You win.\n");
		}
		else if(fail==7){
			printf("You lose.\n");
		}
		else{
			printf("You chickened out.\n");
		}
	}
	return 0;
}
