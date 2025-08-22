#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> IngredientList;

class PotionRecipe
{
private:
    string potionName;
    IngredientList ingredients;

public:
    PotionRecipe(const string& name, const IngredientList& ingredients);

    void printName() const;
    void printIngredients() const;

    void printInfo() const;

    inline string getName() const { return potionName; }
    inline IngredientList getIngredients() const { return ingredients; }
};
