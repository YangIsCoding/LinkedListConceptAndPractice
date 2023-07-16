#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Data{
    char *c; // word
    int t;  // word frequency
}Data;

typedef struct Node{
    Data data;  // data field
    struct Node *next; // pointer field
}Node, *pNode;

typedef struct HeadNode{  // head node
    int total_num;
    pNode next;
}HeadNode, *pHeadNode;
// function declaration
void deleteNotA(char str[]);
void insertNoes(pHeadNode head, char str[]);
void showItems(pHeadNode head, FILE *out);

int main(){
    FILE *f_in, *f_out;
    char str[50] = "";
    f_in = fopen("f1.in", "r+");
    f_out = fopen("f1.out", "w+");
    pHeadNode head = (pHeadNode) malloc(sizeof(HeadNode));
    head->total_num = 0;
    head->next = NULL;
    while(fscanf(f_in, "%s", str) != EOF){
        deleteNotA(str);
        //fprintf(f_out, "%s\n", str);
        insertNoes(head, str);
        head->total_num++;
    }

    showItems(head, f_out);
    printf("Total number of words: %d", head->total_num);
    fclose(f_in);
    fclose(f_out);
    return 0;
}

void deleteNotA(char str[]){
    // delete non-character elements
    int length = strlen(str), i, index = 0;
    char *temp = (char *)(malloc(length + 1));
    for(i = 0; i <= length; i++){
        if((str[i] >= 65 && str[i] <= 90) ||( str[i] >= 97 && str[i] <= 122)){
            temp[index++] = str[i];
        }
    }
    temp[index] = '\0';
    strcpy(str, temp);
    return ;
}

void insertNoes(pHeadNode head, char str[]){
    int length = strlen(str);
    //int i;
    static pNode r = NULL; // tail pointer convenient assignment
    pNode p = head->next;
    while(p){ // Check if there are duplicate words
        if(strcmp(p->data.c, str) == 0){
            p->data.t++;
            return ;
        }
        p = p->next;
    }
    // Create a new node
    pNode node = (pNode)malloc(sizeof(Node));
    node->data.c = (char*)malloc(sizeof(char) * length);
    node->data.t = 1;
    node->next = NULL;
    strcpy(node->data.c, str);
    if(!r){
        head->next = node;
    }
    else{
        r->next = node;
    }
    r = node;
    return ;
}

void showItems(pHeadNode head, FILE *out){
    pNode p = head->next;
    while(p){
        fprintf(out, "%s:%d\n", p->data.c, p->data.t);
        printf("%s:%d\n", p->data.c, p->data.t);
        p = p->next;
    }
    fprintf(out, "Total number of words: %d", head->total_num);
}
