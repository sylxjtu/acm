#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	struct node* next;
	int val;
} Node;

typedef struct list
{
	Node* head;
	int length;
} List;

void insert(List* l, int val){
	l->length++;
	Node* n=l->head,*np=NULL;
	while(n){
		np=n;
		n=n->next;
	}
	if (!np)
	{
		l->head = (Node*)calloc(1,sizeof(Node));
		l->head->val = val;
		return;
	}
	else
	{
		np->next = (Node*)calloc(1,sizeof(Node));
		np->next->val = val;
	}
}

void del(List* l,int index){
	l->length--;
	Node* n=l->head,*tmp;
	if (index==0)
	{
		tmp=l->head;
		l->head=tmp->next;
		free(tmp);
		return;
	}
	for (int i = 0; i < index-1; ++i)
	{
		n = n->next;
	}
	tmp=n->next;
	n->next=tmp->next;
	free(tmp);
}

int find(List*l, int val){
	Node* n=l->head;
	while(n){
		if (n->val==val)
		{
			return 1;
		}
		n=n->next;
	}
	return 0;
}

List li,*l=&li;

int main(void)
{
	int cnt=0;
	char opcode;
	int opreand;
	scanf("%d",&cnt);
	for (int i = 0; i < cnt; ++i)
	{
		scanf(" %c %d",&opcode,&opreand);
		switch(opcode){
			case 'I':
				insert(l,opreand);
				break;
			case 'D':
				del(l,opreand);
				break;
			case 'F':
				printf("%d\n", find(l,opreand));
				break;
		}
	}
	return 0;
}