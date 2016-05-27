#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int arr[30000];
int w,n;
int pfp=0;
int fp=0;
int cnt=0;
map< pair<int,int> , pair<int,int> > mp;

int tr(int curn, int curw){
	//cout << curn << " " << curw << endl;
	if (mp.count(pair<int,int>(curn,curw)))
	{
		return mp[pair<int,int>(curn,curw)].first;
	}
	curn++;
	if (curn >= n)
	{
		mp[pair<int,int>(curn-1,curw)] = pair<int,int>(curw,0);
		return curw;
	}
	if (arr[curn] > curw)
	{
		mp[pair<int,int>(curn-1,curw)] = pair<int,int>(curw,0);
		return curw;
	}
	int r1,r2,x;
	r1=tr(curn,curw-arr[curn]);
	r2=tr(curn,curw);
	x = r1<r2?1:0;
	mp[pair<int,int>(curn-1,curw)] = pair<int,int>(min(r1,r2),x);
	return min(r1,r2);
}

int main(){
	cin >> w >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	while(1){
		mp.clear();
		sort(arr+pfp,arr+n);
		pfp=fp;
		tr(-1, w);
		cnt++;
		pair<int,int> pr=pair<int,int>(fp-1,w);
		while(mp.count(pr)){
			if (pr.first+1 == n)
			{
				break;
			}
			int tmp = arr[pr.first+1];
			if (mp[pr].second)
			{
				fp++;
				arr[pr.first+1] = 0;
			}
			pr = pair<int,int>(pr.first+1,w - tmp + arr[pr.first+1]);
		}
		if (fp == n)
		{
			break;
		}
	}
	cout << cnt << endl;
	return 0;
}
