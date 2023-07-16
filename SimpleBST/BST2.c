#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct Node{
	char string[100];
	struct Node* left;
	struct Node* right;
};

struct Node* GetNewNode(char *string){
	struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
	strcpy(newNode->string,string);
	newNode->left = newNode->right=NULL;
	return newNode; 
}


struct Node* Insert(struct Node* root, char *string){
	if(root==NULL){
		root = GetNewNode(string);
		return root;
	}
    	
	else if(strcmp(string,root->string )<0){
		root->left = Insert(root->left,string);
	}
	else if(strcmp(string,root->string )>0){
		root->right = Insert(root->right,string);
	}
	return root;
}
void printPreorder(struct Node* Node)
{
    if (Node == NULL)
        return;
    printf("%s\n", Node->string);
    printPreorder(Node->left);
    printPreorder(Node->right);
}
void printPostorder(struct Node* Node)
{
    if (Node == NULL)
        return;
    printPostorder(Node->left);
    printPostorder(Node->right);
    printf("%s\n", Node->string);
}
 
void printInorder(struct Node* Node)
{
    if (Node == NULL)
        return;
    printInorder(Node->left);
    printf("%s\n", Node->string);
    printInorder(Node->right);
}
int main(int argc,char **argv){
	
	struct Node* root=NULL;
	char line[1000];
	char text[1000][1000];
	int cnt=0;

	while(scanf("%s",line)!=EOF){
		strcpy(text[cnt],line);
		cnt++;
	}
		
	for(int i=0;i<cnt;i++){
		root = Insert(root,text[i]);
	}
	if(argv[1][1]=='p'){
//		printf("\nPreorder traversal of binary tree is \n");
		printPreorder(root);
	}
	else if(argv[1][1]=='i'){
//		printf("\nInorder traversal of binary tree is \n");
    		printInorder(root);
	}
	else if(argv[1][1]=='P'){
 //  		printf("\nPostorder traversal of binary tree is \n");
    		printPostorder(root);
	}
	else return 0;
}
