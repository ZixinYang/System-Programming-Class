#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "phonebook_opt.h"

entry *findName(char lastName[], entry *pHead)
{
    if (pHead != NULL){
        if(strcmp(lastName, pHead->lastName) == 0) return pHead;
        else if (strcmp(lastName, pHead->lastName) < 0) return findName(lastName, pHead->pLeft);
        else { return findName(lastName, pHead->pRight); }
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    if(strcmp(e->lastName, "")==0 && !e->pRight){strcpy(e->lastName, lastName); return e;}
    
    entry *current;
    current = e;
    entry *ptr;
    
    while(current != NULL){
        if(strcmp(lastName, current->lastName)==0){
            return e;
        }
        else if(strcmp(lastName, current->lastName)<0){
            ptr = current; current = current->pLeft;
        }
        else{
            ptr = current; current = current->pRight;
        }
    }
    entry *Node = (entry *)malloc(sizeof(entry));
    strcpy(Node->lastName, lastName);
    Node->pLeft = NULL;
    Node->pRight = NULL;
    if(strcmp(lastName, ptr->lastName)<0){
        ptr->pLeft = Node;
    }
    else{
        ptr->pRight = Node;
    }
    return e;
}
