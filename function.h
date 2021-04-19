
#include <iostream>
#include "list.h"
class Menu {
public:
	void findByPrice(List* Basa);

	void findByCurrency(List* Basa);

	void findByCountry(List* Basa);

	void add2basa(List* Basa);

	void deleteFromBasa(List* Basa);

	void loading(List* L, std::string filename);

	void change(List* Basa);
};

