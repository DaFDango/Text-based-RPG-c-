#pragma once
#include "Item.h"
#include <list>
#include <iostream>

class Actor
{
public:
	/*============ Getters and setters ============*/
	int GetHp();
	void SetHp(int);
	int GetMaxHp();
	void SetMaxHp(int);
	int GetDamage();
	void SetDamage(int);
	int GetGold();
	void SetGold(int);

	/*============ Actions and related functions ============*/
	void Attack(Actor);
	void TakeDamage(int);

private:
	/*============ Actor properties ============*/
	int hp;
	int maxHp;
	int damage;
	int gold;
	std::list<Item>* inventory;
};

class Humanoid : public Actor
{
public:
	int* GetArmor();
	void SetArmor();

private:
	int armor[4];
};

class Human : public Humanoid
{
public:
	static const std::string name;
	int GetSleepless();
	void SetSleepless(int);

private:
	int sleeplessCount;	//Discourages sleeping repetedly to reset store by spawning monster if player hasn't prayed to reset the counter.
};

class Goblin : public Humanoid
{
public:
	static const std::string name;

private:

};