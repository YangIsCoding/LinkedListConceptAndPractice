#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  MaxLine  1000
struct lnode
{
	char *key;
	struct lnode *next;
};

struct lnode *insert_front(struct lnode *L,char *key)
{
	struct lnode *p;
	p=(struct lnode *)malloc(sizeof(struct lnode));
	p->key = strdup(key);	//小心memory leaking,free lnode之前free(p->key)
	p->next = L;
	return p;
};

struct lnode *l_find(struct lnode *L,char *key)
{
	struct lnode *p;
	p=L;
	while(p)
	{
		if(strcmp(p->key,key)==0)
		{
			return p;
		}		
		p = p->next;
	}
	return NULL;
};

void traverse_print(struct lnode *L)
{
	struct lnode *p=L;
	while(p)
	{
		printf("%s",p->key);
		p = p->next;
	}	
}

int main()
{
	char	line[MaxLine];
	struct	lnode	*keyList;
	keyList = NULL;
	while(fgets(line,MaxLine,stdin))
	{
		if(l_find(keyList,line)==NULL)
		{
			keyList = insert_front(keyList,line);
		}
	}
	traverse_print(keyList);
}
