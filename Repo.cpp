#include "Repo.h"
#include <assert.h>

void Repository::repo_add(const TrenchCoat coat)
{
	auto it = std::find_if(coats.begin(), coats.end(),
		[&](TrenchCoat& c) {return c.get_colour() == coat.get_colour(); });
	this->coats.push_back(coat);
}

void Repository::repo_delete(const TrenchCoat coat)
{
	auto it = std::find_if(coats.begin(), coats.end(), 
		[&](TrenchCoat& c) {return c.get_colour() == coat.get_colour(); });
	this->coats.erase(it);
}

void Repository::repo_update(const TrenchCoat coat)
{
	auto it = std::find_if(coats.begin(), coats.end(),
		[&](TrenchCoat& c) {return c.get_colour() == coat.get_colour(); });
	*it = coat;
}


int Repository::repo_length()
{
	return this->coats.size();
}


