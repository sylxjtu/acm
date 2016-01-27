#include <cstdio>
#include <cctype>

char buf[5][5];
char opr[100];

int main(){
	int kase=0,oprp=0,curI,curJ;
	while(++kase){
		oprp=0;
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if((buf[i][j]=getchar())=='\n'){
					return 0;
				}
				else if(buf[i][j]==' ')
					curI=i,curJ=j;
			}
			while(getchar()!='\n')
				;
		}
		if(kase!=1) {
			printf("\n");
		}
		while((opr[oprp++]=getchar())!='0')
			;
		getchar();
		opr[oprp]=0;
		for (int i = 0; opr[i]; ++i)
		{
			switch(opr[i]){
				case 'A':
				curI--;
				if(curI<0) {
					goto inv;
				}
				buf[curI+1][curJ]=buf[curI][curJ];
				buf[curI][curJ]=' ';
				break;

				case 'B':
				curI++;
				if(curI>4) {
					goto inv;
				}
				buf[curI-1][curJ]=buf[curI][curJ];
				buf[curI][curJ]=' ';
				break;

				case 'L':
				curJ--;
				if(curJ<0) {
					goto inv;
				}
				buf[curI][curJ+1]=buf[curI][curJ];
				buf[curI][curJ]=' ';
				break;

				case 'R':
				curJ++;
				if(curJ>4) {
					goto inv;
				}
				buf[curI][curJ-1]=buf[curI][curJ];
				buf[curI][curJ]=' ';
				break;

				default:
				if(isalpha(opr[i])) {
					goto inv;
				}
			}
		}

		printf("Puzzle #%d:\n",kase);
		for (int i = 0; i < 5; ++i)
		{
			printf("%c %c %c %c %c\n", buf[i][0], buf[i][1], buf[i][2], buf[i][3], buf[i][4]);
		}

		continue;
		inv:
		printf("Puzzle #%d:\n",kase);
		printf("This puzzle has no final configuration.\n");
	}
}