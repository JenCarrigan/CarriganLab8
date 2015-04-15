#include "Rooms.h"
#include <iostream>
#include <string>

/*Rooms.cpp

Definitions for constructors. Initializes pointers to rooms.
*/
Room::Room()
{
	name = "Where are you?!";
	north = NULL;
	south = NULL;
	east = NULL;
	west = NULL;
}

Room::Room(std::string name)
{
	this->name = name;
	north = NULL;
	south = NULL;
	east = NULL;
	west = NULL;
}

Room * Room::getNorth()
{
	return north;
}

Room * Room::getEast()
{
	return east;
}

Room * Room::getSouth()
{
	return south;
}

Room * Room::getWest()
{
	return west;
}

void Room::setNorth(Room *next)
{
	north = next;
}

void Room::setEast(Room *next)
{
	east = next;
}

void Room::setSouth(Room *next)
{
	south = next;
}

void Room::setWest(Room *next)
{
	west = next;
}

std::string Room::getName()
{
	return name;
}