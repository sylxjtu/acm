#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

char board[8][8];

struct Cood
{
	int y;
	int x;
	Cood(int y, int x): y(y) , x(x){}
};

vector<Cood> validmoves;

inline int isinboard(int y, int x){
	if (y>=0 && y<=7 && x>=0 && x<=7)
	{
		return 1;
	}
	return 0;
}

int isvalid(char mv, int y, int x, int incy, int incx){
	if (board[y][x]!='-')
	{
		return 0;
	}
	y+=incy;
	x+=incx;
	if (!isinboard(y,x) || board[y][x]=='-' || board[y][x]==mv)
	{
		return 0;
	}
	while(1){
		y+=incy;
		x+=incx;
		if (!isinboard(y,x) || board[y][x]=='-')
		{
			return 0;
		}
		else if (board[y][x]==mv)
		{
			return 1;
		}
	}
	return 0;
}

void setmv(char mv, int y, int x, int incy, int incx){
	if (isvalid(mv,y,x,incy,incx))
	{
		while(1){
			y+=incy;
			x+=incx;
			if (board[y][x]==mv)
			{
				return;
			}
			board[y][x]=mv;
		}
	}
}

void getvalidmoves(char mv){
	for (int j = 0; j < 8; ++j)
	{
		for (int k = 0; k < 8; ++k)
		{
			for (int incy = -1; incy <= 1; ++incy)
			{
				for (int incx = -1; incx <= 1; ++incx)
				{
					if (isvalid(mv,j,k,incy,incx))
					{
						validmoves.push_back(Cood(j,k));
						goto cont;
					}
				}
			}
			cont:;
		}
	}
}

int list(char& mv){
	getvalidmoves(mv);
	if (validmoves.empty())
	{
		printf("No legal move.\n");
		return 1;
	}
	for(auto &i: validmoves){
		printf("(%d,%d)", i.y+1, i.x+1);
		if (&i == &validmoves.back())
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}
	}
	validmoves.clear();
	return 1;
}

int move(char& mv){
	char c1,c2;
	scanf("%c%c",&c1,&c2);
	int r=c1-'1',c=c2-'1';
	getvalidmoves(mv);
	if (validmoves.empty())
	{
		mv=(mv=='B')?'W':'B';
	}
	for (int incy = -1; incy <= 1; ++incy)
	{
		for (int incx = -1; incx <= 1; ++incx)
		{
			setmv(mv,r,c,incy,incx);
		}
	}
	board[r][c]=mv;
	mv=(mv=='B')?'W':'B';
	int b=0,w=0;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (board[i][j]=='W')
			{
				w++;
			}
			if (board[i][j]=='B')
			{
				b++;
			}
		}
	}
	printf("Black - %2d White - %2d\n", b, w);
	validmoves.clear();
	return 1;
}

int quit(char& mv){
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}

using funcptr = int (*)(char&);

map<char,funcptr> instruct = {{'L',list},{'M',move},{'Q',quit}};

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		if (i!=0)
		{
			printf("\n");
		}

		for (int j = 0; j < 8; ++j)
		{
			for (int k = 0; k < 8; ++k)
			{
				scanf(" %c",&board[j][k]);
			}
		}

		char mv;
		scanf(" %c",&mv);

		while(1){
			char c;
			scanf(" %c",&c);
			if(!instruct[c](mv)){
				break;
			}
		}
	}
	return 0;
}