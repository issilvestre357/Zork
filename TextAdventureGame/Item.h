#pragma once

#include <string>
#include <vector>

class Item 
{
	
private:

	std::string itemName;
	bool canHoldOtherItems;
	std::vector<Item> inventory;
	

public:

	Item(std::string itemName, bool canHoldOtherItems);
	Item* getItem(const std::string& itemName);

	const std::string& getItemName() const;

	
	
	void displayInv() const;

	bool hasItem(const std::string& itemName) const;
	bool addToInv(const Item& item);
	bool removeFromInv(const std::string& itemName);
	bool isEmpty() const;


};