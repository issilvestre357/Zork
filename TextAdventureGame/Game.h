#pragma once

#include "Room.h"
#include "Player.h"

class Game
{

private:

	Room eatingArea;
	Room bathroom;
	Room exitRoom;
	Room guardRoom;
	Room kitchen;
	Room supplyCloset;

	Player player;

	bool fuseInstalled = false;

	void setUpWorld();
	void handleSupplyCloset();


public:
	
	Game();

	bool start();
};