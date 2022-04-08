These are all the changes I Have made to the orignal zork code provided to us:

	* Character.h
//Added friend class MainWindow

//Changed <string> to <item> itemsInCharacter it fixed a problem

// put everything into one public class

// added void addItem(Item *item); and void addItem(Item &item); 


	* Command.h
// didnt change

	* CommandsWords.h
// didnt change

	* Item.h
// didnt change


	* Parser.h
// didnt change

	* Room.h
// friend class MainWindow;

	* ZorkUL.h
// moved some functions to public and create more functions like
	welcome, teleport, printmap, printwordle,

	* Character.cpp
// deleted the /* and the x after character.

	* command.cpp
// didnt change

	* command.cpp
// didnt change

	* commandwords.cpp
// added teleport

	* item.cpp
// didnt change

	* parser.cpp
// didnt change

	* Room.cpp
// didnt change

	* Wordle.cpp
// created but never used. 
// There's some wordle code in there I found online

	* parser.cpp
// didnt change


	*ZorkUL.cpp
// deleted int main since theres mainwindow now
// deleted play()
// made new printwelcome.. just changed cout to return with some text and 
displays current room
// created printend() for when the game is over
// stopped used process command (since we are using buttons theres no need for it)
// redid print help for return instead of cout
// made printmap(), print wordle(), teleport() 
// made viewitems() + getCurrentRoom()


	*mainwindow.ul
//The GUI

	*words.txt
//The .txt file for wordle




































