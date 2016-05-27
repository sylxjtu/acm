#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int factor[] = {2, 3, 5};
int cnt = 1;
priority_queue< long long,vector<long long>,greater<long long> > pq;
set<long long> st;

int main(){
	pq.push(1);
	st.insert(1);
	while(1){
		long long t = pq.top();
		if (cnt++==1500)
		{
			cout << "The 1500'th ugly number is " << t << "." << endl;
			return 0;
		}
		pq.pop();

		for (int i = 0; i < 3; ++i)
		{
			long long n = t*factor[i];
			if (st.count(n)){
				continue;
			}
			else{
				pq.push(n);
				st.insert(n);
			}
		}
	}
}