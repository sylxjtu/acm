#include <cstdio>
#include <vector>
#include <cstring>

struct Instruct{
	int code;
	int datac;
	int data[10];
	Instruct(int code, int datac): code(code), datac(datac){}
};

struct Td{
	int exist=1;
	int r;
	int c;
	int orir;
	int oric;
	int rdt=0;
	int cdt=0;
	Td(int r=0,int c=0): r(r), c(c), orir(r), oric(c){} 
	void apply(){
		this->r+=this->rdt;
		this->c+=this->cdt;
		this->rdt=0;
		this->cdt=0;
	}
};

std::vector<Instruct> vi;
std::vector<Td> vtd;

void dr(const Instruct& ins){
	for (int i = 0; i < ins.datac; ++i)
	{
		for (auto &j: vtd){
			if (ins.data[i] == j.r)
			{
				j.exist=0;
			}
			else if (ins.data[i] <= j.r)
			{
				j.rdt--;
			}
		}
	}
	for (auto &j: vtd){
		j.apply();
	}
}

void dc(const Instruct& ins){
	for (int i = 0; i < ins.datac; ++i)
	{
		for (auto &j: vtd){
			if (ins.data[i] == j.c)
			{
				j.exist=0;
			}
			else if (ins.data[i] <= j.c)
			{
				j.cdt--;
			}
		}
	}
	for (auto &j: vtd){
		j.apply();
	}
}

void ir(const Instruct& ins){
	for (int i = 0; i < ins.datac; ++i)
	{
		for (auto &j: vtd){
			if (ins.data[i] <= j.r)
			{
				j.rdt++;
			}
		}
	}
	for (auto &j: vtd){
		j.apply();
	}
}

void ic(const Instruct& ins){
	for (int i = 0; i < ins.datac; ++i)
	{
		for (auto &j: vtd){
			if (ins.data[i] <= j.c)
			{
				j.cdt++;
			}
		}
	}
	for (auto &j: vtd){
		j.apply();
	}
}

void ex(const Instruct& ins){
	int r1=ins.data[0],c1=ins.data[1],r2=ins.data[2],c2=ins.data[3];
	int brk=0;
	for (auto &i: vtd){
		if (i.r==r1 && i.c==c1)
		{
			i.r=r2, i.c=c2;
			continue;
		}
		if (i.r==r2 && i.c==c2)
		{
			i.r=r1, i.c=c1;
			continue;
		}
	}
}

char inst_code[][3]={"DR","DC","IR","IC","EX"};
using funcptr = void(*)(const Instruct&);
funcptr operations[5]={dr,dc,ir,ic,ex};

int main(){
	int r,c,n,kase=0;
	while(++kase){
		scanf("%d %d",&r,&c);
		if (r==0 || c==0)
		{
			return 0;
		}
		scanf("%d",&n);
		if (kase!=1)
		{
			printf("\n");
		}
		printf("Spreadsheet #%d\n", kase);
		for (int i = 0; i < n; ++i)
		{
			int code=0,datac;
			char tmp[3];
			scanf("%s",tmp);
			for (int i = 0; i < 5; ++i)
			{
				if (!strcmp(tmp,inst_code[i]))
				{
					code=i;
					break;
				}
			}
			if (code==4)
			{
				datac=4;
			}
			else
			{
				scanf("%d",&datac);
			}
			vi.push_back(Instruct(code,datac));
			for (int i = 0; i < datac; ++i)
			{
				scanf("%d",&(vi.back().data[i]));
			}
		}
		scanf("%d",&n);
		for (int i = 0; i < n; ++i)
		{
			int r,c;
			scanf("%d%d",&r,&c);
			vtd.push_back(Td(r,c));
		}
		for (auto i: vi){
			operations[i.code](i);
		}
		for (auto i: vtd){
			if (i.exist)
			{
				printf("Cell data in (%d,%d) moved to (%d,%d)\n",i.orir,i.oric,i.r,i.c);
			}
			else
			{
				printf("Cell data in (%d,%d) GONE\n",i.orir,i.oric);
			}
		}
		vi.clear();
		vtd.clear();
	}
	return 0;
}