#include "UserInterface.h"
#include <windows.h>
#include <iostream>
#include <string>

using namespace std;



void UserInterface::print_menu_admin()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 12);
	cout << "||~~~~~~~~~~ ADMIN MODE ~~~~~~~~~~||" << endl;
	SetConsoleTextAttribute(h, 14);
	cout << "print => Displays all the trench coats available in the store;" << endl;
	cout << "add => The admin can add a new trench coat;" << endl;
	cout << "delete => The admin can delete an existing coat from the database;" << endl;
	cout << "update => The admin can update an existing coat;" << endl;
	cout << "x => Exit the menu." << endl;
	SetConsoleTextAttribute(h, 15);
}

void UserInterface::print_menu_user()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 9);
	cout << "size => Displays the coats having a given size;" << endl;
	cout << "add => Adds the coat to your shopping basket;" << endl;
	cout << "next => Displays the next coat;" << endl;
	cout << "shopping basket => Displays your shopping basket and the total price of the items." << endl;
	cout << "x => Exit the menu." << endl;
	cout << endl;
	SetConsoleTextAttribute(h, 15);
}

//##################### ADMIN MODE ###########################

void UserInterface::print_all_coats()
{
	vector<TrenchCoat> list = this->service.get_all_coats();
	TrenchCoat coat;

	if (list.size() == 0)
		cout << "The store is empty! :<";

	cout << endl;
	for (int i = 0; i < list.size(); i++)
	{
		coat = list.at(i);
		cout << "Size:" << coat.get_size() << "\tColour:" << coat.get_colour() << "\tPhotograph:" << coat.get_photograph() << "\tPrice:" << coat.get_price() << "\tQuantity:" << coat.get_quantity() << endl;
	}
}

void UserInterface::add_coat_ui()
{
	std::string size, colour, photograph, quantity, price;

	cout << "Give the size:";
	getline(cin, size);
	for (char c = '0'; c <= '9'; c++)
		while (size.find(c) != string::npos)
		{
			cout << "The size should contain only letters! Try again:";
			getline(cin, size);
			c = 10;
		}

	cout << "Give the colour:";
	getline(cin, colour);
	for (char c = '0'; c <= '9'; c++)
		while (colour.find(c) != string::npos)
		{
			cout << "The colour should contain only letters! Try again:";
			getline(cin, colour);
			c = 10;
		}

	cout << "Paste the link to the photograph:";
	getline(cin, photograph);
	cout << "Give the price:";
	getline(cin, price);
	while (stoi(price) < 0)
	{
		cout << "The price shuldn't be a negative number! Our premium coats cost money! Try again:";
		getline(cin, price);
	}

	cout << "Give the quantity:";
	getline(cin, quantity);
	while (stoi(quantity) < 0)
	{
		cout << "The quantity shouldn't be a negative number! Try again:";
		getline(cin, quantity);
	}

	this->service.add_coat(size, colour, photograph, stoi(price), stoi(quantity));
	cout << "Coat added successfully!" << endl;
}

void UserInterface::delete_coat_ui()
{
	string colour;

	cout << "Please give the colour:";
	getline(cin, colour);
	for (char c = '0'; c <= '9'; c++)
		while (colour.find(c) != string::npos)
		{
			cout << "The colour should contain only letters! Try again:";
			getline(cin, colour);
			c = 10;
		}
	
	this->service.delete_coat(colour);
	cout << "Coat deleted successfully!" << endl;
}

void UserInterface::update_coat_ui()
{
	string size, colour, photograph, quantity, price;

	cout << "Give the colour of the coat you want to update:";
	getline(cin, colour);
	for (char c = '0'; c <= '9'; c++)
		while (colour.find(c) != string::npos)
		{
			cout << "The colour should contain only letters! Try again:";
			getline(cin, colour);
			c = 10;
		}

	cout << "Give the new size:";
	getline(cin, size);
	for (char c = '0'; c <= '9'; c++)
		while (size.find(c) != string::npos)
		{
			cout << "The size should contain only letters! Try again:";
			getline(cin, size);
			c = 10;
		}

	cout << "Give the new photograph:";
	getline(cin, photograph);

	cout << "Give the price:";
	getline(cin, price);
	while (stoi(price) < 0)
	{
		cout << "The price shuldn't be a negative number! Our premium coats cost money! Try again:";
		getline(cin, price);
	}

	cout << "Give the quantity:";
	getline(cin, quantity);
	while (stoi(quantity) < 0)
	{
		cout << "The quantity shouldn't be a negative number! Try again:";
		getline(cin, quantity);
	}

	this->service.update_coat(size, photograph, stoi(price), stoi(quantity), colour);
	cout << "Coat updated successfully!" << endl;
}


