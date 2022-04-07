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
    Character();
    Character(string description);
    string shortDescription();
    string longDescription();
    vector<Item> viewItems();
    Item findItem(Item item);
    int findItemPos(Item item);
    void removeItem(Item item);
    bool isOverencumbered(float maxWeight);
    string viewCharacterInfo();
    void addItem(string itemDescription);
    void addItem(Item *item);
    void addItem(Item &item);
    int getStamina();
    void setStamina(int stamina);
    void decrementStamina();
    int getHealth();
    void setHealth(int health);
    void decrementHealth();
};

#endif
