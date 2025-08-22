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

    // addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
    void addRecipe(const string& name, const vector<string>& ingredients);

    // 모든 레시피 출력 메서드
    void displayAllRecipes(StockManager* SM = nullptr) const;

    PotionRecipe* searchRecipeByName(string name) const;
    RecipeList searchRecipeByIngredient(string ingredient) const;
};

