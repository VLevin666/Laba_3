#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include "item.h"
#include <stdio.h>
#include <stdlib.h>
char filename[100];
struct node{
	struct node* next;
	Item data;
};
typedef struct node Node;
struct list {
	Node* first;
};
typedef struct list List;

void add(List* L, Item* foradd);

void print(List* L);

void findPrice(List* L,int pr);

int deleteFromList(List* L, Item toDelete);

void write2file(List* L);

void findCurrency(List* L,char cu[5]);

void findCountry(List* L,char co[15]);

#endif 
 

