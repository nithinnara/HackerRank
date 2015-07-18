//
//  largest rectangle.cpp
//  Stacks
//
//  Created by Nithin Nara on 17/07/15.
//  Copyright © 2015 Nithin Nara. All rights reserved.
//

#include "largest rectangle.hpp"

using namespace std;

int isFullStack(DynArrStack *S) {
    return (S->top == S->capacity-1);
}

int isEmptyStack(DynArrStack *S) {
    return (S->top == -1);
}

void DoubleStack(DynArrStack *S) {
    S->capacity *= 2;
    S->array = (int *) realloc(S->array, S->capacity);
}

void push(DynArrStack *S,int x)
{
    if(isFullStack(S))
        DoubleStack(S);
    S->array[++S->top] = x;
}

int top(DynArrStack *S)
{
    if (isEmptyStack(S)) {
        return INT_MIN;
    }
    return S->array[S->top];
}

int pop(DynArrStack *S)
{
    if (isEmptyStack(S)) {
        return INT_MIN;
    }
    return S->array[S->top--];
    
}

int area = 0;

int main()
{
    int N,i = 0;
    
    cin >> N;
    int hist[N];
    
    while (scanf("%d", &hist[i++]) != EOF);
    
    DynArrStack *S = CreateStack(N);
    
    i = 0;
    while (i < N)
    {
        // If bar height is > height of bar on top stack then push, else pop
        if (isEmptyStack(S) || hist[top(S)] <= hist[i])
            push(S,i++);
        else
            updateMaxArea(&S, hist,i);
    }
    
    //If the stack is not empty try calculating area with every remaining index in the stack
    while (!isEmptyStack(S))
        updateMaxArea(&S, hist,i);
    
    cout << area;
    
    return area;
    
}

void updateMaxArea(DynArrStack **S,int hist[],int i) {
    
    int topCurr,topPrev;
    int area_with_top;
    
    topCurr = top(*S);
    pop(*S);
    
    topPrev = (isEmptyStack(*S) ? -1 :top(*S));
    
    //rect width is right index (i) - left index (tpPrev) - 1
    area_with_top = hist[topCurr] * (i - topPrev - 1);
    
    if (area < area_with_top)
        area = area_with_top;
    
}


