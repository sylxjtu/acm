#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> strv;
char s[]={'A','C','G','T'};

int main(){
	int ksn;
	scanf("%d",&ksn);
	for (int ks = 0; ks < ksn; ++ks)
	{
		int m,nlen;
		scanf("%d%d",&m,&nlen);
		std::string a;
		for (int i = 0; i < m; ++i)
		{
			std::cin >> a;
			strv.push_back(a);
		}
		std::vector<char> outpv;
		int totsum=0;
		for (int ni = 0; ni < nlen; ++ni)
		{
			int curMin=m+1;
			char curMinp;
			for (int i = 0; i < 4; ++i)
			{
				int sum=0;
				for (int j = 0; j < m; ++j)
				{
					sum+=(s[i]==strv[j][ni]?0:1);
				}
				if(sum<curMin) {
					curMin=sum;
					curMinp=s[i];
				}
			}
			outpv.push_back(curMinp);
			totsum+=curMin;
		}
		for (auto i: outpv)
		{
			std::cout << i;
		}
		printf("\n%d\n",totsum);
		strv.clear();
	}
}