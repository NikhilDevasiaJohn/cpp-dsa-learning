#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    bool exit = false;
    while (!exit) {
        system("cls"); // Clear the console screen
        int choice;
        cout << "Main Menu:" << endl;
        cout << "1. Say Hello" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Hello, User!" << endl;
            Sleep(2000); // Pause for 2 seconds
        } else if (choice == 2) {
            exit = true;
        }
    }
    return 0;
}
