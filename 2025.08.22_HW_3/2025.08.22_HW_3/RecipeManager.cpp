#include "RecipeManager.h"

#include "PotionRecipe.h"
#include "StockManager.h"

RecipeManager::~RecipeManager()
{
    for (RecipeIterator iter = recipes.begin(); iter != recipes.end(); ++iter)
        SAFE_DELETE((*iter))

    recipes.clear();
}

// addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
void RecipeManager::addRecipe(const string& name, const vector<string>& ingredients)
{
    recipes.push_back(new PotionRecipe(name, ingredients));
    cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << endl;
}

void RecipeManager::displayAllRecipes(StockManager* SM) const
{
    if (recipes.empty())
    {
        cout << "아직 등록된 레시피가 없습니다." << endl;
        return;
    }

    cout << "\n--- [ 전체 레시피 목록 ] ---" << endl;
    for (size_t i = 0; i < recipes.size(); ++i)
    {
        if (recipes[i])
        {
            recipes[i]->printInfo();
            if (SM)
            {
                cout << "  > 남은 재고: " << SM->getStock(recipes[i]->getName()) << endl;
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
