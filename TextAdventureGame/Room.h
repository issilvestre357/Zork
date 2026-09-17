#pragma once

#include <string>
#include <vector>
#include <map>
#include "Item.h"
#include "Connection.h"


class Room
{
private:
	
	std::string roomName;
	std::string roomDescription;
	std::vector<Item> itemsInRoom;
	std::map<std::string, Connection> connections;

	bool isLightOn = false;
	
	

public:
	 
	Room(std::string roomName, std::string roomDescription);

	const std::string& getRoomName() const;
	std::string getRoomDescription() const;
	
	void displayItemsInRoom() const;
	void addItemToRoom(const Item& item);
	void removeItemFromRoom(const std::string& itemName);
	void setLightState(bool lightInput);
	void connectRoom(const std::string& direction, Room& room, bool locked, const std::string& requiredKey);
	void setRoomDescription(const std::string& description);

	Connection* getConnection(const std::string& direction);
	Item* getItem(const std::string& itemName);
	
	




	
};