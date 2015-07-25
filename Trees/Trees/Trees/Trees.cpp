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


int IsFullQueue(DynArrQueue *Q) {
    return ((Q->rear + 1)%Q->capacity == Q->front);
}

int IsEmptyQueue(DynArrQueue *Q) {
    return (Q->front == -1);
}

int QueueSize(DynArrQueue *Q) {
    return ((Q->capacity - Q->front + Q->rear + 1)% Q->capacity);
}

void ResizeQueue(DynArrQueue *Q)
{
    int size = Q->capacity;
    Q->capacity *= 2;
    Q->array = (struct node **) realloc(Q->array, Q->capacity);
    if (!Q->array) return;
    
    if (Q->front > Q->rear) {
        for (int i=0; i<Q->front; i++) {
            Q->array[i+size] = Q->array[i];
        }
        Q->rear = Q->rear+size;
    }
}

void EnQueue(DynArrQueue *Q,node *data)
{
    if(IsFullQueue(Q))
        ResizeQueue(Q);
    Q->rear = (Q->rear + 1)%Q->capacity;
    Q->array[Q->rear] = data;
    if (Q->front == -1) {
        Q->front = Q->rear;
    }
}

struct node* DeQueue(DynArrQueue *Q)
{
    if (IsEmptyQueue(Q)) {
        return 0;
    }
    
    node *data = nullptr;
    data = Q->array[Q->front];
    if (Q->front == Q->rear)
        Q->front = Q->rear = -1;
    else
        Q->front = (Q->front + 1) % Q->capacity;
    
    return data;
}

void DeleteQueue(DynArrQueue *Q) {
    if (Q) {
        if (Q->array)
            free(Q->array);
        free(Q);
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

void LevelOrder(node * root)
{
    struct node *temp;
    struct DynArrQueue *Q = CreateQueue();
    if (!root) return;
    EnQueue(Q, root);
    
    while (!IsEmptyQueue(Q)) {
        temp = DeQueue(Q);
        printf("%d%s",temp->data," ");
        
        if (temp->left != NULL) {
            EnQueue(Q, temp->left);
        }
        if (temp->right != NULL) {
            EnQueue(Q, temp->right);
        }
    }
    DeleteQueue(Q);
}

node * insert(node * root, int value)
{
    struct node *temp,*newNode;
    newNode = (struct node *) malloc(sizeof(struct node));
    newNode->left = newNode->right = NULL;
    
    struct DynArrQueue *Q = CreateQueue();
    
    if (!root) {
        return root = newNode;
    }
    
    EnQueue(Q, root);
    
    while (!IsEmptyQueue(Q)) {
        temp = DeQueue(Q);
        
        if (temp->left) {
            EnQueue(Q, temp->left);
        }else{
            temp->left = newNode;
            DeleteQueue(Q);
            break;
        }
        if (temp->right) {
            EnQueue(Q, temp->right);
        }else{
            temp->right = newNode;
            DeleteQueue(Q);
            break;
        }
    }
    DeleteQueue(Q);
    return root;
}

void decode_huff(node * root,string s)
{
    struct node *temp;
    temp = root;
    
    char stringArr[s.length()];
    strcpy(stringArr, s.c_str());
    
    int i = 0;
    while (i < sizeof(stringArr)) {
        
        if (stringArr[i] == '1')
            temp = temp->right;
        else if (stringArr[i] == '0')
            temp = temp->left;
        
        if (temp->data != '\0') {
            cout << temp->data;
            temp = root;
        }
        
        i++;
    }
}

node * lca(node * root, int v1,int v2)
{
    if (root == NULL) return root;
    
    if (root->data == v1 || root->data == v2)
        return root;
    
    node *left_lca  = lca(root->left, v1, v2);
    node *right_lca = lca(root->right, v1, v2);
    
    // If both left & right exist, then this node is the LCA
    if (left_lca && right_lca)
        return root;
    
    // Else left or right subtree should be the LCA
    return (left_lca != NULL)? left_lca: right_lca;
}

int main(int argc, const char * argv[]) {
    struct node *tree;
    
    tree = (struct node *) malloc( sizeof(struct node) );
    tree = NULL;
    
    Preorder(tree);
    return 0;
}

