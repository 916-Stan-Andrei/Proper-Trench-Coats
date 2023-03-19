#include "Service.h"

void Service::add_coat(std::string size, std::string colour, std::string photograph, float price, int quantity)
{
    TrenchCoat coat = TrenchCoat(size, colour, photograph, price, quantity);
    this->repo.repo_add(coat);
}

void Service::delete_coat(std::string colour)
{
    TrenchCoat coat = TrenchCoat("", colour, "", 0, 0);
    this->repo.repo_delete(coat);
}

void Service::update_coat(std::string new_size, std::string new_photograph, float new_price, int new_quantity, std::string colour)
{
    TrenchCoat coat = TrenchCoat(new_size, colour, new_photograph, new_price, new_quantity);
    this->repo.repo_update(coat);
}

void Service::populate()
{
    add_coat("S", "black","https://www.moja.ro/en/oversized-black-coat", 550.50, 3);
    add_coat("XS", "grey", "https://www.johnlewis.com/kin-parka-coat/p4889500", 750, 1);
    add_coat("XL", "yellow", "https://www.johnlewis.com/hobbs-carmina-straight-coat/p5753903", 150.99, 20);
    add_coat("M", "green", "https://www.johnlewis.com/mango-honolulu-wool-rich-long-pea-green/p6021776", 1000, 1);
    add_coat("XL", "golden", "https://www.goldengoose.com/ca/en/ls/women/clothing/coats-jackets", 2500, 17);
    add_coat("L", "red", "https://www.amazon.com/Womens-Red-Coat/s?k=Women%27s+Red+Coat", 265.75, 19);
    add_coat("L", "orange", "https://www.etsy.com/market/orange_coat", 333, 28);
    add_coat("XS", "purple", "https://www3.next.co.uk/shop/gender-women-productaffiliation-coatsandjackets/colour-purple", 3655.25, 2);
    add_coat("M", "silver", "https://www.nordstrom.com/sr/silver-jacket", 200, 15);
    add_coat("XL", "white", "https://www.medelita.com/lab-coats.html", 25.99, 100);
}


