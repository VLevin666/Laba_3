#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
	struct item{
	float price;
	char* country;
	char* currency;
};
typedef struct item Item;

void printt(Item i);

void freeItem(Item i);

#endif 
