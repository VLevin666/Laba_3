#include "function.h"
void findByPrice(List* Basa){
	printf("Price:\n");
	float pr;
	scanf("%f",&pr);
	printf("\n");
	findPrice(Basa,pr);
}
void findByCurrency(List *Basa){///
	printf("Currency:\n");
	char cu[5];
	scanf("%s",cu);
	printf("\n");
	findCurrency(Basa,cu);
}
void findByCountry(List *Basa){///
	printf("Country:\n");
	char co[15];
	scanf("%s",co);
	printf("\n");
	findCountry(Basa,co);
}
void loading(List *Basa){
	printf("File country: (1.txt)\n");
	scanf("%s", filename);
	FILE* f=fopen (filename,"r");
	if (f==NULL){
		printf("ERROR: database corrupted\n");
		exit(0);
	}
	int i,j;
	Basa->first=0;
	float price;
	char currency[5];
	char country[15];
	char x;//simvol iz faila
	while(!feof(f)){
		Item* it=(Item*)malloc(sizeof(Item));
		fscanf(f,"%f",&price);
		if(price<0){
			free(it);
			break;
		}
		it->price=price;
		x=fgetc(f);
		i=0;
		while ((x=fgetc(f))!=':'){
			currency[i]=x;
			i++;
		}
		currency[i]='\0';
		it->currency=(char*)malloc((i+1)*sizeof(char));
		for (j=0;j<=i;j++){
			it->currency[j]=currency[j];
		}
		i=0;
		while ((x=fgetc(f))!='\n'){
			country[i]=x;
			i++;
		}
		country[i]='\0';
		it->country=(char*)malloc((i+1)*sizeof(char));
		for (j=0;j<=i;j++){
			it->country[j]=country[j];
		}
		add(Basa,it);
		free(it);
	}
	fclose(f);
}
void add2basa(List* Basa){
	float price;
	char currency[5];
	char country[15];
	char x;
	Item* it=(Item*)malloc(sizeof(Item));
	int i,j;
	printf("Price: \n");
	scanf("%f",&price);
	it->price=price;
	getchar();
	printf("Currency:\n");
	i=0;
	while ((x=getchar())!='\n'){
		currency[i]=x;
		i++;
	}
	currency[i]='\0';
	it->currency=(char*)malloc((i+1)*sizeof(char));
	for (j=0;j<=i;j++){
		it->currency[j]=currency[j];
	}
	printf("Country:\n");
	i=0;
	while ((x=getchar())!='\n'){
		country[i]=x;
		i++;
	}
	country[i]='\0';
	it->country=(char*)malloc((i+1)*sizeof(char));
	for (j=0;j<=i;j++){
		it->country[j]=country[j];
	}
	add(Basa,it);
	free(it);
}
int deleteFromBasa(List* Basa){
float price;
char currency[5];
char country[15];
char x;
Item* it=(Item*)malloc(sizeof(Item));
int i,j;
printf("Price:\n");
scanf("%f",&price);
it->price=price;
getchar();
printf("Currency:\n");
i=0;
while ((x=getchar())!='\n'){
	currency[i]=x;
	i++;
}
currency[i]='\0';
it->currency=(char*)malloc((i+1)*sizeof(char));
for (j=0;j<=i;j++){
	it->currency[j]=currency[j];
}
printf("Country:\n");
i=0;
while ((x=getchar())!='\n'){
	country[i]=x;
	i++;
}
country[i]='\0';
it->country=(char*)malloc((i+1)*sizeof(char));
for (j=0;j<=i;j++){
	it->country[j]=country[j];
}
return deleteFromList(Basa,*it);
}
void change(List* Basa){
	int result=deleteFromBasa(Basa);
	if (result==1){
		printf("Enter new options\n");
		add2basa(Basa);
	}	
}
