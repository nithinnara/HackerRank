//
//  main.cpp
//  Programming Abstractions
//
//  Created by Nithin Nara on 12/07/15.
//  Copyright © 2015 Nithin Nara. All rights reserved.
//

#include "linkedlist.h"

using namespace std;

int main(int argc, const char * argv[]) {
    struct Node *linkedlist,*linkedlist2;
    struct DllNode *doublylinkedlist;
    
    linkedlist = (struct Node *) malloc( sizeof(struct Node) );
    linkedlist = NULL;
    
    doublylinkedlist = (struct DllNode *) malloc( sizeof(struct DllNode) );
    doublylinkedlist = NULL;
    
    linkedlist = InsertTail(linkedlist,10);
    linkedlist = InsertTail(linkedlist,12);
    linkedlist = InsertTail(linkedlist,12);
    linkedlist = InsertTail(linkedlist,12);
    linkedlist = InsertTail(linkedlist,12);
    linkedlist = InsertTail(linkedlist,13);
    linkedlist = InsertTail(linkedlist,13);
    
    // Print(linkedlist);
    
    linkedlist2 = InsertHead(linkedlist2,10);
    linkedlist2 = InsertHead(linkedlist2,12);
    linkedlist2 = InsertHead(linkedlist2,13);
    // Print(linkedlist);
    
    linkedlist = InsertNth(linkedlist,1,0);
    linkedlist = InsertNth(linkedlist,2,3);
    linkedlist = InsertNth(linkedlist,3,2);
    //Print(linkedlist);
    
    linkedlist = Delete(linkedlist,0);
    linkedlist = Delete(linkedlist,1);
    linkedlist = Delete(linkedlist,2);
    //Print(linkedlist);
    
    //ReversePrint(linkedlist);
    
    linkedlist = Reverse(linkedlist);
    // Print(linkedlist);
    
    int boolean = CompareLists(linkedlist, linkedlist);
    cout << boolean;
    
    //    linkedlist = MergeLists(linkedlist, linkedlist2);
    //  Print(linkedlist);
    
    //cout << GetNode(linkedlist, 0);
    linkedlist = RemoveDuplicates(linkedlist);
    //Print(linkedlist);
    
    doublylinkedlist = (SortedInsert(doublylinkedlist, 10));
    doublylinkedlist = (SortedInsert(doublylinkedlist, 7));
    doublylinkedlist = (SortedInsert(doublylinkedlist, 11));
    // PrintDll(doublylinkedlist);
    
    doublylinkedlist = DllReverse(doublylinkedlist);
    PrintDll(DllReverse(doublylinkedlist));
    
    return 0;
}

void Print(Node *head)
{
    while(head != NULL) {
        cout << head->data << "\n";
        head = head->next;
    }
}
void PrintDll(DllNode *head)
{
    while(head != NULL) {
        cout << head->data << "\n";
        head = head->next;
    }
}

Node* InsertTail(Node *head,int data)
{
    struct Node *newNode,*p;
    newNode = (struct Node *) malloc( sizeof(struct Node) );
    newNode->data = data;
    newNode->next = NULL;
    p = head;
    
    if(head == NULL){
        head = newNode;
        return head;
    }
    
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
    return head;
}

Node* InsertHead(Node *head,int data)
{
    struct Node *newNode;
    newNode = (struct Node *) malloc( sizeof(struct Node) );
    newNode->data = data;
    newNode->next = NULL;
    
    if(head == NULL){
        head = newNode;
        return head;
    }else {
        newNode->next = head;
        head = newNode;
    }
    
    return head;
}

Node* InsertNth(Node *head, int data, int position)
{
    struct Node *newNode,*p,*q = nullptr;
    newNode = (struct Node *) malloc( sizeof(struct Node) );
    newNode->data = data;
    p = head;
    int k =0;
    
    if(position == 0){
        newNode->next = head;
        head = newNode;
        return head;
    }else{
        while(p != NULL && k <= (position -1)) {
            q = p;
            p = p->next;
            k++;
        }
        if(p != NULL){
            q->next = newNode;
            newNode->next = p;
        }else{
            q->next = newNode;
            newNode->next = NULL;
        }
    }
    return head;
}

