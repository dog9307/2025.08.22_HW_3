#include "PotionRecipe.h"

// 생성자: 재료 목록을 받아 초기화하도록 수정
PotionRecipe::PotionRecipe(const string& name, const IngredientList& ingredients)
	: potionName(name)
	, ingredients(ingredients)
{
}

void PotionRecipe::printName() const
{
	cout << "- 물약 이름: " << potionName << endl;
}

void PotionRecipe::printIngredients() const
{
    cout << "  > 필요 재료: ";
    for (size_t j = 0; j < ingredients.size(); ++j)
    {
        cout << ingredients[j];
        if (j < ingredients.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}

void PotionRecipe::printInfo() const
{
    printName();
    printIngredients();
}
