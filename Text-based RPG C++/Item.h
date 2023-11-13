#pragma once
#include <iostream>

class Item
{
public:
	std::string getName();
	void setName();
	int getValue();
	void setValue();

private:
	std::string name;
	int value;	//Defines item efficiency (hp healed, added attack damage/defence and so on)
};

class Weapon : public Item 
{

};
