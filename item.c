#include "item.h"
void printt(Item i){
	printf("%.2f C:%5s\tCo:%15s\n",i.price,i.currency,i.country);//C-Currency; Co-Country
}
void freeItem(Item i){
	free(i.currency);
	free(i.country);
}
