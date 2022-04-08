#include <iostream>

using namespace std;
#include "ZorkUL.h"


ZorkUL::ZorkUL() {
	createRooms();

}

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;

    a = new Room("in the hall, \"I guess I should go downstairs\"");


    b = new Room("in your parents room, \"They always give out about my messy room but theres is worse!\" ");

    c = new Room("outside your sisters room,\n\"I'd better not go in here, she'd just scream at me anyways\"");

    d = new Room("in the porch,\n\"I can see the outside, if I keep going this way I can go outside or maybe I should go back to my room\"");

    e = new Room("in the sittting room,\n\"I could always just in stay here and turn on my xbox\"");

    f = new Room("in your bedroom,\n\"Okay my bedroom, maybe I should turn my computer back on and play some games\"");
    f->addItem(new Item("Your phone", 1, 11));
    g = new Room("in your closet,\n\"I remember I got stuck in here before\"");

    h = new Room("in your Bathroom,\n\"I dont need the bathroom right now\"");

    i = new Room("in the kitchen,\n\"I'm not hungry right now\"");

    j = new Room("outside");

//             (N, E, S, W)
	a->setExits(f, b, d, c);
	b->setExits(NULL, NULL, NULL, a);
	c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, j, i);
	e->setExits(NULL, NULL, NULL, d);
	f->setExits(NULL, g, a, h);
	g->setExits(NULL, NULL, NULL, f);
	h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
    j->setExits(d, NULL, NULL, NULL);

    rooms.push_back(*a);
    rooms.push_back(*b);
    rooms.push_back(*c);
    rooms.push_back(*d);
    rooms.push_back(*e);
    rooms.push_back(*f);
    rooms.push_back(*g);
    rooms.push_back(*h);
    rooms.push_back(*i);
    rooms.push_back(*j);

    currentRoom = f;
}

/**
 *  Main play routine.  Loops until end of play.
 */

/*void ZorkUL::play() {
	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

	bool finished = false;
	while (!finished) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << endl;
	cout << "end" << endl;
}*/

string ZorkUL::printWelcome() {
    /*
    cout << "start"<< endl;
	cout << "info for help"<< endl;
	cout << endl;
	cout << currentRoom->longDescription() << endl;
    */
    return "Hello Gamer, You have one mission! \nYou have to go outside \n\n"
           "Click the \"How to play\" button for help!" + currentRoom->longDescription();
}

string ZorkUL::printEnd() {
    return "end";
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
/*
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        cout << "[Your Bathroom] --- [Your Bedroom] --- [Your closet]" << endl;
        cout << "                          |         " << endl;
        cout << "                          |         " << endl;
        cout << "[Sisters room] --- [The stairs] --- [parents room]" << endl;
        cout << "                          |         " << endl;
        cout << "                          |         " << endl;
        cout << "[Kitchen]      --- [The porch] --- [Sttting Room]" << endl;
        cout << "                          |         " << endl;
        cout << "                          |         " << endl;
        cout << "                   [The outside]        " << endl;

		}

    else if (commandWord.compare("teleport") == 0)
    {
       teleport();
    }



    else if (commandWord.compare("go") == 0){
		goRoom(command);
    }

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }

    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }

    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
            return true; signal to quit
	}
    return false;
}
*/

/** COMMANDS **/
string ZorkUL::printMap() {
    string output;
    output +=  "[Your Bathroom] --- [Your Bedroom] ---   [Your closet]                \n" ;
    output +=  "                                                 |                                                                    \n" ;
    output +=  "[Sisters room]    -----   [The Hall]    -----    [parents room]            \n" ;
    output +=  "                                                 |                                  \n" ;
    output +=  "[Kitchen]      -------      [The porch]    ----- [Sttting Room]             \n" ;
    output +=  "                                                 |                                  \n" ;
    output +=  "               	          [The outside]                     \n" ;

    output += currentRoom->longDescription();
    output +=  "\n" ;
    return output;
}

string ZorkUL::printHelp() {
    //cout << "valid inputs are; " << endl;
    return "Click the button that you would like to do,"
           " eg if you want to go north then click go north ";

}

string ZorkUL::printWordle() {
    //cout << "valid inputs are; " << endl;
    return "I couldn't get my wordle code to work, so heres a link to the wordle site: https://www.nytimes.com/games/wordle/index.html" ;

}


string ZorkUL::teleport() {
    currentRoom = &rooms.at((int) rand() % rooms.size());

    return currentRoom->longDescription();
   }

/*
void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}
*/

string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}

string ZorkUL::viewItems() {
    return currentRoom->displayItem();
}

Room ZorkUL::getCurrentRoom() {
    return *currentRoom;
}
