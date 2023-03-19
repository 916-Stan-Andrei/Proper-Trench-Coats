#pragma once
#include<iostream>
#include <assert.h>

class TrenchCoat {
private:
	std::string size, colour, photograph;
	float price;
	int quantity;
public:
	TrenchCoat();
	TrenchCoat(const std::string size, const std::string colour, const std::string photograph, const float price, const int quantity);

	std::string get_size() const { return size; }
	std::string get_colour() const { return colour; }
	std::string get_photograph() const { return photograph; }
	float get_price() const { return price; }
	int get_quantity() const { return quantity; }
};

void test_TrenchCoat();
