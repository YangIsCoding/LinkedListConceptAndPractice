#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node{
	char word[1000];
	int cnt;
	struct Node* next;
};

struct Node *Search(struct Node head,char *line){
        struct Node *f;
        f = head.next;
        while(f!=NULL && strcmp(f->word,line)!=0){
                f = f->next;
        }
        return f;
}

struct Node *insert(char *line){
        struct Node *l;
        l = (struct Node *)malloc(sizeof(struct Node));
        char *ptr = line;
        char *qtr = l->word;
        while(*ptr){
                *qtr++ = *ptr++;
        }

        l->cnt = 1;
        l->next = NULL;
        return l;
}

void refresh(char *line){
	char *ptr = line;
	for(int i=0;i<strlen(line);i++){
		if(*(ptr+i)=='\n'){
			*(ptr+i)='\0';
		}
	}
}

int main(){
	int firstNode = 1;
	struct Node *head = NULL;
	struct Node *last = NULL;
	struct Node *find;
	char line[1024];
	char *ptr;

	while(fgets(line,1024,stdin)){
		refresh(line);
		ptr = line;
		if(*ptr != '-'){
			if(firstNode){
				head = insert(ptr);
				last = head;
				firstNode = 0;
			}
			else if(!firstNode){
				if(strcmp(head->word,ptr)==0){
					head->cnt = head->cnt+1;
				}
				else if(find = Search(*head,ptr)){
					find->cnt = find->cnt+1;
				}
				else{
					last->next= insert(ptr);
					last = last->next; 
				}
			}
		}
		else{
			ptr++;
			if(strcmp(head->word,ptr)==0){
				head->cnt--;
			}
			else{
				find = Search(*head,ptr);
				find->cnt--;
			}
		}		
	}
	while(head){
			printf("%s: %d\n",head->word,head->cnt);
			head = head->next;
	}

}
