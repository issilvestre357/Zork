
#include "Game.h"
#include "Item.h"
#include <iostream>
#include <string>
#include <cctype>

Game::Game()
	
	: eatingArea("Eating Area", "The main dining area of the pizzeria."),
	  bathroom("Bathroom", "A small bathroom. It looks like someone left something behind."),
	  exitRoom("Exit", " "),
	  guardRoom("Guard Room", "A small security room filled with old equipment"),
	  kitchen("Kitchen", "The pizzeria kitchen."),
	  supplyCloset("Supply Closet", "A cramped supply closet full of electrical equipment, this panel could sure use some work!"),

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

bool Game::start()
{
    std::string input;

    std::cout << "You wake up dazed in a pizzeria dining room, what do you do?" << std::endl;
    std::cout << player.getCurrentRoom()->getRoomDescription() << std::endl;
    player.getCurrentRoom()->displayItemsInRoom();
    std::cout << "Which way would you like to go: " << "North, South, East, or West." << std::endl;
    
    while (true)
    {
        Room* roomBeforeCommand = player.getCurrentRoom();

        std::cout << "\n> ";
        std:getline(std::cin, input);


        for (size_t i = 0; i < input.size(); i++)
        {
            input[i] = static_cast<char>(std::tolower(input[i]));
        }

        if (input.find("restart") != std::string::npos)
        {
            std::string answer;

            std::cout << "Would you really like to restart? Yes or no: ";
            std::getline(std::cin, answer);

            for (size_t i = 0; i < answer.size(); i++)
            {
                answer[i] = static_cast<char>(std::tolower(answer[i]));
            }

            if (answer == "yes" || answer == "y")
            {
                return true;
            }

            std::cout << "Restart cancelled." << std::endl;
            continue;
        }


        if (input.find("quit") != std::string::npos)
        {
            std::string answer;

            std::cout << "Thanks for playing!" << std::endl;
            std::cout << "Would you like to restart? Yes or no: ";
            std::getline(std::cin, answer);

            for (size_t i = 0; i < answer.size(); i++)
            {
                answer[i] = static_cast<char>(std::tolower(answer[i]));
            }

            if (answer == "yes" || answer == "y")
            {
                return true;
            }

            return false;
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
        

        if ((input.find("pick up") != std::string::npos || input.find("grab") != std::string::npos || input.find("take") != std::string::npos) && itemName != "")
        {
            player.pickUpItem(itemName);
        }
        else if ((input.find("drop") != std::string::npos || input.find("leave") != std::string::npos) && itemName != "")
        {
            player.dropItem(itemName);
        }
        else if (input.find("inventory") != std::string::npos)
        {
            player.displayInventory();
        }
        else if ((input.find("look") != std::string::npos || input.find("see") != std::string::npos))
        {
            std::cout << player.getCurrentRoom()->getRoomDescription() << std::endl;
            player.getCurrentRoom()->displayItemsInRoom();
        }
        else if (input.find("north") != std::string::npos)
        {
            player.move("north");
        }
        else if (input.find("south") != std::string::npos)
        {
            player.move("south");
        }
        else if (input.find("east") != std::string::npos)
        {
            player.move("east");
        }
        else if (input.find("west") != std::string::npos)
        {
            player.move("west");
        }
        else
        {
            std::cout << "I don't know that one try something else." << std::endl;
        }


        if (player.getCurrentRoom() != roomBeforeCommand &&
            player.getCurrentRoom()->getRoomName() == "supply closet")
        {
            handleSupplyCloset();
        }


        if (player.getCurrentRoom()->getRoomName() == "exit")
        {
            std::string answer;

            std::cout << "\nYou made it out of the pizzeria!" << std::endl;
            std::cout << "Congratulations, you escaped!" << std::endl;
            std::cout << "Would you like to play again? Yes or no: ";

            std::getline(std::cin, answer);

            for (size_t i = 0; i < answer.size(); i++)
            {
                answer[i] = static_cast<char>(std::tolower(answer[i]));
            }

            if (answer == "yes" || answer == "y")
            {
                return true;
            }
            return false;
        }
    }
    return false;
}

void Game::handleSupplyCloset()
{
    if (fuseInstalled)
    {
        return;
    }

    std::string answer;

    std::cout << "\nYou notice an empty fuse slot in the electrical panel." << std::endl;
    std::cout << "Would you like to use the Fuse? Yes or no: ";

    std::getline(std::cin, answer);

    for (size_t i = 0; i < answer.size(); i++)
    {
        answer[i] = static_cast<char>(std::tolower(answer[i]));
    }

    if (answer == "yes" || answer == "y")
    {
        if (!player.hasItem("Fuse"))
        {
            std::cout << "You don't have the Fuse yet." << std::endl;
            std::cout << "What will you do next?" << std::endl;
            return;
        }

        player.removeItem("Fuse");

        kitchen.setLightState(true);
        fuseInstalled = true;

        supplyCloset.setRoomDescription
        ("A cramped supply closet full of electrical equipment. The fuse is installed and the electrical panel is humming normally.");

        std::cout << "\nYou install the Fuse into the electrical panel." << std::endl;
        std::cout << "The power comes back on!" << std::endl;
        std::cout << "You hear the kitchen lights flicker to life." << std::endl;
        std::cout << "What do you do next" << std::endl;

        return;
    }

    std::cout << "You leave the electrical panel alone for now." << std::endl;
    std::cout << "What will you do next?" << std::endl;
}

