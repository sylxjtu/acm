#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

struct Student
{
	int a,b,c;
	Student(int a,int b,int c):a(a),b(b),c((c-1)%(a+b)){};
	void forward(int sleepable){
		c++;
		c%=a+b;
		if (c==a)
		{
			if (!sleepable)
			{
				c=0;
			}
		}
	}
	inline int isasleep(){
		return c>=a;
	}
};

int main(){
	int kase=1;
	while(1){
		vector<Student> stuv;
		set< vector<int> > s;
		int n;
		cin >> n;
		if (!n)
		{
			return 0;
		}
		for (int i = 0; i < n; ++i)
		{
			int a,b,c;
			cin >> a >> b >> c;
			stuv.push_back(Student(a,b,c));
		}
		int totalsec=1;
		while(1){
			int asleep=0;
			vector<int> tmpv;
			for(auto& i: stuv)
			{
				tmpv.push_back(i.c);
				asleep+=(i.isasleep()?1:0);
			}
			for(auto& i: stuv)
			{
				i.forward(asleep > stuv.size()-asleep);
			}
			int sorisize = s.size();
			s.insert(tmpv);
			tmpv.clear();
			if (s.size() == sorisize)
			{
				printf("Case %d: %d\n", kase, -1);
				break;
			}
			if (asleep == 0)
			{
				printf("Case %d: %d\n", kase, totalsec);
				break;
			}
			totalsec++;
		}
		kase++;
	}
}