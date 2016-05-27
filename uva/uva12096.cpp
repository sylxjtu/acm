#include <iostream>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct SetStack{
	int curID;
	stack<int> s;
	map<set<int>,int> m;
	vector< set<int> > v;

	SetStack():curID(0){}

	int id(const set<int>& st){
		if (!m.count(st))
		{
			m[st] = curID++;
			v.push_back(st);
		}
		return m[st];
	}

	set<int>& setByID(int id){
		return v[id];
	}

	void push(){
		set<int> st;
		s.push(id(st));
	}

	void dup(){
		s.push(s.top());
	}

	void unin(){
		int s1,s2;
		s1=s.top();
		s.pop();
		s2=s.top();
		s.pop();
		set<int> st1=setByID(s1),st2=setByID(s2);
		set<int> st;
		set_union(st1.begin(), st1.end(), st2.begin(), st2.end(), inserter(st,st.begin()));
		s.push(id(st));
	}

	void intersect(){
		int s1,s2;
		s1=s.top();
		s.pop();
		s2=s.top();
		s.pop();
		set<int> st1=setByID(s1),st2=setByID(s2);
		set<int> st;
		set_intersection(st1.begin(), st1.end(), st2.begin(), st2.end(), inserter(st,st.begin()));
		s.push(id(st));
	}

	void add(){
		int s1,s2;
		s1=s.top();
		s.pop();
		s2=s.top();
		s.pop();
		set<int> st2=setByID(s2);
		st2.insert(s1);
		s.push(id(st2));
	}
};

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		SetStack stk;
		int opcnt;
		cin >> opcnt;
		for (int j = 0; j < opcnt; ++j)
		{
			string s;
			cin >> s;
			if (s=="PUSH"){
				stk.push();
			}
			else if(s=="DUP"){
				stk.dup();
			}
			else if(s=="UNION"){
				stk.unin();
			}
			else if(s=="INTERSECT"){
				stk.intersect();
			}
			else{
				stk.add();
			}
			cout << stk.setByID(stk.s.top()).size() << endl;
		}
		cout << "***" << endl;
	}
}