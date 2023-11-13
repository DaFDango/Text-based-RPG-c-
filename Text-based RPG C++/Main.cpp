#include <iostream>
#include <sstream>
#include <conio.h> 
#include "Actor.h"
#include "Scene.h"
#include "System.h"

int main()
{
    Human* player = new Human;
    Scene* s = new Scene;
    char a = NULL;
    std::string c;
    int baseHp = 10;
    int baseDmg = 2;

    player->SetHp(baseHp);
    player->SetMaxHp(baseHp);
    player->SetDamage(baseDmg);
    player->SetGold(0);

    while (a != 'Q')
    {
        SystemText("Where do you want to go?\n");
        std::cout << "1.Cave\n" << "2.Village\n" << "3.Sanctuary\n" << "4.Sleep\n" << "5.Character\n" << "6.Quit\n\n";

        switch (_getch())
        {
            case '1':
                system("cls");
                s->Cave(player);
                break;
            case '2':
                system("cls");
                s->Village(player);
                break;
            case '3':
                s->Sanctuary(player);
                break;
            case '4':
                s->Sleep(player);
                break;
            case '5':
                s->Character(player);
                break;
            case '6':
                a = 'Q';
                break;
            default:
                system("cls");
                break;
        }
    }
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
