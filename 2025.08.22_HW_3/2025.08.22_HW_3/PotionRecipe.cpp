#include "PotionRecipe.h"

// ������: ��� ����� �޾� �ʱ�ȭ�ϵ��� ����
PotionRecipe::PotionRecipe(const string& name, const IngredientList& ingredients)
	: potionName(name)
	, ingredients(ingredients)
{
}

void PotionRecipe::printName() const
{
	cout << "- ���� �̸�: " << potionName << endl;
}

void PotionRecipe::printIngredients() const
{
    cout << "  > �ʿ� ���: ";
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
