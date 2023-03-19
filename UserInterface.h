#pragma once
#include "Service.h"

class UserInterface {
private:
	Service service;
	Service basket;
public:
	UserInterface(const Service s): service(s), basket(s) {}

	void run_app();
	void run_admin();
	void run_user();

private:
	static void print_menu_admin();
	static void print_menu_user();

	void print_all_coats();
	void add_coat_ui();
	void delete_coat_ui();
	void update_coat_ui();

	static void size_menu();
	void add_to_shopping_basket(TrenchCoat coat);
	void print_shopping_basket();

};