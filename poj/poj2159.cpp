//AC Time: 47MS
//Algorithm: sort?
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v1(26,0),v2(26,0);
char out[2][4]={"NO","YES"};
void inp(){
	char tmp;
	while((tmp=getchar())!='\n'){
		v1[tmp-'A']++;
	}
	while((tmp=getchar())!='\n'){
		v2[tmp-'A']++;
	}
}
void outp(int i){
	printf("%s\n", out[i]);
}
int process(){
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	if (v1==v2)
	{
		return 1;
	}
	return 0;
}
int main(int argc, char const *argv[])
{
	inp();
	outp(process());
	return 0;
}