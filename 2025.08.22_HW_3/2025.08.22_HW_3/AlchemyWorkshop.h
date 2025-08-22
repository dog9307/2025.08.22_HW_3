#pragma once

#include "Commons.h"

class RecipeManager;
class StockManager;

enum SearchOption
{
	ByName,
	ByIngredient
};

class AlchemyWorkshop
{
private:
	RecipeManager* RM;
	StockManager* SM;

public:
	AlchemyWorkshop();
	~AlchemyWorkshop();

	void addRecipe();
	void printAllRecipes() const;
	void Search(SearchOption option) const;
	void DispensePotion();
	void ReturnPotion();
};
