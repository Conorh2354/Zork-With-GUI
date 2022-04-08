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
    vector<Item> itemsInCharacter;
public:

    Character(string description);
    string shortDescription();
    string longDescription();
    vector<Item> viewItems();

    Item findItem(Item item);
    int findItemPos(Item item);
    void removeItem(Item item);

    void addItems(string Item);
    void addItem(Item *item);
    void addItem(Item &item);

};

#endif
