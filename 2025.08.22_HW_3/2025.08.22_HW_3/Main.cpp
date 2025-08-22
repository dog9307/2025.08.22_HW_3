#include "PotionRecipe.h"
#include "AlchemyWorkshop.h"

enum SELECT_MENU
{
    Add = 1,
    Print,
    SearchByName,
    SearchByIngredient,
    DispensePotion,
    ReturnPotion,
    Quit
};

int main() {
    AlchemyWorkshop myWorkshop;

    bool isWorkShopClose = false;
    while (!isWorkShopClose)
    {
        cout << "※ 연금술 공방 관리 시스템" << endl;
        cout << "1. 레시피 추가" << endl;
        cout << "2. 모든 레시피 출력" << endl;
        cout << "3. 레서피 이름 검색" << endl;
        cout << "4. 레서피 재료 검색" << endl;
        cout << "5. 물약 조제" << endl;
        cout << "6. 물약 반환" << endl;
        cout << "7. 종료" << endl;
        cout << "선택: ";

        int choice;
        cin >> choice;

        if (cin.fail())
        {
            cout << "잘못된 입력입니다. 숫자를 입력해주세요." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice)
        {
            case Add:
                myWorkshop.addRecipe();
            break;

            case Print:
                myWorkshop.printAllRecipes();
            break;

            case SearchByName:
                myWorkshop.Search(SearchOption::ByName);
            break;

            case SearchByIngredient:
                myWorkshop.Search(SearchOption::ByIngredient);
            break;

            case DispensePotion:
                myWorkshop.DispensePotion();
            break;

            case ReturnPotion:
                myWorkshop.ReturnPotion();
            break;

            case Quit:
                cout << "공방 문을 닫습니다..." << endl;
                isWorkShopClose = true;
            break;

            default:
                cout << "잘못된 선택입니다. 다시 시도하세요." << endl;
            break;
        }
    }

    return 0;
}
