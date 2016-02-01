#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Student{
	unsigned long sid;
	int cid;
	char name[11];
	int sc[4];
	int total;
};

Student students[1000];
Student* studentsp = students;
char subject_name[4][15]={"Chinese","Mathematics","English","Programming"};

void ex(){
	exit(0);
}

void add(){
	unsigned long sid;
	while(1){
		int total=0;
		printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
		scanf("%lu",&sid);
		if (!sid)
		{
			return;
		}
		for (Student* iter=students; iter != studentsp; iter++)
		{
			if (sid==iter->sid)
			{
				printf("Duplicated SID.\n");
				scanf("%*d%*s%*d%*d%*d%*d");
				goto outercontinue;
			}
		}
		studentsp->sid=sid;
		scanf("%d%s",&(studentsp->cid),studentsp->name);
		for (int i = 0; i < 4; ++i)
		{
			scanf("%d",&(studentsp->sc[i]));
		}
		for (int i = 0; i < 4; ++i)
		{
			total+=studentsp->sc[i];
		}
		studentsp->total=total;
		studentsp++;
		outercontinue:;
	}
}

void rm(){
	while(1){
		printf("Please enter SID or name. Enter 0 to finish.\n");
		unsigned long sid;
		char name[11];
		int cnt=0;
		if (scanf("%lu",&sid)==0)
		{
			scanf("%s",name);
			for (Student* iter=students; iter != studentsp; iter++)
			{
				if (iter->sid!=0 && !strcmp(name,iter->name))
				{
					iter->sid=0;
					cnt++;
				}
			}
		}
		else
		{
			if (sid==0)
			{
				return;
			}
			for (Student* iter=students; iter != studentsp; iter++)
			{
				if (iter->sid==sid)
				{
					cnt++;
					iter->sid=0;
					break;
				}
			}
		}
		printf("%d student(s) removed.\n", cnt);
	}
}

int rank(Student& s){
	int ret=1;
	for (Student* iter=students; iter != studentsp; iter++)
	{
		if (iter->sid!=0 && iter->total > s.total)
		{
			ret++;
		}
	}
	return ret;
}

void queryinfo(Student* iter){
	printf("%d %010lu %d %s", rank(*iter), iter->sid, iter->cid, iter->name);
	for (int i = 0; i < 4; ++i)
	{
		printf(" %d", iter->sc[i]);
	}
	printf(" %d %.2f\n", iter->total, iter->total / 4.0 + 1e-5);
}

void query(){
	while(1){
		printf("Please enter SID or name. Enter 0 to finish.\n");
		unsigned long sid;
		char name[11];
		if (scanf("%lu",&sid)==0)
		{
			scanf("%s",name);
			for (Student* iter=students; iter != studentsp; iter++)
			{
				if (iter->sid!=0 && !strcmp(name,iter->name))
				{
					queryinfo(iter);
				}
			}
		}
		else
		{
			if (sid==0)
			{
				return;
			}
			for (Student* iter=students; iter != studentsp; iter++)
			{
				if (iter->sid==sid)
				{
					queryinfo(iter);
				}
			}
		}
	}
}

void rnklist(){
	puts("Showing the ranklist hurts students' self-esteem. Don't do that.");
}

void stat(){
	int cid;
	printf("Please enter class ID, 0 for the whole statistics.\n");
	scanf("%d",&cid);
	int total[4]={0,0,0,0};
	int passed_student[5]={0,0,0,0,0};
	int passed_subject[4][2]={0,0,0,0,0,0,0,0};
	int totals=0;
	for (Student* iter=students; iter != studentsp; iter++)
	{
		if (iter->sid==0)
		{
			continue;
		}
		if (!cid || iter->cid==cid)
		{
			totals++;
			int passed=0;
			for (int i = 0; i < 4; ++i)
			{
				total[i]+=iter->sc[i];
				if (iter->sc[i]<60)
				{
					passed_subject[i][1]++;
				}
				else{
					passed_subject[i][0]++;
					passed++;
				}
			}
			passed_student[passed]++;
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		printf("%s\n", subject_name[i]);
		printf("Average Score: %.2f\n", total[i]/(.0+totals)+1e-5);
		printf("Number of passed students: %d\n", passed_subject[i][0]);
		printf("Number of failed students: %d\n\n", passed_subject[i][1]);
	}
	printf("Overall:\nNumber of students who passed all subjects: %d\nNumber of students who passed 3 or more subjects: %d\nNumber of students who passed 2 or more subjects: %d\nNumber of students who passed 1 or more subjects: %d\nNumber of students who failed all subjects: %d\n\n"
		, passed_student[4], passed_student[3]+passed_student[4], passed_student[2]+passed_student[3]+passed_student[4], passed_student[1]+passed_student[2]+passed_student[3]+passed_student[4], passed_student[0]);
}

using funcptr = void(*)();
funcptr funcs[]={ex,add,rm,query,rnklist,stat};

void mainmenu(){
	puts("Welcome to Student Performance Management System (SPMS).\n\n1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n");
}

int main(){
	while(1){
		mainmenu();
		int n;
		scanf("%d",&n);
		funcs[n]();
	}
}