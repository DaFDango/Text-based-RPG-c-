#pragma once
#include "Actor.h"

/*============ Getters and Setters ============*/

/*>Actor<*/
int Actor::GetHp() { return this->hp; }
void Actor::SetHp(int value) { hp = value; }
int Actor::GetMaxHp(){ return this->maxHp; }
void Actor::SetMaxHp(int value){ maxHp = value; }
int Actor::GetDamage() { return this->damage; }
void Actor::SetDamage(int value) { this->damage = value; }
int Actor::GetGold() { return this->gold; }
void Actor::SetGold(int value) { this->gold = value; }

/*>Humanoid<*/
int* Humanoid::GetArmor() { return armor; }
void Humanoid::SetArmor() {  }

/*>Human<*/
int Human::GetSleepless() { return this->sleeplessCount; }
void Human::SetSleepless(int value) { this->sleeplessCount = value; }

/*============ Actions and Related Functions ============*/
void Actor::Attack(Actor a) { a.TakeDamage(this->damage); }
void Actor::TakeDamage(int i) { hp -= i; }

const std::string Human::name = std::string("Human");
const std::string Goblin::name = std::string("Goblin");