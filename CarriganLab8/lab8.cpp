#include "Rooms.h"
#include <iostream>
#include <cstdlib>

/* Move function

Takes direction char and current room as parameters
and moves player to next room in node. If player enters
direction that has a null pointer, program will output
that there is no door.

*/
Room * move(Room *current, char direction)
{
	Room *next = NULL;
	switch (direction)
	{
	case 'n': next = current->getNorth();
		break;
	case 'e': next = current->getEast();
		break;
	case 's': next = current->getSouth();
		break;
	case 'w': next = current->getWest();
		break;
	}

	if (next == NULL)
	{
		std::cout << "No door!\n\n";
		return current;
	}
	else
	{
		std::cout << "You are now moving to the " << next->getName() << std::endl;
		return next;
	}
}

/*Check function

Takes current room as parameter and checks the direction
the player can go. If all directions in the room have a
null pointer, the player is stuck and can never leave.
*/
void check(Room *current)
{
	std::cout << "You can go:\n";
	if (current->getNorth() != NULL)
		std::cout << "North\n";
	if (current->getEast() != NULL)
		std::cout << "East\n";
	if (current->getSouth() != NULL)
		std::cout << "South\n";
	if (current->getWest() != NULL)
		std::cout << "West\n";
	if (current->getWest() == NULL && current->getSouth() == NULL && current->getEast() == NULL && current->getNorth() == NULL)
	{
		std::cout << "NOWHERE!\nYou have reached a dead end. You are now trapped here for all eternity. Sucks to be you!\n";
		std::cout << "Guess you'll have to try again...";
		std::cin.ignore();
		std::cin.get();
		exit(1);
	}
}

int main()
{
	//create pointer rooms
	Room *lobby = new Room("Lobby");
	Room *den = new Room("Den");
	Room *hallway = new Room("Hallway");
	Room *kitchen = new Room("Kitchen");
	Room *stairs = new Room("Stairs");
	Room *bedroom = new Room("Bedroom");
	Room *exit = new Room("Exit");

	//link rooms
	lobby->setWest(den);
	lobby->setNorth(hallway);
	den->setNorth(kitchen);
	kitchen->setWest(hallway);
	hallway->setEast(kitchen);
	hallway->setWest(bedroom);
	hallway->setNorth(stairs);
	bedroom->setEast(hallway);
	kitchen->setNorth(exit);

	char direction;
	Room *next = NULL;

	std::cout << "You are in the " << lobby->getName() << std::endl;
	check(lobby);
	std::cout << "Which way would you like to go (e/n/w/s)? ";
	std::cin >> direction;
	next = move(lobby, direction);
	while (next->getName() != "Exit")
	{
		if (next->getName() == "Exit")
			break;
		std::cout << "\n\nYou are now in the " << next->getName() << std::endl;
		check(next);
		std::cout << "Which way would you like to go (e/n/w/s)? ";
		std::cin >> direction;
		next = move(next, direction);
	}

	if (next->getName() == "Exit")
	{
		std::cout << "\n\n\nCongrats, you made it out of the house. You want a cookie? Too bad. Lots of people can get out of a house.\n\n";
		std::cin.ignore();
		std::cin.get();
	}

	delete lobby, den, hallway, kitchen, stairs, bedroom, exit;
	return 0;
}