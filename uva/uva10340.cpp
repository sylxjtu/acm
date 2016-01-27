#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	string s1,s2;
	while(cin >> s1 >> s2) {
	    int curI=0;
	    for(auto c: s1){
	    	int found=0;
	    	for (int i = curI; i < s2.size(); ++i)
	    	{
	    		if(c==s2[i]) {
	    			curI=i+1;
	    			found=1;
	    			break;
	    		}
	    	}
	    	if(!found) {
	    		printf("No\n");
	    		goto cont;
	    	}
	    }
	    printf("Yes\n");
	    cont:;
	}
}