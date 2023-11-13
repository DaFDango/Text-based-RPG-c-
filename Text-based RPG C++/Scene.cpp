#include <conio.h>
#include <iostream>
#include <sstream>
#include <Windows.h>
#include "Actor.h"
#include "Scene.h"
#include "System.h"

void Scene::Cave(Human* p)
{
    Goblin* enemy = new Goblin;
    srand(time(NULL));

    std::cout << "An enemy " + enemy->name+ " approches" << "\n\n";

    enemy->SetHp((rand() % 6) + 1);
    enemy->SetDamage((rand() % 2) + 1);
    enemy->SetGold(rand() % 3 + 1);

    std::string input;

    while (true) {

        std::cout << "Player health: " << p->GetHp() << "\n";
        std::cout << "--------><--------\n";
        std::cout << "Goblin health: " << enemy->GetHp() << "\n\n";

        std::cout << "Write 'attack' or 'a' to attack\n";
        getline(std::cin, input);

        for (auto& x : input) {
            x = tolower(x);
        }

        if (input.compare("attack") == 0 || input.compare("a") == 0) {
            enemy->TakeDamage(p->GetDamage());
        }
        
        if (enemy->GetHp() > 0) 
        {
            p->TakeDamage(enemy->GetDamage());  //Should be based on speed stat, "jump the enemy or get jumped by the enemy"
            
        }
        else 
        {
            short addedGold = enemy->GetGold();
            p->SetGold(p->GetGold() + addedGold);

            system("cls");
            RedText("You killed the monster. \n\n");
            HealthText("Player hp: " + std::to_string(p->GetHp()) + "hp\n");
            GoldText("You stole " + std::to_string(addedGold) + "g, Total: " + std::to_string(p->GetGold()) + "g");
            _getch();
            system("cls");
            break;
        }
        system("cls");
    }
}

void Scene::Village(Human* p)   //Shops
{
    char a = NULL;
    std::string c;
    system("cls");

    while (a != 'Q')
    {
        GoldText("Gold: " + std::to_string(p->GetGold()) + "g" + "\n");
        std::cout << "Hello adventurer.\n....\n\n" << "1. item1\n" << "2. item2\n" << "3. item3\n" << "4. item4\n";

        switch (tolower(_getch()))
        {
        case '1':
            a = 'Q';
            break;
        case '2':
            a = 'Q';
            break;
        case '3':
            a = 'Q';
            break;
        case '4':
            a = 'Q';
            break;
        default:
            system("cls");
            break;
        }
    }
    system("cls");
}

void Scene::Sanctuary(Human* p) //Healing, possibly speccing
{
    std::string c;
    system("cls");

    HealthText("Player health: " + std::to_string(p->GetHp()));
    std::cout << " |";
    GoldText(" Player Gold " + std::to_string(p->GetGold()) + "\n");
    std::cout << "Do you want to pray at the altar";
    GoldText("(5 gold)?\n");
    std::cout << "(Y)es\n" << "(N)o\n";
    switch(tolower(_getch()))
    {
        case 'y':
            p->SetGold((p->GetGold()) - 5);
            p->SetHp(p->GetMaxHp());
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            std::cout << "You feel a healing sensation after praying. (Press any key to continue...)\n"; //switch out for coloring functions
            _getch();
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        case 'n':
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            std::cout << "The gods will remember that. (Press any key to continue...)\n";
            _getch();
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        default:
            system("cls");
            break;
    }
}

void Scene::Sleep(Human* p) //Updates shop/village
{
    p->SetSleepless(p->GetSleepless() + 1);
    system("cls");
}

void Scene::Character(Human* p)
{
    system("cls");
    SystemText("Health: " + std::to_string(p->GetHp()) + "hp / " + std::to_string(p->GetMaxHp()) + "hp\n");
    SystemText("Damage: " + std::to_string(p->GetDamage()) + "\n");
    //Defence, speed...
    SystemText("Gold: " + std::to_string(p->GetGold()) + "g\n");
    SystemText("Inventory: N/A");
    _getch();
    system("cls");
}