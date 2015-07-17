//
//  linkedlist.h
//  Programming Abstractions
//
//  Created by Nithin Nara on 17/07/15.
//  Copyright © 2015 Nithin Nara. All rights reserved.
//

#ifndef linkedlist_h
#define linkedlist_h

#include <iostream>

struct Node
{
    int data;
    struct Node *next;
};

struct DllNode
{
    int data;
    DllNode *next;
    DllNode *prev;
};

void Print(Node *head);
void PrintDll(DllNode *head);
Node* InsertHead(Node *head,int data);
Node* InsertTail(Node *head,int data);
Node* InsertNth(Node *head, int data, int position);
Node* Delete(Node *head, int position);
Node* Reverse(Node *head);
void ReversePrint(Node *head);
int CompareLists(Node *headA, Node* headB);
Node* MergeLists(Node *headA, Node* headB);
int GetNode(Node *head,int positionFromTail);
int GetLength(Node *head);
Node* RemoveDuplicates(Node *head);
DllNode* SortedInsert(DllNode *head,int data);
DllNode* DllReverse(DllNode* head);



#endif /* linkedlist_h */
