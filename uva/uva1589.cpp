#include <cstdio>
#include <cstring>
#include <vector>
#define ATTACKABLE 1
#define OCCUPIED 2

int board[10][9];

inline
int valid(int x, int y){
	return x>=0 && x<9 && y>=0 && y<10;
}

inline
int valid_p(int x, int y){
	return x>=3 && x<=5 && y>=0 && y<=2;
}

void set_flag(int x, int y, int flag){
	if (valid(x,y))
	{
		board[y][x]|=flag;
	}
}

void general(int x, int y){
	for (int i = y-1; i >= 0 && (i==y-1 || !(board[i+1][x] & OCCUPIED) ); --i)
	{
		board[i][x]|=ATTACKABLE;
	}
}

void chariot(int x,int y){
	for (int i = y+1; i < 10 && (i==y+1 || !(board[i-1][x] & OCCUPIED) ); ++i)
	{
		board[i][x]|=ATTACKABLE;
	}
	for (int i = y-1; i >= 0 && (i==y-1 || !(board[i+1][x] & OCCUPIED) ); --i)
	{
		board[i][x]|=ATTACKABLE;
	}
	for (int i = x+1; i < 10 && (i==x+1 || !(board[y][i-1] & OCCUPIED) ); ++i)
	{
		board[y][i]|=ATTACKABLE;
	}
	for (int i = x-1; i >= 0 && (i==x-1 || !(board[y][i+1] & OCCUPIED) ); --i)
	{
		board[y][i]|=ATTACKABLE;
	}
}

void horse(int x, int y){
	if (!(board[y][x+1] & OCCUPIED))
	{
		set_flag(x+2,y+1,ATTACKABLE);
		set_flag(x+2,y-1,ATTACKABLE);
	}
	if (!(board[y][x-1] & OCCUPIED))
	{
		set_flag(x-2,y+1,ATTACKABLE);
		set_flag(x-2,y-1,ATTACKABLE);
	}
	if (!(board[y+1][x] & OCCUPIED))
	{
		set_flag(x+1,y+2,ATTACKABLE);
		set_flag(x-1,y+2,ATTACKABLE);
	}
	if (!(board[y-1][x] & OCCUPIED))
	{
		set_flag(x+1,y-2,ATTACKABLE);
		set_flag(x-1,y-2,ATTACKABLE);
	}
}

void cannon(int x,int y){
	for (int i = y+1; i < 10; ++i)
	{
		if (board[i][x] & OCCUPIED)
		{
			for (int j = i+1; j < 10 && !(board[j][x] & OCCUPIED); ++j)
			{
				board[j][x]|=ATTACKABLE;
			}
			break;
		}
	}
	for (int i = y-1; i >= 0; --i)
	{
		if (board[i][x] & OCCUPIED)
		{
			for (int j = i-1; j >= 0 && !(board[j][x] & OCCUPIED); --j)
			{
				board[j][x]|=ATTACKABLE;
			}
			break;
		}
	}
	for (int i = x+1; i < 10; ++i)
	{
		if (board[y][i] & OCCUPIED)
		{
			for (int j = i+1; j < 10 && !(board[y][j] & OCCUPIED); ++j)
			{
				board[y][j]|=ATTACKABLE;
			}
			break;
		}
	}
	for (int i = x-1; i >= 0; --i)
	{
		if (board[y][i] & OCCUPIED)
		{
			for (int j = i-1; j >= 0 && !(board[y][j] & OCCUPIED); --j)
			{
				board[y][j]|=ATTACKABLE;
			}
			break;
		}
	}
}

char pieceChar[4]={'G','R','H','C'};
void (*pieceArr[4]) (int x, int y) = {general,chariot,horse,cannon};

struct Piece{
	int code;
	int y;
	int x;
	Piece(int code,int y,int x):code(code), y(y), x(x){}
	void run(){
		pieceArr[this->code](this->x,this->y);
	}
};

std::vector<Piece> v;

#ifdef DEBUG
void pboard(){
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			printf("%d", board[i][j]);
		}
		printf("\n");
	}
}
#endif

int main(){
	int n,y,x;
	while(1){
		scanf("%d%d%d",&n,&y,&x);
		if (!n && !y && !x)
		{
			return 0;
		}
		y--,x--;

		for (int i = 0; i < n; ++i)
		{
			char c;
			scanf(" %c",&c);
			int py,px;
			scanf("%d %d",&py,&px);
			for (int i = 0; i < 4; ++i)
			{
				if (c==pieceChar[i])
				{
					board[py-1][px-1]|=OCCUPIED;
					v.push_back(Piece(i,py-1,px-1));
				}
			}
		}

		for(auto i: v){
			i.run();
		}

		for (int i = -1; i <= 1; ++i)
		{
			for (int j = -1; j <= 1; ++j)
			{
				if ( (i || j) && (!i || !j) && valid_p(x+j,y+i) && !(board[y+i][x+j] & ATTACKABLE))
				{
					printf("NO\n");
					goto no;
				}
			}
		}

		printf("YES\n");
		no:;
		memset(board,0,sizeof(board));
		v.clear();
	}
}