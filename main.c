#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "function.h"
int main(){
	/// "1.txt"
	List* Basa=(List*)malloc(sizeof(List));
	loading(Basa);
	printf ("Currency exchange rate database\n");
	getchar();
	char number=0;
	char musor;
	while (number!='8'){
		printf("\n");
		printf(" Main Menu\n");
		printf("1) view all rate \n");
		printf("2) show all rate by country \n");
		printf("3) show all rate by price \n");
		printf("4) show all rate by currency \n");
		printf("5) add rate \n");
		printf("6) delete rate \n");
		printf("7) edit rate \n");
		printf("8) exit \n");
		printf("\n");
		printf("Enter one symbol from 1 to 8:\n");
		while((number=getchar())=='\n'){///
		}
		musor=getchar();
		switch (number){
		case '1':
		print(Basa);
		break;
		case '2':
		findByCountry(Basa);
		break;
		case '3':
		findByPrice(Basa); 
		break;
		case '4':
		findByCurrency(Basa);
		break;
		case '5':
		add2basa(Basa);
		break;
		case '6':
		deleteFromBasa(Basa);
		break;
		case '7':
		change(Basa);
		break;
		case '8':
		break;
		default:
		printf("Choose a number from 1 to 8");
		}	
	}
	write2file(Basa);
	free(Basa);
	return 0;
}
