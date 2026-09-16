#pragma once

#include "Room.h"
#include "Item.h"
#include <string>
#include <vector>


class Player
{

private:

	Room* currentRoom;
	std::vector<Item> carriedItems;


public:

	Player(Room& startingRoom);

	Room* getCurrentRoom() const;

	void move(const std::string& direction);
	void pickUpItem(const std::string& itemName);
	void dropItem(const std::string& itemName);
	void displayInventory() const;

	bool hasItem(const std::string& itemName) const;
};