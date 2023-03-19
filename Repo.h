#pragma once
#include "TrenchCoat.h"
#include <vector>

using namespace std;


class Repository {
private:
	vector <TrenchCoat> coats;
public:
	Repository() {};

	void repo_add(const TrenchCoat coat);

	void repo_delete(const TrenchCoat coat);

	void repo_update(const TrenchCoat coat);

	vector <TrenchCoat> get_TrenchCoats() const { return coats; }

	int repo_length();
};

void test_repo_all();