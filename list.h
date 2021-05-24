#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include "item.h"
#include <iostream>
#include<string>
#include<fstream>
class Node {
public:
	Node* next;
	Item data;
};
class List {
public:
	Node* first;
	void add(Item* foradd);

	void print();

	void findPrice(float pr);

	void deleteFromList(int ind);

	void write2file(std::string filename);

	void findCurrency(std::string cu);

	void findCountry(std::string co);

	void editElement(int ind);
	
	~List(){
		delete first;
	}	
		

};

#endif 
