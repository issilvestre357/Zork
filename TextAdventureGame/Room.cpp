#include "Room.h"
#include <cctype>
#include <iostream>


Room::Room(std::string roomName, std::string roomDescription)
{
	for (size_t i = 0; i < roomName.size(); i++)
	{
		roomName[i] = static_cast<char>(std::tolower(roomName[i]));
	}

	this -> roomName = roomName;
	this ->roomDescription = roomDescription;
}

const std::string& Room::getRoomName() const
{
	return roomName;
}

std::string Room::getRoomDescription() const 
{
	if (roomName == "kitchen")
	{
		if (isLightOn == true)
		{
			return "You can now see everything in the kitchen!";
		}
		else {
			return "It's too dark I can't see anything in here";
		}


	} 
	else {
		return roomDescription;
	}

}

void Room::addItemToRoom(const Item& item)
{
	itemsInRoom.push_back(item);
}

void Room::removeItemFromRoom(const std::string& itemName)
{
	if (roomName == "kitchen" && isLightOn == false)
	{
		std::cout << "It's too dark to find anything in here" << std::endl;
		return;
	}
	for (size_t i = 0; i < itemsInRoom.size(); i++)
	{
		if (itemsInRoom[i].getItemName() == itemName)
		{
			itemsInRoom.erase(itemsInRoom.begin() + i);
			return;
		}
	}
}

void Room::displayItemsInRoom() const
{
	if (roomName == "kitchen" && isLightOn == false) 
	{
		return;
	}
	if (itemsInRoom.empty())
	{
		return;
	}
	for (size_t i = 0; i < itemsInRoom.size(); i++)
	{
		std::cout << itemsInRoom[i].getItemName() << std::endl;
	}
}

void Room::setLightState(bool lightInput) 
{
	isLightOn = lightInput;
}

void Room::connectRoom(const std::string& direction, Room& room, bool locked, const std::string& requiredKey)
{
	connections.erase(direction);

	connections.emplace(direction, Connection(room, locked, requiredKey));
	
}

Connection* Room::getConnection(const std::string& direction)
{
	auto it = connections.find(direction);

	if (it != connections.end())
	{
		return &it->second;
	}

	return nullptr;
}

Item* Room::getItem(const std::string& itemName)
{
	if (roomName == "kitchen" && isLightOn == false)
	{
		return nullptr;
	}

	for (size_t i = 0; i < itemsInRoom.size(); i++)
	{
		std::string storedName = itemsInRoom[i].getItemName();

		for (size_t j = 0; j < storedName.size(); j++)
		{
			storedName[j] = static_cast<char>(std::tolower(storedName[j]));
		}

		if (itemName == storedName)
		{
			return &itemsInRoom[i];
		}
	}

	return nullptr;
}
