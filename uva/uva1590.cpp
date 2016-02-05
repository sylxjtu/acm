#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct IpAddr
{
	unsigned int data;
	IpAddr(int data=0):data(data){}
};

ostream& operator << (ostream &out, const IpAddr& ip){
	for (int i = 0; i < 4; ++i)
	{
		if (i!=0)
		{
			out << '.';
		}
		out << ( ( ip.data >> ( (3-i) * 8 ) ) & 255 );
	}
	return out;
}

istream& operator >> (istream &in, IpAddr& ip){
	for (int i = 0; i < 4; ++i)
	{
		if (i!=0)
		{
			in.ignore(1,'.');
		}
		int tmp;
		in >> tmp;
		ip.data |= tmp;
		if (i!=3)
		{
			ip.data <<= 8;
		}
	}
	return in;
}

vector<IpAddr> v;

int main(){
	while(1){
		int n;
		if(scanf("%d",&n)!=1){
			return 0;
		}
		for (int i = 0; i < n; ++i)
		{
			IpAddr ip;
			cin >> ip;
			v.push_back(ip);
		}
		for (int i = 0; i < 32; ++i)
		{
			int bit = (1<<(31-i)) & v.front().data;
			for(auto &a: v){
				if ( ((1<<(31-i)) & a.data) != bit)
				{
					IpAddr mask = IpAddr(((1<<i)-1)<<(32-i));
					IpAddr segment = IpAddr(mask.data & v.front().data);
					cout << segment << endl << mask << endl;
					goto nxt;
				}
			}
		}
		cout << IpAddr(v.front().data) << endl << IpAddr(4294967295) << endl;
		nxt:
		v.clear();
	}
}