#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct scope{
	double start;
	double end;
};

struct point{
	int x;
	int y;
};

bool scopeChoosePointLesser(const scope& s1, const scope& s2){
	return s1.end < s2.end;
}

int main(){
	//Init
	int n,d;
	int kase = 1;
	while(1){
		//Input
		cin >> n >> d;
		if(!n && !d){
			return 0;
		}
		vector<point> vp;
		for (int i = 0; i < n; ++i)
		{
			point t;
			cin >> t.x >> t.y;
			vp.push_back(t);
		}
		//Process
		vector<scope> vs;
		int cnt=1;
		double curEnd;
		for (int i = 0; i < vp.size(); ++i)
		{
			if (vp[i].y > d)
			{
				cout << "Case " << kase << ": " << -1 << endl;
				goto cont;
			}
			double dx=sqrt(d*d-vp[i].y*vp[i].y);
			scope t;
			t.start=vp[i].x-dx;
			t.end=vp[i].x+dx;
			vs.push_back(t);
		}
		sort(vs.begin(), vs.end(), scopeChoosePointLesser);
		curEnd=vs[0].end;
		for (int i = 1; i < vs.size(); ++i)
		{
			if (vs[i].start > curEnd)
			{
				cnt++;
				curEnd=vs[i].end;
			}
		}
		//Output
		cout << "Case " << kase << ": " << cnt << endl;
		cont:
		kase++;
	}
}