#include "function.h"

void Menu::findByPrice(List* Basa) {
	printf("Price:\n");
	float pr;
	std::cin>>pr;
	std::cout<<"\n";
	Basa->findPrice(pr);
}
void Menu::findByCurrency(List* Basa) {
	printf("Currency:\n");
	std::string cu;
	std::cin >> cu;
	printf("\n");
	Basa->findCurrency(cu);
}
void Menu::findByCountry(List* Basa) {
	std::cout << "Country:\n";
	std::string co;
	std::cin >> co;
	std::cout << "\n";
	Basa->findCountry(co);
}
void Menu::loading(List* Basa,std::string filename) {
	std::ifstream file(filename);
	std::string country, currency;
	float price;
	
	if (file.is_open()) {
		if (file.peek() != '\0') {
			while (!file.eof()) {
				file >> price;
				\
				file >> currency;
				file >> country;
				Item* ii = new Item();
				ii->SetPrice(price);
				ii->SetCurrency(currency);\
				ii->SetCountry(country);
				Basa->add(ii);
			}
		}
		file.close();
	}
	else {
		std::cout << "Can't open file " << filename << '\n';
	}
}
void Menu::add2basa(List* Basa) {
	float price;
	std::string currency;
	std::string country;
	Item* it = new Item();
	std::cout << "Price:\n";
	std::cin >> price;
	it->price = price;

	std::cout << "Currency:\n";
	std::cin >> currency;
	it->currency = currency;

	std::cout << "Country:\n";
	std::cin >> country;
	it->country = country;
	Basa->add(it);
	//delete it;
}
void Menu::deleteFromBasa(List* Basa) {

	int ind;
	std::cout << "index element to delete: " << '\n';
	std::cin >> ind;
	Basa->deleteFromList(ind);
}

void Menu::change(List* Basa) {

	int ind;
	std::cout << "index element to change: " << '\n';
	std::cin >> ind;
	Basa->editElement(ind);
}
