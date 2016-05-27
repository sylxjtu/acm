#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

#define Y (bp/8)
#define X (bp%8)
struct Point{
	int y;
	int x;
	Point(int y=0, int x=0): y(y), x(x){}
	void print() const{
		cout << char('a' + x) << 8 - y;
	}
};

bool operator<(const Point& pl, const Point& pr){
	if (pl.y>pr.y)
	{
		return true;
	}
	else if (pl.y == pr.y)
	{
		return pl.x<pr.x;
	}
	return false;
}

bool black(const Point& pl, const Point& pr){
	if (pl.y<pr.y)
	{
		return true;
	}
	else if (pl.y == pr.y)
	{
		return pl.x<pr.x;
	}
	return false;
}

Point parr[2][8][8];
int ind[2][8];

char board[8][8];
char seq[6] = {'K','Q','R','B','N','P'};

int main(){
	int bp = 0;
	char tp;
	while((tp=getchar())!=EOF){
		if(tp == '|'){
			char t = getchar();
			if(t == '.' || t == ':'){
				board[Y][X] = getchar();
				bp++;
			}
		}
	}
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if(isalpha(board[i][j])){
				int color;
				if (isupper(board[i][j]))
				{
					color = 0;
				}
				else{
					color = 1;
				}
				for (int k = 0; k < 6; ++k)
				{
					if (seq[k] == toupper(board[i][j]))
					{
						parr[color][k][ind[color][k]++] = Point(i,j);
					}
				}
			}
		}
	}
	for (int i = 0; i < 2; ++i)
	{
		printf(!i?"White: ":"Black: ");
		int pcomma = 0;
		for (int j = 0; j < 6; ++j)
		{
			if (!i)
			{
				sort(parr[i][j],parr[i][j]+ind[i][j]);
			}
			else{
				sort(parr[i][j],parr[i][j]+ind[i][j],black);
			}
			for (int k = 0; k < ind[i][j]; ++k)
			{
				if (!pcomma)
				{
					pcomma = 1;
				}
				else{
					putchar(',');
				}
				j!=5?putchar(seq[j]):0;
				parr[i][j][k].print();
			}
		}
		printf("\n");
	}
	return 0;
}