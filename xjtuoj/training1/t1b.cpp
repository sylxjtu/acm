#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
queue<int> bfsq;
int board[4][4];
int tempboard[4][4];

int jugde(){
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (tempboard[i][j] != tempboard[0][0])
			{
				return 0;
			}
		}
	}
	return 1;
}

int bfs(int mask){
	memcpy(tempboard, board, sizeof(board));
	for (int i = 0; i < 16; ++i)
	{
		if (mask & (1<<i))
		{
			int r = i/4;
			int c = i%4;
			for (int i = -1; i <= 1; ++i)
			{
				for (int j = -1; j <= 1; ++j)
				{
					if (r+i >=0 && r+i < 4 && c+j >= 0 && c+j < 4 && (!i|!j))
					{
						tempboard[r+i][c+j] = tempboard[r+i][c+j]?0:1;
					}
				}
			}
		}
	}
	return jugde();
}

int main(){
	int t = 0;
	bfsq.push(t);
	for (int i = 0; i < 4; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < 4; ++j)
		{
			board[i][j] = (s[j]=='b'?0:1);
		}
	}
	while(!bfsq.empty()){
		for (int i = 15; i >= -1; --i)
		{
			if (t & (1<<i) || i == -1)
			{
				for (int j = i+1; j < 16; ++j)
				{
					bfsq.push(t|(1<<j));
					//for (int k = 0; k < 15; ++k)
					//{
					//	cout << ( ( (t|(1<<j))  & (1<<k) ) ?1:0);
					//}
					//cout << endl;
				}
				break;
			}
		}
		t = bfsq.front();
		if (bfs(bfsq.front()))
		{
			int cnt = 0;
			for (int i = 0; i < 16; ++i)
			{
				if (t & (1<<i))
				{
					cnt++;
				}
			}
			cout << cnt << endl;
			return 0;
		}
		else {
			bfsq.pop();
		}
	}
	cout << string("Impossible") << endl;
	return 0;
}