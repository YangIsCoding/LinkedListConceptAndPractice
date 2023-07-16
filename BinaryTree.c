#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	char string[2500];
	struct node *lnode,*rnode;
};
int height(struct node* Node){
	if(Node==NULL){
		return 0;
	}
	int lheight = height(Node->lnode);
	int rheight = height(Node->rnode); 
	if(lheight>rheight){
		return lheight+1;
	}
	else{
		return rheight+1;
	}
}

void printGivLev(struct node* root,int lev){
	if(root==NULL){
		return;
	}
	if(lev==1){
		printf("%s\n",root->string);
	}
	else if(lev>1){
		printGivLev(root->lnode,lev-1);
		printGivLev(root->rnode,lev-1);
	}
}

void PrintLevOrd(struct node *root){
	int h = height(root);
	int i;
	for(i=1;i<=h;i++){
		printGivLev(root,i);
	}	

}

struct node* insert(struct node* T,char *string){
	if(T==NULL){
		struct node*p = (struct node*)malloc(sizeof(struct node));
		strcpy(p->string,string);
		p->lnode = NULL;
		p->rnode = NULL;
		return p;
	}
	if(strcmp(T->string,string)>0){
		T->lnode = insert(T->lnode,string);
	}
	else if(strcmp(T->string,string)<0){
		T->rnode = insert(T->rnode,string);
	}
	return T;
}

int main(){
	char line[2500];
	struct node *root= NULL;
	while(scanf("%s",line)!=EOF){
		root = insert(root,line);
	}
	PrintLevOrd(root);
	
}
