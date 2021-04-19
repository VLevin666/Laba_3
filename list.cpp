#include "list.h"
void List::add(Item* foradd) {
	if (first == 0) {
		first = new Node();
		first->data = *foradd;
		first->next = 0;
	}
	else {
		Node* tmp = first;
		while (tmp->next != 0) {
			tmp = tmp->next;
		}
		tmp->next = new Node();
		tmp->next->data = *foradd;
		tmp->next->next = 0;
	}
}
void List::print() {
	Node* tmp = first;
	while (tmp != 0) {
		tmp->data.printt();
		tmp = tmp->next;
	}
}
void  List::findPrice(float pr) {
	Node* tmp = first;
	int k = 0;
	while (tmp != 0) {
		if (tmp->data.price == pr) {
			tmp->data.printt();
			k = 1;
		}
		tmp = tmp->next;
	}
	if (k == 0) {
		std::cout << "No such rate\n";
	}
}
void List::deleteFromList(int ind) {

	if (ind == 0) {
		if (first->next)
			first = first->next;
		else
		first = NULL;
		return;
	}

	Node* elem = NULL, * tmp = first;
	int i = 0;
	while (tmp != NULL) {
		if (i == ind-1) {
			elem = tmp;
			break;
		}
		tmp = tmp->next;
		i++;
	}


	if (elem == NULL) return;

	Node* elem2 = elem->next;
	if(elem->next)
	elem->next = elem2->next;

	delete elem2;
}
void  List::write2file(std::string filename) {
	std::ofstream out(filename);
	if (out.is_open()){
		Node* tmp = first;
		while (tmp != 0) {
			out<<tmp->data.price<<'\n'<<tmp->data.currency << '\n' <<tmp->data.country << '\n';
			tmp = tmp->next;
		}
	}
	else {
		std::cout << "Can't open file " << filename << '\n';
	}
	out.close();
}
void  List::findCurrency(std::string cu) {///
	Node* tmp = first;
	int k = 0;
	while (tmp != 0) {
		if (tmp->data.currency == cu) {
			tmp->data.printt();
			k = 1;
		}
		tmp = tmp->next;
	}
	if (k == 0) {
		std::cout << "No such rate\n";
	}
}
void  List::findCountry(std::string co) {///
	Node* tmp = first;
	int k = 0;
	while (tmp != 0) {
		if (tmp->data.country == co) {
			tmp->data.printt();
			k = 1;
		}
		tmp = tmp->next;
	}
	if (k == 0) {
		std::cout<<"No such rate\n";
	}
}
void List::editElement(int ind) {
	Node* elem = NULL, * tmp = first;
	int i = 0;
	while (tmp != NULL) {
		if (i == ind) {
			elem = tmp;
			break;
		}
		tmp = tmp->next;
		i++;
	}


	float price;
	std::string currency;
	std::string country;
	std::cout << "Price:\n";
	std::cin >> price;
	elem->data.price = price;

	std::cout << "Currency:\n";
	std::cin >> currency;
	elem->data.currency = currency;

	std::cout << "Country:\n";
	std::cin >> country;
	elem->data.country = country;
}
