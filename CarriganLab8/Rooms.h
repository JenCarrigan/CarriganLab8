#include <iostream>
#include <string>

/*Header File

Creates Room structure
*/
#ifndef Rooms_h
#define Rooms_h

struct Room
{
private:
	std::string name;
	Room *north, *south, *east, *west;

public:
	Room();
	Room(std::string);
	Room *getNorth();
	Room *getEast();
	Room *getSouth();
	Room *getWest();
	void setNorth(Room *next);
	void setEast(Room *next);
	void setSouth(Room *next);
	void setWest(Room *next);
	std::string getName();
};

#endif
