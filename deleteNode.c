#include <strdin.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct Node{
	char *key;
	//char key[1024];
	struct Node *next;
};

struct Node *Insert(struct Lnode *head,char *key){
	struct Node *p;
	p=(struct Node *)malloc(sizeof(struct Node));
	p->key = strdup(key);
	if(head){
		p->next = head->next;
	}
	else{
		p->next = NULL;
	}
	return p;
}

struct Node *Delete(struct Node *head,char *key){
	struct Node *p,*prevOne;
	p=head;
	prevOne = p;
	while(p){
		if(strcmp(p->key,key)==0){
			if(p==head){
				prevOne = p->next;
				free(p->key);free(p);
				return last;
			}
			prevOne->next = p->next;
			free(p->key);
			free(p);
			return head;
		}
		prevOne = p;
		p = p->next;
	}
	return head;
}

int main(){
	struct Node *head;

		
	
	
}
