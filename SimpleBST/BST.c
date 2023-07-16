// C program for different tree traversals
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node {
    //int data;
    char string[100];
    struct node* left;
    struct node* right;
};
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(char *string)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    strcpy(node->string,string);
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
 
/* Given a binary tree, print its nodes according to the
  "bottom-up" postorder traversal. */
void printPostorder(struct node* node)
{
    if (node == NULL)
        return;
 
    // first recur on left subtree
    printPostorder(node->left);
 
    // then recur on right subtree
    printPostorder(node->right);
 
    // now deal with the node
    printf("%s ", node->string);
}
 
/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    printf("%s ", node->string);
 
    /* now recur on right child */
    printInorder(node->right);
}
 
/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct node* node)
{
    if (node == NULL)
        return;
 
    /* first print data of node */
    printf("%s ", node->string);
 
    /* then recur on left sutree */
    printPreorder(node->left);
 
    /* now recur on right subtree */
    printPreorder(node->right);
}
 
/* Driver program to test above functions*/
int main()
{
    struct node* root = newNode("banana");
    root->left = newNode("apple");
    root->right = newNode("candy");
    root->left->left = newNode("binary");
   // root->left->right = newNode("e");
 
    printf("\nPreorder traversal of binary tree is \n");
    printPreorder(root);
 
    printf("\nInorder traversal of binary tree is \n");
    printInorder(root);
 
    printf("\nPostorder traversal of binary tree is \n");
    printPostorder(root);
 
    getchar();
    return 0;
}
