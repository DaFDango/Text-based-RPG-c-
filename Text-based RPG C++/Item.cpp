#include "Item.h"

std::string Item::getName() {
	return this->name;
}
void Item::setName(std::string value) {
	this->name = value;
}
int Item::getMight() {
	return this->might;
}
void Item::setMight(int value) {
	this->might = value;
}