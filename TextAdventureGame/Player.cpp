
#include"Player.h"
#include "Room.h"
#include <iostream>

Player::Player(Room& startingRoom) 
	: currentRoom(&startingRoom)
{
}

Room* Player::getCurrentRoom() const
{
	return currentRoom;
}

bool Player::hasItem(const std::string& itemName) const
{
	for (size_t i = 0; i < carriedItems.size(); i++)
	{
		if (carriedItems[i].getItemName() == itemName)
		{
			return true;
		}
		if (carriedItems[i].getItemName() == (itemName))
		{
			return true;
		}
	}
	return false;
}\

void Player::move(const std::string& direction)
{
	Connection* connection = currentRoom->getConnection(direction);

	if (connection == nullptr)
	{
		std::cout << "There's nothing over there." << std::endl;
		return;
	}

	if (connection->isLocked())
	{
		std::string requiredKey = connection->getRequiredKey();

		if (!hasItem(requiredKey))
		{
			std::cout << "This door is locked but the key has to be around here somewhere." << std::endl;
			return;
		}
		if (!connection->tryUnlock(requiredKey))
		{
			std::cout << "It seems I have the wrong key." << std::endl;
			return;
		}
		std::cout << "You unlocked the door!" << std::endl;
	}

	currentRoom = connection->getDestinationRoom();

	std::cout << "You enter: " << currentRoom->getRoomName() << std::endl;

	std::cout << currentRoom->getRoomDescription() << std::endl;

	currentRoom->displayItemsInRoom();
}

void Player::pickUpItem(const std::string& itemName) 
{
	Item* item = currentRoom->getItem(itemName);

	if (item == nullptr)
	{
		std::cout << "There's nothing like that here" << std::endl;
		return;
	}
	if (item->getItemName() == "Tool Belt")
	{
		carriedItems.push_back(*item);
		currentRoom->removeItemFromRoom(item->getItemName());
		
		std::cout << "You picked up the Tool Belt! This will be great to carry all my stuff in." << std::endl;
		return;
	}
	if (!hasItem("Tool Belt"))
	{
		std::cout << "If only I had something to carry this in." << std::endl;
		return;
	}
	for (size_t i = 0; i < carriedItems.size(); i++)
	{
		if (carriedItems[i].getItemName() == "Tool Belt")
		{
			if (carriedItems[i].addToInv(*item))
			{
				std::string pickedUpItemName = item->getItemName();

				currentRoom->removeItemFromRoom(pickedUpItemName);

				std::cout << "You picked up: " << pickedUpItemName << std::endl;
			}
			return;
		}
	}
}

void Player::dropItem(const std::string& itemName)
{
	if (itemName == "tool belt")
	{
		for (size_t i = 0; i < carriedItems.size(); i++)
		{
			if (carriedItems[i].getItemName() == "Tool Belt")
			{
				if (!carriedItems[i].isEmpty())
				{
					std::cout << "The belt's too tight with all these things inside it to drop it." << std::endl;
					return;
				}
				currentRoom->addItemToRoom(carriedItems[i]);
				carriedItems.erase(carriedItems.begin() + i);

				std::cout << "You have dropped the Tool Belt." << std::endl;
				return;
			}
		}
		std::cout << "You aren't carrying the Tool Belt." << std::endl;
		return;
	}
	for (size_t i = 0; i < carriedItems.size(); i++)
	{
		if (carriedItems[i].getItemName() == "Tool Belt")
		{
			Item* item = carriedItems[i].getItem(itemName);

			if (item == nullptr)
			{
				std::cout << "You aren't carrying that." << std::endl;
				return;
			}
			std::string droppedItemName = item->getItemName();

			currentRoom->addItemToRoom(*item);

			carriedItems[i].removeFromInv(droppedItemName);

			std::cout << "You dropped: " << droppedItemName << std::endl;
			return;
		}
	}
	std::cout << "You aren't carrying that." << std::endl;
}

void Player::displayInventory() const
{
	if (carriedItems.empty())
	{
		std::cout << "You aren't carrying anything." << std::endl;
		return;
	}

	for (size_t i = 0; i < carriedItems.size(); i++)
	{
		std::cout << carriedItems[i].getItemName() << std::endl;

		if (carriedItems[i].getItemName() == "Tool Belt")
		{
			if (carriedItems[i].isEmpty())
			{
				std::cout << "The Tool Belt is empty." << std::endl;
			}
			else
			{
				std::cout << "Inside the Tool Belt is:" << std::endl;
				carriedItems[i].displayInv();
			}
		}
	}
}

bool Player::removeItem(const std::string& itemName)
{
	for (size_t i = 0; i < carriedItems.size(); i++)
	{
		if (carriedItems[i].getItemName() == "Tool Belt")
		{
			return carriedItems[i].removeFromInv(itemName);
		}
	}

	return false;
}