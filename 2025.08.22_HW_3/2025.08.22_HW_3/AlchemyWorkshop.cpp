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
    cout << "���� �̸�: ";
    cin.ignore(10000, '\n');
    getline(cin, name);

    PotionRecipe* find = RM->searchRecipeByName(name);
    if (find)
    {
        cout << ">> " << name << "��(��) �̹� �ֽ��ϴ�." << endl;
        return;
    }

    // ���� ��Ḧ �Է¹ޱ� ���� ����
    vector<string> ingredients_input;
    string ingredient;
    cout << "�ʿ��� ������ �Է��ϼ���. (�Է� �Ϸ� �� '��' �Է�)" << endl;

    while (true)
    {
        cout << "��� �Է�: ";
        getline(cin, ingredient);

        // ����ڰ� '��'�� �Է��ϸ� ��� �Է� ����
        if (ingredient == "��") break;

        ingredients_input.push_back(ingredient);
    }

    // �Է¹��� ��ᰡ �ϳ� �̻� ���� ���� ������ �߰�
    if (!ingredients_input.empty())
    {
        RM->addRecipe(name, ingredients_input);
        SM->initializeStock(name);
    }
    else
    {
        cout << ">> ��ᰡ �Էµ��� �ʾ� ������ �߰��� ����մϴ�." << endl;
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
            cout << "ã�� ���� �̸�: ";
            cin.ignore(10000, '\n');
            getline(cin, name);

            PotionRecipe* find = RM->searchRecipeByName(name);
            if (find)
            {
                find->printInfo();
            }
            else
            {
                cout << ">> �׷� �̸��� ������ �����ϴ�." << endl;
            }
        }
        break;

        case ByIngredient:
        {
            string name;
            cout << "ã�� ��� �̸�: ";
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
                cout << ">> �׷� ��ᰡ �ʿ��� ������ �����ϴ�." << endl;
            }
        }
        break;
    }
}

void AlchemyWorkshop::DispensePotion()
{
    string name;
    cout << "ã�� ���� �̸�: ";
    cin.ignore(10000, '\n');
    getline(cin, name);

    PotionRecipe* find = RM->searchRecipeByName(name);
    if (find)
    {
        if (SM->dispensePotion(name))
        {
            cout << ">> " << name << "��(��) �ϳ� �����߽��ϴ�." << endl;
            find->printInfo();
            cout << ">> ���� ���: " << SM->getStock(name) << endl;
        }
        else
        {
            cout << ">> ���� " << name << "��(��) �����ϴ�." << endl;
        }
    }
    else
    {
        cout << ">> �׷� �̸��� ������ �����ϴ�." << endl;
    }
}

void AlchemyWorkshop::ReturnPotion()
{
    string name;
    cout << "��ȯ�� ���� �̸�: ";
    cin.ignore(10000, '\n');
    getline(cin, name);

    PotionRecipe* find = RM->searchRecipeByName(name);
    if (find)
    {
        if (SM->returnPotion(name))
        {
            cout << ">> " << name << "��(��) �ϳ� ��ȯ�߽��ϴ�." << endl;
            find->printInfo();
            cout << ">> ���� ���: " << SM->getStock(name) << endl;
        }
        else
        {
            cout << ">> �̹� " << name << "��(��) ��á���ϴ�." << endl;
        }
    }
    else
    {
        cout << ">> �׷� �̸��� ������ �����ϴ�." << endl;
    }
}
