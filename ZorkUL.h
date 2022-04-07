#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
//#include "Parser.h"
#include "Room.h"
#include "item.h"
#include "weapon.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ZorkUL {
private:
    vector<Room> rooms;
	Room *currentRoom;
	void createRooms();
    //void printWelcome();
	bool processCommand(Command command);
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
    string map();
    string viewCharacterInfo();
    string viewItems();
    Room getCurrentRoom();
    string playWordle();
};

#endif /*ZORKUL_H_*/

