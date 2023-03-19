#pragma once
#include "Repo.h"

class Service {
private:
	Repository repo;
public:
	explicit Service(const Repository repository) : repo(repository) {}

	Repository get_repo() const { return repo; }

	void add_coat(std::string size, std::string colour, std::string photograph, float price, int quantity);
	void delete_coat(std::string colour);
	void update_coat(std::string new_size, std::string new_photograph, float new_price, int new_quantity, std::string colour);

	vector<TrenchCoat> get_all_coats() const { return this->repo.get_TrenchCoats(); }
	void populate();
};
