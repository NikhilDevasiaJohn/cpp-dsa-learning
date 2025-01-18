#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class Bill {
private:
    string Item;
    int Rate;
    int Quantity;

public:
    // Default Constructor
    Bill(): Item(""), Rate(0), Quantity(0) {

    }

    // Setter for Item
    void setItem(string item) {
        Item = item;
    }

    // Setter for Rate
    void setRate(int rate) {
        Rate = rate;
    }

    // Setter for Quantity
    void setQuantity(int quantity) {
        Quantity = quantity;
    }
};
