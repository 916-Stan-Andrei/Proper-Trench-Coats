#include "TrenchCoat.h"


TrenchCoat::TrenchCoat() : size(""), colour(""), photograph(""), price(0), quantity(0) {}

TrenchCoat::TrenchCoat(const std::string size, const std::string colour, const std::string photograph, const float price, const int quantity)
{
	this->size = size;
	this->colour = colour;
	this->photograph = photograph;
	this->price = price;
	this->quantity = quantity;
}

//TESTS
void test_TrenchCoat()
{
	TrenchCoat c = TrenchCoat("XS", "Yellow", "Maybe not", 100, 15);
	assert(c.get_colour() == "Yellow");
	assert(c.get_photograph() == "Maybe not");
	assert(c.get_price() == 100);
	assert(c.get_quantity() == 15);
	assert(c.get_size() == "XS");
}
