#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Bigint{
	vector<int> data;
	Bigint() = default;
	void apply(){
		for (int i = 0; i < data.size(); ++i)
		{
			if (i == data.size()-1)
			{
				while(data[i]>=10){
					data.push_back(data[i]/10);
					data[i]%=10;
					i++;
				}
			}
			data[i+1]+=data[i]/10;
			data[i]%=10;
		}
	}
	Bigint(int i){
		data.push_back(i);
		this->apply();
	}
	Bigint operator+=(const Bigint& x){
		for (int i = 0; i < x.data.size(); ++i)
		{
			if (i>=data.size())
			{
				data.push_back(x.data[i]);
			}
			else
			{
				data[i]+=x.data[i];
			}
		}
		apply();
	}
	Bigint operator*(const Bigint& x){
		Bigint r;
		for (int i = 0; i < data.size(); ++i)
		{
			Bigint t;
			for (int j = 0; j < i; ++j)
			{
				t.data.push_back(0);
			}
			for (int j = 0; j < x.data.size(); ++j)
			{
				t.data.push_back(data[i]*x.data[j]);
			}
			r+=t;
		}
		return r;
	}
};

Bigint mypow(Bigint b, int n){
	Bigint r(1);
	for(;n;n>>=1){
		if (n&1)
		{
			r = r*b;
		}
		b = b*b;
	}
	return r;
}

int main(){
	int t;
	cin >> t;
	Bigint b = mypow(Bigint(2), t);
	b += Bigint(-1);
	b = b * Bigint(2);
	reverse(b.data.begin(), b.data.end());
	for (int i = 0; i < b.data.size(); ++i)
	{
		cout << b.data[i];
	}
	cout << endl;
	return 0;
}