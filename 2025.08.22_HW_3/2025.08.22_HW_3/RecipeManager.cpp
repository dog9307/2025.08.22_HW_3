#include "RecipeManager.h"

#include "PotionRecipe.h"
#include "StockManager.h"

RecipeManager::~RecipeManager()
{
    for (RecipeIterator iter = recipes.begin(); iter != recipes.end(); ++iter)
        SAFE_DELETE((*iter))

    recipes.clear();
}

// addRecipe �޼���: ��� ���(vector)�� �Ű������� �޵��� ����
void RecipeManager::addRecipe(const string& name, const vector<string>& ingredients)
{
    recipes.push_back(new PotionRecipe(name, ingredients));
    cout << ">> ���ο� ������ '" << name << "'��(��) �߰��Ǿ����ϴ�." << endl;
}

void RecipeManager::displayAllRecipes(StockManager* SM) const
{
    if (recipes.empty())
    {
        cout << "���� ��ϵ� �����ǰ� �����ϴ�." << endl;
        return;
    }

    cout << "\n--- [ ��ü ������ ��� ] ---" << endl;
    for (size_t i = 0; i < recipes.size(); ++i)
    {
        if (recipes[i])
        {
            recipes[i]->printInfo();
            if (SM)
            {
                cout << "  > ���� ���: " << SM->getStock(recipes[i]->getName()) << endl;
            }
        }
    }
    std::cout << "---------------------------\n";
}

PotionRecipe* RecipeManager::searchRecipeByName(string name) const
{
    PotionRecipe* find = nullptr;

    for (auto elem : recipes)
    {
        if (elem->getName() == name)
        {
            find = elem;
            break;
        }
    }

    //for (size_t i = 0; i < recipes.size(); ++i)
    //{
    //    if (recipes[i]->getName() == name)
    //    {
    //        find = recipes[i];
    //        break;
    //    }
    //}

    return find;
}

RecipeList RecipeManager::searchRecipeByIngredient(string ingredient) const
{
    RecipeList findList;

    for (size_t i = 0; i < recipes.size(); ++i)
    {
        IngredientList currentIngredientList = recipes[i]->getIngredients();
        for (size_t j = 0; j < currentIngredientList.size(); ++j)
        {
            if (currentIngredientList[j] == ingredient)
            {
                findList.push_back(recipes[i]);
                break;
            }
        }
    }

    return findList;
}
