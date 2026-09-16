
#include "Item.h"
#include <cctype>
#include <iostream>

Item::Item(std::string itemName, bool canHoldOtherItems)
	: itemName(itemName), canHoldOtherItems(canHoldOtherItems)
{

}

Item* Item::getItem(const std::string& itemName)
{
	for (size_t i = 0; i < inventory.size(); i++)
	{
		std::string storedName = inventory[i].getItemName();

		for (size_t j = 0; j < storedName.size(); j++)
		{
			storedName[j] = static_cast<char>(std::tolower(storedName[j]));
		}

		if (itemName == storedName)
		{
			return &inventory[i];
		}
	}

	return nullptr;
}

const std::string& Item::getItemName() const 
{
	return itemName;
}

bool Item::addToInv(const Item& item)
{
	if (canHoldOtherItems != true)
	{
		return false;
	} 
	inventory.push_back(item);
	return true;
}

bool Item::removeFromInv(const std::string& itemName)
{
	for (size_t i = 0; i < inventory.size(); i++)
	{
		if (inventory[i].getItemName() == itemName)
		{
			inventory.erase(inventory.begin() + i);
			return true;
		}
	}

	return false;
}

void Item::displayInv() const
{

	if (inventory.size() <= 0) {

		std::cout << "Your inventory is empty" << std::endl;

	}
	else {
		for (size_t i = 0; i < inventory.size(); i++)
			std::cout << inventory[i].getItemName() << std::endl;

	}
}

bool Item::hasItem(const std::string& itemName) const
{
	for (size_t i = 0; i < inventory.size(); i++)
	{
		if (inventory[i].getItemName() == itemName)
		{
			return true;
		}
	}
	return false;
}

bool Item::isEmpty() const
{
	return inventory.empty();
}
