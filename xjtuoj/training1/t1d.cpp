#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int n, h;
int fi[30],di[30],ti[30],spdti[30];

int maxFish(int h, int curnode){
	if (curnode == n-1 || h<=ti[curnode])
	{
		int ret = 0;
		int remainFish = fi[curnode] - di[curnode]*spdti[curnode];
		spdti[curnode]+=h;
		for(; remainFish>0 && h>0; remainFish-=di[curnode], h--){
			ret += remainFish;
		}
		return ret;
	}
	else{
		int retmoveon = maxFish(h-ti[curnode], curnode+1);
		for (int i = curnode+1; i < n; ++i)
		{
			spdti[i] = 0;
		}
		int stayfish = fi[curnode] - di[curnode]*spdti[curnode];
		int spdtit = spdti[curnode];
		spdti[curnode]++;
		int retstay = maxFish(h-1, curnode) + (stayfish>0?stayfish:0);
 		if (retmoveon > retstay)
 		{
 			spdti[curnode] = spdtit;
 			for (int i = curnode+1; i < n; ++i)
 			{
 				spdti[i] = 0;
 			}
 			return maxFish(h-ti[curnode], curnode+1);
 		}
 		else{
 			return retstay;
 		}
	}
}

int main(){
	int kase = 0;
	while(1){
		cin >> n;
		if (!n)
		{
			return 0;
		}
		if (!kase)
		{
			kase = 1;
		}
		else{
			cout << endl;
		}
		cin >> h;
		h*=12;
		for (int i = 0; i < n; ++i)
		{
			cin >> fi[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> di[i];
		}
		for (int i = 0; i < n-1; ++i)
		{
			cin >> ti[i];
		}
		int ret = maxFish(h,0);
		for (int i = 0; i < n; ++i)
		{
			cout << spdti[i]*5;
			if (i != n-1)
			{
				cout << ", ";
			}
		}
		cout << endl << "Number of fish expected: " << ret << endl;
		for (int i = 0; i < 30; ++i)
		{
			spdti[i] = 0;
		}
	}
}