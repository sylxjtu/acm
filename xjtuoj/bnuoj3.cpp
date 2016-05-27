#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Bigreal{
	vector<int> num;
	int expo;
	friend ostream& operator<< (ostream& o, const Bigreal& r);
	Bigreal(int expo = 0): expo(expo){};
	Bigreal(string s){
		int isdot = 0;
		expo = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '.')
			{
				isdot = 1;
				continue;
			}
			num.push_back(s[i] - '0');
			expo += isdot;
		}
		reverse(num.begin(), num.end());
	}
	void process(){
		for (int i = 0; i < num.size(); ++i)
		{
			if (i == num.size()-1 && num[i] > 9)
			{
				while(num[i] > 9){
					num.push_back(num[i]/10);
					num[i] %= 10;
					i++;
				}
				return;
			}
			num[i+1] += num[i]/10;
			num[i] %= 10;
		}
	}
	Bigreal& operator+=(const Bigreal& b2){
		for (int i = 0; i < b2.num.size(); ++i)
		{
			if (i >= num.size())
			{
				num.push_back(b2.num[i]);
			}
			else
			{
				num[i] += b2.num[i];
			}
		}
		return *this;
	}
	Bigreal operator*(const Bigreal& b2) const{
		Bigreal r;
		for (int i = 0; i < num.size(); ++i)
		{
			Bigreal t;
			for (int ii = 0; ii < i; ++ii)
			{
				t.num.push_back(0);
			}
			for (int j = 0; j < b2.num.size(); ++j)
			{
				t.num.push_back(num[i]*b2.num[j]);
			}
			r+=t;
		}
		r.process();
		r.expo = expo + b2.expo;
		//cout << "in1:" << *this << "in2:" << b2 << "out1:" << r << endl;
		return r;
	}
};

Bigreal mypow(Bigreal& n, unsigned int e){
	Bigreal r(string("1"));
	for (; e; e>>=1)
	{
		if (e&1)
		{
			r = r*n;
		}
		n=n*n;
	}
	return r;
}

ostream& operator<< (ostream& o, const Bigreal& r){
	Bigreal t = r;
	int c = t.expo;
	int d = t.num.size() - t.expo;
	for (int i = 0; i < t.expo; ++i)
	{
		if (t.num[i] != 0)
		{
			c=i;
			break;
		}
	}
	reverse(t.num.begin(), t.num.end());
	for (int i = 0; i < t.num.size() - t.expo; ++i)
	{
		if (t.num[i] != 0)
		{
			d=i;
			break;
		}
	}
	if (c+d >= t.num.size())
	{
		o << 0;
	}
	for (int i = d; i < t.num.size()-c; ++i)
	{
		if (t.num.size() - i == t.expo)
		{
			o << ".";
		}
		o << t.num[i];
	}
	return o;
}

int main(){
	string s;
	unsigned int i;
	while(cin >> s >> i){
		Bigreal x(s);
		cout << mypow(x, i) << endl;
	}
}