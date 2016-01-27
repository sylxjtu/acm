#include <cstdio>
#include <vector>

struct Point {
	int x;
	int y;
	Point(int y=0,int x=0):x(x),y(y){};
};

char puzzle[20][20];

std::vector<Point> epoints;

int main(){
	int kase=0;
	while(++kase){
		int r,c;
		scanf("%d",&r);
		if(r==0) {
			return 0;
		}
		scanf("%d",&c);
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				scanf(" %c",&puzzle[i][j]);
			}
		}
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if(puzzle[i][j]!='*') {
					if( (!i || !j) || ( puzzle[i-1][j]=='*' || puzzle[i][j-1]=='*' ) ) {
						epoints.push_back(Point(i,j));
					}
				}
			}
		}
		if(kase!=1) {
			printf("\n");
		}
		printf("puzzle #%d:\n", kase);
		printf("Across\n");
		for (int i = 0; i < epoints.size(); ++i)
		{
			if(epoints[i].x==0 || puzzle[epoints[i].y][epoints[i].x-1]=='*') {
				printf("%3d.", i+1);
				for (int j = epoints[i].x; j < c && puzzle[epoints[i].y][j]!='*' ; ++j)
				{
					printf("%c", puzzle[epoints[i].y][j]);
				}
				printf("\n");
			}
		}
		printf("Down\n");
		for (int i = 0; i < epoints.size(); ++i)
		{
			if(epoints[i].y==0 || puzzle[epoints[i].y-1][epoints[i].x]=='*') {
				printf("%3d.", i+1);
				for (int j = epoints[i].y; j < r && puzzle[j][epoints[i].x]!='*' ; ++j)
				{
					printf("%c", puzzle[j][epoints[i].x]);
				}
				printf("\n");
			}
		}
		epoints.clear();
	}
}