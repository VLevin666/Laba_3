#include "util.h"
#include "list.h"
void add(List *L,Item *foradd){
	if (L->first==0){
		L->first=(Node*)malloc(sizeof (Node));
		L->first->data = *foradd;
		L->first->next=0;
	}
	else{
		Node *tmp=L->first;
		while(tmp->next!=0){
			tmp=tmp->next;
		}
		tmp->next=(Node*)malloc(sizeof (Node));
		tmp->next->data = *foradd;
		tmp->next->next=0;
	}
}
void print(List *L){
	Node *tmp=L->first;
	while (tmp!=0){
		printt(tmp->data);
		tmp=tmp->next;
	}
}
void findPrice(List* L,int pr){
	Node *tmp=L->first;
	int k=0;
	while (tmp!=0){
		if (tmp->data.price==pr){
			printt(tmp->data);
			k=1;
		}
		tmp=tmp->next;
	}
	if (k==0){
		printf("No such rate\n");
	}
}
int deleteFromList(List* L, Item toDelete){
	Node *tmp=L->first;
	if (tmp->data.price==toDelete.price &&
	stringCompare(tmp->data.currency, toDelete.currency )==0 &&
	stringCompare(tmp->data.country, toDelete.country )==0 ){
		Node *remove = L->first;
		L->first = L->first->next;
		freeItem(remove->data);
		free(remove);
		return 1;
	}
	Node *prev=tmp;
	tmp = prev->next;
	while (tmp!=0){
		if (tmp->data.price==toDelete.price &&
		stringCompare(tmp->data.currency, toDelete.currency)==0 &&
		stringCompare(tmp->data.country, toDelete.country)==0 ){
			Node *remove = tmp;
			prev->next = tmp->next;
			freeItem(remove->data);
			free(remove);
			return 1;

		}
		prev = tmp;
		tmp =prev->next;
	}
	printf("No such rate\n");
	return 0;
}
void write2file(List* L){
	FILE* f=fopen(filename,"w");
	Node *tmp=L->first;
	while (tmp!=0){
		fprintf (f,"%.2f:%s:%s\n",tmp->data.price,tmp->data.currency,tmp->data.country);
		tmp=tmp->next;
	}
	fprintf(f,"-1");
	fclose(f);
}
void findCurrency(List* L,char cu[5]){///
	Node *tmp=L->first;
	int k=0;
	while (tmp!=0){
		if (stringCompare(tmp->data.currency,cu)==0){
			printt(tmp->data);
			k=1;
		}
	tmp=tmp->next;
	}
	if (k==0){
		printf("No such rate\n");
	}
}
void findCountry(List* L,char co[15]){///
	Node *tmp=L->first;
	int k=0;
	while (tmp!=0){
		if (stringCompare(tmp->data.country ,co)==0){
		printt(tmp->data);
		k=1;
		}
		tmp=tmp->next;
	}
	if (k==0){
		printf("No such rate\n");
	}
}
