#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "ZorkUL.h"

#include <string>
using namespace std;
#include <vector>
using std::vector;

class Character {
    friend class MainWindow;

private:
	string description;
    vector < string > itemsInCharacter;





public:
	Character(string description);
	string shortDescription();
	string longDescription();







    void addItems(string Item);








};

#endif
