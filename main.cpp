#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include "list.h"
#include "function.h"
using namespace std;
int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "Error: provide database filename\n";
		return 1;
	}
	List* Basa = new List();

	Menu menu;
	menu.loading(Basa, argv[1]);
	std::cout << "Currency exchange rate database\n";
	getchar();
	char number = 0;
	char musor;
	while (number != '8') {
		cout<<"\n";
		cout << " Main Menu\n";
		cout << "1) view all rate \n";
		cout << "2) show all rate by country \n";
		cout << "3) show all rate by price \n";
		cout << "4) show all rate by currency \n";
		cout << "5) add rate \n";
		cout << "6) delete rate \n";
		cout << "7) edit rate \n";
		cout << "8) exit \n";
		cout << "\n";
		cout << "Enter one symbol from 1 to 8:\n";
		cin >> number;
		switch (number) {
		case '1':
			Basa->print();
			break;
		case '2':
			menu.findByCountry(Basa);
			break;
		case '3':
			menu.findByPrice(Basa);
			break;
		case '4':
			menu.findByCurrency(Basa);
			break;
		case '5':
			menu.add2basa(Basa);
			break;
		case '6':
			menu.deleteFromBasa(Basa);
			break;
		case '7':
			menu.change(Basa);
			break;
		case '8':
			break;
		default:
			cout << "Choose a number from 1 to 8";
		}
	}
	Basa->write2file(argv[1]);
	delete Basa;
	return 0;
}
