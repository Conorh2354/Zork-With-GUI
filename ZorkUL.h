#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
//#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:
    vector<Room> rooms;
	Room *currentRoom;
	void createRooms();
    //void printWelcome();
	bool processCommand(Command command);
    //void printHelp();
	void goRoom(Command command);
    void createItems();
    void displayItems();

public:
    ZorkUL();
    void play();
    string printWelcome();
    string printHelp();
    string printEnd();
    string go(string direction);
    string teleport();
    string printMap();
    string printWordle();
    string viewItems();
    Room getCurrentRoom();
    string printInventory();
};

#endif /*ZORKUL_H_*/