Node* Delete(Node *head, int position)
{
    struct Node *p,*q = nullptr;
    
    p = head;
    int k =0;
    
    if(position == 0){
        p = head;
        head = head->next;
        free(p);
        return head;
    }else{
        while(p != NULL && k <= (position -1)) {
            q = p;
            p = p->next;
            k++;
        }
        if(p != NULL){
            q->next = p->next;
            free(p);
        }else{
            q->next = NULL;
            free(p);
        }
    }
    return head;
}

void ReversePrint(Node *head)
{
    if(head != NULL) {
        ReversePrint(head->next);
        cout << head->data << "\n";
    }
}

Node* Reverse(Node *head)
{
    struct Node *p = nullptr,*q = nullptr;
    
    while (head != NULL) {
        p = head->next;
        head->next = q;
        q = head;
        head = p;
    }
    return q;
}

int CompareLists(Node *headA, Node* headB)
{
    while (headA != NULL) {
        if (headA->data != headB->data) {
            return 0;
        }
        headA = headA->next;
        headB = headB->next;
    }
    if (headB == NULL && headA == NULL) return 1;
    return 0;
    
}

Node* MergeLists(Node *headA, Node* headB)
{
    /* Recursion
     struct Node* result = NULL;
     
     if (headA == NULL)
     return(headB);
     else if (headB==NULL)
     return(headA);
     
     if (headA->data <= headB->data)
     {
     result = headA;
     result->next = MergeLists(headA->next, headB);
     }
     else
     {
     result = headB;
     result->next = MergeLists(headA, headB->next);
     }
     return result;
     */
    
    struct Node* merged = NULL;
    Node** tail = &merged;
    
    while (headA != NULL && headB != NULL) {
        if (headA->data < headB->data) {
            *tail = headB;
            headA = headA->next;
        } else {
            *tail = headB;
            headB = headB->next;
        }
        tail = &((*tail)->next);
    }
    *tail = headA ? headA : headB;
    return merged;
    
}

int GetNode(Node *head,int positionFromTail)
{
    int count  = GetLength(head);
    int i = 0;
    while (i < count-positionFromTail) {
        if (i == count-positionFromTail-1) {
            return head->data;
        }
        head = head->next;
        i++;
    }
    return 0;
}

int GetLength(Node *head)
{
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

Node* RemoveDuplicates(Node *head)
{
    struct Node *p = head,*q = nullptr;
    q = p;
    p = p->next;
    while (p) {
        if (p->data == q->data) {
            q->next = p->next;
            free(p);
            p = q;
        }
        q = p;
        p = p->next;
    }
    return head;
}

int HasCycle(Node* head)
{
    struct Node *fastptr = head,*slowptr = head;
    
    while (slowptr) {
        fastptr = fastptr->next;
        if (fastptr == slowptr) {
            return 1;
        }
        fastptr = fastptr->next;
        if (fastptr == slowptr) {
            return 1;
        }
        slowptr = slowptr->next;
    }
    return 0;
}

int FindMergeNode(Node *headA, Node *headB)
{
    
    struct Node *ptr = headB,*temp = headA;
    
    int countA = GetLength(headA);
    int countB = GetLength(headB);
    int  i =0;
    
    int diff  = countA-countB;
    
    if (diff > 0) ptr = headA;temp = headB;
    
    while (i < abs(diff)) {
        ptr = ptr -> next;
        i++;
    }
    
    while (temp && ptr) {
        if (temp == ptr) {
            return temp->data;
        }
    }
    
    free(temp);
    free(ptr);
    return 0;
}

DllNode* SortedInsert(DllNode *head,int data)
{
    struct DllNode *newNode,*temp,*p = nullptr;
    newNode = (struct DllNode *) malloc(sizeof(struct DllNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    temp = head;
    
    
    if(!head){
        return newNode;
    }
    while(temp!=NULL && (data>=(temp->data))){
        p=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        p->next=newNode;
        newNode->prev=p;
        return head;
    }
    if(p==NULL){
        head->prev=newNode;
        newNode->next=head;
        return newNode;
    }
    p->next=newNode;
    newNode->prev=p;
    newNode->next=temp;
    temp->prev=newNode;
    return head;
}

DllNode* DllReverse(DllNode* head)
{
    struct DllNode *curptr,*temp;
    curptr = head;
    
    if(head==NULL) return NULL;
    
    while (curptr->next != NULL) {
        temp = curptr->next;
        curptr->next = curptr->prev;
        curptr->prev = temp;
        curptr = curptr->prev;
    }
    
    curptr->next = curptr->prev; //Last node
    curptr->prev = NULL;
    return curptr;
}

