#include "AlchemyWorkshop.h"

#include "RecipeManager.h"
#include "StockManager.h"
#include "PotionRecipe.h"

AlchemyWorkshop::AlchemyWorkshop()
{
	RM = new RecipeManager;
	SM = new StockManager;
}

AlchemyWorkshop::~AlchemyWorkshop()
{
	SAFE_DELETE(RM)
	SAFE_DELETE(SM)
}

void AlchemyWorkshop::addRecipe()
{
    string name;
    cout << "물약 이름: ";
    cin.ignore(10000, '\n');
    getline(cin, name);

    PotionRecipe* find = RM->searchRecipeByName(name);
    if (find)
    {
        cout << ">> " << name << "은(는) 이미 있습니다." << endl;
        return;
    }

    // 여러 재료를 입력받기 위한 로직
    vector<string> ingredients_input;
    string ingredient;
    cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)" << endl;

    while (true)
    {
        cout << "재료 입력: ";
        getline(cin, ingredient);

        // 사용자가 '끝'을 입력하면 재료 입력 종료
        if (ingredient == "끝") break;

        ingredients_input.push_back(ingredient);
    }

    // 입력받은 재료가 하나 이상 있을 때만 레시피 추가
    if (!ingredients_input.empty())
    {
        RM->addRecipe(name, ingredients_input);
        SM->initializeStock(name);
    }
    else
    {
        cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << endl;
    }
}

void AlchemyWorkshop::printAllRecipes() const
{
    RM->displayAllRecipes(SM);
}

void AlchemyWorkshop::Search(SearchOption option) const
{
    switch (option)
    {
        case ByName:
        {
            string name;
            cout << "찾을 물약 이름: ";
            cin.ignore(10000, '\n');
            getline(cin, name);

            PotionRecipe* find = RM->searchRecipeByName(name);
            if (find)
            {
                find->printInfo();
            }
            else
            {
                cout << ">> 그런 이름의 물약은 없습니다." << endl;
            }
        }
        break;

        case ByIngredient:
        {
            string name;
            cout << "찾을 재료 이름: ";
            cin.ignore(10000, '\n');
            getline(cin, name);

            RecipeList find = RM->searchRecipeByIngredient(name);
            if (!find.empty())
            {
                RecipeIterator iter;
                for (iter = find.begin(); iter != find.end(); ++iter)
                {
                    (*iter)->printInfo();
                }
            }
            else
            {
                cout << ">> 그런 재료가 필요한 물약은 없습니다." << endl;
            }
        }
        break;
    }
}

void AlchemyWorkshop::DispensePotion()
{
    string name;
    cout << "찾을 물약 이름: ";
    cin.ignore(10000, '\n');
    getline(cin, name);

    PotionRecipe* find = RM->searchRecipeByName(name);
    if (find)
    {
        if (SM->dispensePotion(name))
        {
            cout << ">> " << name << "을(를) 하나 제공했습니다." << endl;
            find->printInfo();
            cout << ">> 남은 재고: " << SM->getStock(name) << endl;
        }
        else
        {
            cout << ">> 남은 " << name << "이(가) 없습니다." << endl;
        }
    }
    else
    {
        cout << ">> 그런 이름의 물약은 없습니다." << endl;
    }
}

void AlchemyWorkshop::ReturnPotion()
{
    string name;
    cout << "반환할 물약 이름: ";
    cin.ignore(10000, '\n');
    getline(cin, name);

    PotionRecipe* find = RM->searchRecipeByName(name);
    if (find)
    {
        if (SM->returnPotion(name))
        {
            cout << ">> " << name << "을(를) 하나 반환했습니다." << endl;
            find->printInfo();
            cout << ">> 남은 재고: " << SM->getStock(name) << endl;
        }
        else
        {
            cout << ">> 이미 " << name << "이(가) 꽉찼습니다." << endl;
        }
    }
    else
    {
        cout << ">> 그런 이름의 물약은 없습니다." << endl;
    }
}
