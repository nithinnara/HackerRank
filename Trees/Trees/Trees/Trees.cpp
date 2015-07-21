//
//  Trees.cpp
//  Trees
//
//  Created by Nithin Nara on 21/07/15.
//  Copyright © 2015 Nithin Nara. All rights reserved.
//

#include "Trees.hpp"

void Preorder(node *root);

int isFullStack(DynArrStack *S) {
    return (S->top == S->capacity-1);
}

int isEmptyStack(DynArrStack *S) {
    return (S->top == -1);
}

void DoubleStack(DynArrStack *S) {
    S->capacity *= 2;
    S->array = (struct node **) realloc(S->array, S->capacity);
}

void push(DynArrStack *S,node *x) {
    if(isFullStack(S))
        DoubleStack(S);
    S->array[++S->top] = x;
}

struct node* top(DynArrStack *S) {
    if (isEmptyStack(S)) {
        struct node *tree = nullptr;
        return tree;
    }
    return S->array[S->top];
}

struct node* pop(DynArrStack *S) {
    if (isEmptyStack(S)) {
        struct node *tree = nullptr;
        return tree;
    }
    return S->array[S->top--];
}

void deleteStack(DynArrStack *S) {
    if (S) {
        if (S->array)
            free(S->array);
        free(S);
    }
}

void Preorder(node *root) {
    
    struct DynArrStack * S = CreateStack();
    
    while (1) {
        while (root) {
            printf("%d",root->data);
            printf("%s"," ");
            
            push(S,root);
            root = root->left;
        }
        
        if (isEmptyStack(S))
            break;
        
        root = pop(S);
        root = root->right;
    }
    
    deleteStack(S);
    
    /* Recursive */
    
    /*if(root){
     printf("%d",root->data);
     printf("%s"," ");
     Preorder(root->left);
     Preorder(root->right);
     }*/
    
}

void Postorder(node *root) {
    
    struct DynArrStack * S = CreateStack();
    
    while (1) {
        if(root) {
            push(S,root);
            root = root->left;
        }else{
            if(isEmptyStack(S)) break ;
            else if(top(S)->right == NULL){
                root = pop(S);
                printf("%d",root->data);
                printf("%s"," ");
                if (root == top(S)->right) {
                    printf("%d",top(S)->data);
                    printf("%s"," ");
                    pop(S);
                }
            }
            
            if (!isEmptyStack(S))
                root = top(S)->right;
            else
                root  = NULL;
        }
    }
    
    deleteStack(S);
    /* Recursive */
    
    /*if(root){
        Preorder(root->left);
        Preorder(root->right);
        printf("%d",root->data);
        printf("%s"," ");
     }*/
    
}

void Inorder(node *root) {
    
    struct DynArrStack * S = CreateStack();
    
    while (1) {
        while (root) {
            push(S,root);
            root = root->left;
        }
        
        if (isEmptyStack(S))
            break;
        
        root = pop(S);
        printf("%d",root->data);
        printf("%s"," ");
        root = root->right;
    }
    
    deleteStack(S);

    /* Recursive */
    
    /*if(root){
     Preorder(root->left);
     printf("%d",root->data);
     printf("%s"," ");
     Preorder(root->right);
     }*/
    
}

int height(node * root)
{
    /* Recursive beauty */
    
    if (root == NULL)
        return 0;
    else{
        int leftHeight = height(root->left);
        int rightHeight =  height(root->right);
        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        }
        else{
            return rightHeight + 1;
        }
    }
}

void left_view(node * root);
void right_view(node * root);

void top_view(node * root)
{
    left_view(root);
    right_view(root->right);
}

void left_view(node * root)
{
    if (root == NULL)  return;
    
    left_view(root->left);
    printf("%d%s",root->data," ");
}

void right_view(node * root)
{
    if (root == NULL)  return;
    
    printf("%d%s",root->data," ");
    right_view(root->right);
}

int main(int argc, const char * argv[]) {
    struct node *tree;
    
    tree = (struct node *) malloc( sizeof(struct node) );
    tree = NULL;
    
    Preorder(tree);
    return 0;
}

