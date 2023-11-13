#pragma once
#include <iostream>

class Item
{
public:
	std::string getName();
	void setName(std::string);
	int getMight();
	void setMight(int);

private:
	std::string name;
	int might;	//Defines item efficiency (hp healed, added attack damage/defence and so on)
};

class Weapon : public Item 
{

};
