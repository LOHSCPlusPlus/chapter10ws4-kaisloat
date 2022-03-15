#include "RabbitDataBase.h"
#include "ReadUtils.h"

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_MENU_LEN = 70;
void printMenu(char options[][MAX_MENU_LEN], int numEntries) {
    for (int index = 0; index < numEntries; index++) {
        cout << (index + 1) << ") " << options[index] << endl;
    }
}

// Interact with the database functions using a menu to choose what to do
int main() {
    RabbitDataBase dataBase; 
    int option = 0;
    char menuOptions[][MAX_MENU_LEN]={  "Print rabbit list",
                                        "Save list to file",
                                        "Remove rabbit",
                                        "Add rabbit",
                                        "Quit"};
    dataBase.read();
    do {
        printMenu(menuOptions,5);
        option = readInt("Please select an option: ");
        switch(option) {
            case 1:
                dataBase.print(cout, true);
                break;
            case 2:
                dataBase.save();
                break;
            case 3:
                dataBase.remove();
                break;
            case 4:
                dataBase.add();
                break;
            case 5:
                break;
            default:
                cout << "Invalid option, try again" << endl;
                break;
        }
    }while(option != 5);
    
    return 0;
}
