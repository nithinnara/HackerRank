//
//  Trees.hpp
//  Trees
//
//  Created by Nithin Nara on 21/07/15.
//  Copyright © 2015 Nithin Nara. All rights reserved.
//

#ifndef Trees_cpp
#define Trees_cpp

#include <stdio.h>
#include <iostream>

#define DEFAULT_SIZE 100

struct node
{
    int data;
    node* left;
    node* right;
};

struct DynArrStack {
    int top;
    int capacity;
    struct node** array;
};

struct DynArrStack *CreateStack() {
    
    struct DynArrStack *S = (struct DynArrStack *) malloc(sizeof(struct DynArrStack));
    if (!S) return NULL;
    S->capacity = DEFAULT_SIZE;
    S->top = -1;
    S->array = (struct node**) malloc(S->capacity * sizeof(struct node*));
    if (!S->array) return  NULL;
    return S;
}

struct DynArrQueue {
    int front,rear;
    int capacity;
    struct node** array;
};

struct DynArrQueue *CreateQueue(int N = 1) {
    
    struct DynArrQueue *S = (struct DynArrQueue *) malloc(sizeof(struct DynArrQueue));
    if (!S) return NULL;
    S->capacity = N;
    S->front = S->rear = -1;
    S->array = (struct node**) malloc(S->capacity * sizeof(struct node*));
    if (!S->array) return  NULL;
    return S;
}


#endif /* Trees_cpp */
