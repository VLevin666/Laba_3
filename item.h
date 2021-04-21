#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include<iostream>
class Item {
public:
	float price;
	std::string country;
	std::string currency;
	friend std::ostream& operator<< (std::ostream& out, const Item& item){
		out <<item.price << "    Co:    " << item.country << "    C:    " << item.currency << '\n';
		return out;
	}

	friend std::istream& operator>> (std::istream& is, Item& item){
		is >> item.price >> item.country >> item.currency;
		return is;
	}

	void SetPrice(float p) {
		this->price = p;
	}
	float GetPrice() {
		return this->price;
	}
	void SetCurrency(std::string p) {
		this->currency = p;
	}
	std::string GetCurrency() {
		return this->currency;
	}
	void SetCountry(std::string p) {
		this->country = p;
	}
	std::string GetCountry() {
		return this->country;
	}
	void printt();


};


#endif 
