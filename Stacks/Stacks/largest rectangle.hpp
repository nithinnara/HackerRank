//
//  largest rectangle.hpp
//  Stacks
//
//  Created by Nithin Nara on 17/07/15.
//  Copyright © 2015 Nithin Nara. All rights reserved.
//

#ifndef largest_rectangle_cpp
#define largest_rectangle_cpp

#include <stdio.h>

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


struct DynArrStack {
    int top;
    int capacity;
    int *array;
};

struct DynArrStack *CreateStack(int N) {
    
    struct DynArrStack *S = (struct DynArrStack *) malloc(sizeof(struct DynArrStack));
    if (!S) return NULL;
    S->capacity = N;
    S->top = -1;
    S->array = (int *)  malloc(S->capacity * sizeof(int));
    if (!S->array) return  NULL;
    return S;
}

void updateMaxArea(DynArrStack **S,int hist[],int i);


#endif /* largest_rectangle_cpp */
