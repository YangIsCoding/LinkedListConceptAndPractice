#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
	char name[1000];
	int hw1;
	int hw2;
	int hw3;
	int hw4;
	int hw5;
	int total;
	struct Node* next;
};
struct Node* head;



void Insert(char *name,int hw1,int hw2,int hw3,int hw4,int hw5){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	strcpy(temp->name,name);
	temp->hw1 = hw1;
	temp->hw2 = hw2;
	temp->hw3 = hw3;
	temp->hw4 = hw4;
	temp->hw5 = hw5;
	temp->total = hw1+hw2+hw3+hw4+hw5;
	temp->next= head;
	head = temp; 

}

void Print(){
	struct Node* temp = head;
	while(temp != NULL){
		printf("%s\t",temp->name);
		printf("%d\t",temp->hw1);
		printf("%d\t",temp->hw2);
		printf("%d\t",temp->hw3);
		printf("%d\t",temp->hw4);
		printf("%d\n",temp->hw5);
		temp = temp->next; 
	}
}

void swap(int *a,int *b){
	int temp;
	temp = *a;
	*a=*b;
	*b=temp;
}

void swapn(char *name1,char *name2){
	char temp[1000];
	strcpy(temp,name1);
	strcpy(name1,name2);
	strcpy(name2,temp);
}

void Sort(){
	struct Node *i,*j;
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	for(i=head;i->next!=NULL;i=i->next){
		for(j=i->next;j!=NULL;j=j->next){
			if(i->total < j->total){
				
				swapn(i->name,j->name);	
			
				swap(&(i->hw1),&(j->hw1));
				swap(&(i->hw2),&(j->hw2));
				swap(&(i->hw3),&(j->hw3));
				swap(&(i->hw4),&(j->hw4));
				swap(&(i->hw5),&(j->hw5));
				swap(&(i->total),&(j->total));
			}
		}
	}
}

int main(){

	char line[1024];
	head = NULL;  //empty
	char name[1000];
	int hw1;
	int hw2;
	int hw3;
	int hw4;
	int hw5;
	
	while(scanf("%s%d%d%d%d%d",name,&hw1,&hw2,&hw3,&hw4,&hw5)!=EOF){
		Insert(name,hw1,hw2,hw3,hw4,hw5);
	}
	Sort();
	Print();
	

}