//############################# USER MODE #################################



void UserInterface::size_menu()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 9);
	cout << "next => go to the next sorted item;" << endl;
	cout << "stop => exit this option." << endl;
	SetConsoleTextAttribute(h, 15);
}


void UserInterface::add_to_shopping_basket(TrenchCoat coat)
{
	this->basket.add_coat(coat.get_size(), coat.get_colour(), coat.get_photograph(), coat.get_price(), coat.get_quantity());
}

void UserInterface::print_shopping_basket()
{
	vector<TrenchCoat> list = this->basket.get_all_coats();
	TrenchCoat coat;
	int i;
	for (i = 0; i < list.size(); i++)
	{
		coat = list.at(i);
		cout << "Size:" << coat.get_size() << "\tColour:" << coat.get_colour() << "\tPhotograph:" << coat.get_photograph() << "\tPrice:" << coat.get_price() << "\tQuantity:" << coat.get_quantity() << endl;
	}
}





void UserInterface::run_app()
{
	std::string mode;
	cout << "Please choose the mode (admin/user): ";
	getline(std::cin, mode);

	if (mode == "admin")
		run_admin();
	else if (mode == "user") run_user();
	else cout << "You don't deserve to use my app :/";

}

void UserInterface::run_admin()
{
	std::string option;
	print_menu_admin();
	service.populate();
	int ok = 1;
	while (ok)
	{
		cout << "Please choose an option:";
		getline(std::cin, option);

		if (option == "print")
		{
			print_all_coats();
			cout << endl;
		}
		else if (option == "add")
		{
			add_coat_ui();
			cout << endl;
		}
		else if (option == "delete")
		{
			delete_coat_ui();
			cout << endl;
		}
		else if (option == "update")
		{
			update_coat_ui();
			cout << endl;
		}
		else if (option == "x")
			ok = 0;
		else std::cout << "Wrong input!" << endl;
	}
}

void UserInterface::run_user()
{
	service.populate();
	vector<TrenchCoat> list = this->service.get_all_coats();
	TrenchCoat coat;

	if (list.size() == 0)
		cout << "The store is empty! :<" << endl;

	std::string size;
	std::string option;
	float totalsum = 0;
	int ok = 1, i = 0, j = 0;
	coat = list.at(i);
	cout << "Size:" << coat.get_size() << "\tColour:" << coat.get_colour() << "\tPhotograph:" << coat.get_photograph() << "\tPrice:" << coat.get_price() << "\tQuantity:" << coat.get_quantity() << endl;
	while (ok)
	{
		print_menu_user();
		cout << "Please choose an option:";
		getline(std::cin, option);
		if (option == "size")
		{
			cout << "Please give a size:";
			getline(std::cin, size);
			if (size == "empty")
				for (j = 0; j < list.size(); j++)
				{
					coat = list.at(j);
					cout << "Size:" << coat.get_size() << "\tColour:" << coat.get_colour() << "\tPhotograph:" << coat.get_photograph() << "\tPrice:" << coat.get_price() << "\tQuantity:" << coat.get_quantity() << endl;
					size_menu();
					cout << "Please choose an option:";
					getline(std::cin, option);
					if (option == "stop")
						break;
				}
			else {
				for (j = 0; j < list.size(); j++)
				{
					coat = list.at(j);
					if (size == coat.get_size())
					{
						cout << "Size:" << coat.get_size() << "\tColour:" << coat.get_colour() << "\tPhotograph:" << coat.get_photograph() << "\tPrice:" << coat.get_price() << "\tQuantity:" << coat.get_quantity() << endl;
						size_menu();
						cout << "Please choose an option:";
						getline(std::cin, option);
						if (option == "stop")
							break;
					}
				}
			}
		}	
		else if (option == "add")
		{
			coat = list.at(i);
			add_to_shopping_basket(coat);
			totalsum += coat.get_price();
			cout << "Totalsum:" << totalsum << endl;
		}
		else if (option == "next")
		{
			i++;
			coat = list.at(i);
			cout << "Size:" << coat.get_size() << "\tColour:" << coat.get_colour() << "\tPhotograph:" << coat.get_photograph() << "\tPrice:" << coat.get_price() << "\tQuantity:" << coat.get_quantity() << endl;
		}
		else if (option == "shopping basket")
		{
			cout << endl;
			print_shopping_basket();
			cout << "Totalsum:" << totalsum << endl;
		}
		else if (option == "x")
			ok = 0;
		else std::cout << "Wrong input!" << endl;

		if (i == list.size())
			i = 0;
	}
}
