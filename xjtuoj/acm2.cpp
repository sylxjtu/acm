#include <iostream>
#include <cctype>
using namespace std;
int main(){
	int p1,p2,p3;
	cin >> p1 >> p2 >> p3;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '-' && i!=0 && i!=s.size()-1 && s[i+1]-s[i-1]>0 && ( (isalpha(s[i-1])&&isalpha(s[i+1])) || (isdigit(s[i-1])&&isdigit(s[i+1]))) )
		{
			if (p3==1)
			{
				for (char j = s[i-1]+1; j < s[i+1]; ++j)
				{
					if (p1 == 3)
					{
						for (int k = 0; k < p2; ++k)
						{
							cout << "*";
						}
					}
					else if (p1 == 1)
					{
						for (int k = 0; k < p2; ++k)
						{
							cout << (char)tolower(j);
						}
					}
					else if (p1 == 2)
					{
						for (int k = 0; k < p2; ++k)
						{
							cout << (char)toupper(j);
						}
					}
				}
			}
			else if (p3==2)
			{
				for (char j = s[i+1]-1; j > s[i-1]; --j)
				{
					if (p1 == 3)
					{
						for (int k = 0; k < p2; ++k)
						{
							cout << "*";
						}
					}
					else if (p1 == 1)
					{
						for (int k = 0; k < p2; ++k)
						{
							cout << (char)tolower(j);
						}
					}
					else if (p1 == 2)
					{
						for (int k = 0; k < p2; ++k)
						{
							cout << (char)toupper(j);
						}
					}
				}
			}
			continue;
		}
		cout << s[i];
	}
	cout << endl;
	return 0;
}