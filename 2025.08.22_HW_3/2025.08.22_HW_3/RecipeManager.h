#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Commons.h"

using namespace std;

class PotionRecipe;
class StockManager;

typedef vector<PotionRecipe*> RecipeList;
typedef RecipeList::iterator RecipeIterator;

class RecipeManager
{
private:
    RecipeList recipes;

public:
    ~RecipeManager();

    // addRecipe �޼���: ��� ���(vector)�� �Ű������� �޵��� ����
    void addRecipe(const string& name, const vector<string>& ingredients);

    // ��� ������ ��� �޼���
    void displayAllRecipes(StockManager* SM = nullptr) const;

    PotionRecipe* searchRecipeByName(string name) const;
    RecipeList searchRecipeByIngredient(string ingredient) const;
};

