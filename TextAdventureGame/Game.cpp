
#include "Game.h"
#include "Item.h"
#include <iostream>
#include <string>
#include <cctype>

Game::Game()
	
	: eatingArea("Eating Area", "The main dining area of the pizzeria."),
	  bathroom("Bathroom", "A small bathroom. It looks like someone left something behind."),
	  exitRoom("Exit", "The front exit. Freedom is right in front of you."),
	  guardRoom("Guard Room", "A small security room filled with old equipment, seems like somethings missing on the panel."),
	  kitchen("Kitchen", "The pizzeria kitchen."),
	  supplyCloset("Supply Closet", "A cramped supply closet full of electrical equipment."),

	  player(eatingArea)
{
	setUpWorld();
}

void Game::setUpWorld()
{
	eatingArea.connectRoom("north", bathroom, false, "");
    bathroom.connectRoom("south", eatingArea, false, "");

   
    eatingArea.connectRoom("west", kitchen, false, "");
    kitchen.connectRoom("east", eatingArea, false, "");

    
    kitchen.connectRoom("south", supplyCloset, false, "");
    supplyCloset.connectRoom("north", kitchen, false, "");

    
    eatingArea.connectRoom("east", guardRoom, true, "Guardroom Key");
    guardRoom.connectRoom("west", eatingArea, false, "");

    
    eatingArea.connectRoom("south", exitRoom, true, "Exit Key");
    exitRoom.connectRoom("north", eatingArea, false, "");


    Item toolBelt("Tool Belt", true);
    Item fuse("Fuse", false);
    Item guardroomKey("Guardroom Key", false);
    Item exitKey("Exit Key", false);


    bathroom.addItemToRoom(toolBelt);
    eatingArea.addItemToRoom(fuse);
    kitchen.addItemToRoom(guardroomKey);;
    guardRoom.addItemToRoom(exitKey);
}

void Game::start()
{
    std::string input;

    std::cout << "You wake up dazed in a pizzeria, what do you do?" << std::endl;
    std::cout << player.getCurrentRoom()->getRoomDescription() << std::endl;
    player.getCurrentRoom()->displayItemsInRoom();
    
    while (true)
    {
        std::cout << "\n> ";
    std:getline(std::cin, input);


        for (size_t i = 0; i < input.size(); i++)
        {
            input[i] = static_cast<char>(std::tolower(input[i]));
        }

        std::string itemName = "";




        if (input.find("tool belt") != std::string::npos)
        {
            itemName = "tool belt";
        }
        else if (input.find("fuse") != std::string::npos)
        {
            itemName = "fuse";
        }
        else if (input.find("guardroom key") != std::string::npos)
        {
            itemName = "guardroom key";
        }
        else if (input.find("exit key") != std::string::npos)
        {
            itemName = "exit key";
        }
 
    }
}
