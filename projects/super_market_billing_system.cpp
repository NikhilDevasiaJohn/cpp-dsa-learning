#include <iostream> // For input and output operations
#include <fstream> // For file handling
#include <sstream> // For string stream operations
#include <windows.h> // For Sleep and other Windows-specific functions
using namespace std;

// Class to represent a Bill
class Bill {
private:
    string Item; // Name of the item
    int Rate; // Rate of the item
    int Quantity; // Quantity of the item

public:
    // Constructor to initialize default values
    Bill() : Item(""), Rate(0), Quantity(0) {}

    // Setter for Item
    void setItem(string item) {
        Item = item;
    }

    // Setter for Rate
    void setRate(int rate) {
        Rate = rate;
    }

    // Setter for Quantity
    void setQuant(int quant) {
        Quantity = quant;
    }

    // Getter for Item
    string getItem() {
        return Item;
    }

    // Getter for Rate
    int getRate() {
        return Rate;
    }

    // Getter for Quantity
    int getQuant() {
        return Quantity;
    }
};

// Function to add an item to the bill
void addItem(Bill &b) {
    bool close = false; // Flag to track when to close the loop

    while (!close) {
        int choice;
        // Display menu options
        cout << "\t1. Add." << endl;
        cout << "\t2. Close." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice == 1) {
            // Clear screen for better UI experience
            system("cls");
            string item;
            int rate, quant;

            // Input item details
            cout << "\tEnter Item Name: ";
            cin >> item;
            b.setItem(item);

            cout << "\tEnter Rate of Item: ";
            cin >> rate;
            b.setRate(rate);

            cout << "\tEnter Quantity of Item: ";
            cin >> quant;
            b.setQuant(quant);

            // Open the file in append mode to add new items
            ofstream out("C:/cpp-dsa-learning/projects/Bill.txt", ios::app);
            if (!out) {
                cout << "\tError: File Can't Open!" << endl;
            } else {
                // Write item details to the file
                out << b.getItem() << " : " << b.getRate() << " : " << b.getQuant() << endl;
                cout << "\tItem Added Successfully." << endl;
            }
            out.close();
            Sleep(3000); // Pause to show the success message
        } else if (choice == 2) {
            // Exit the loop and go back to the main menu
            system("cls");
            close = true;
            cout << "\tBack to Main Menu!" << endl;
            Sleep(3000);
        }
    }
}

// Function to print the bill and update item quantities
void printBill() {
    system("cls"); // Clear screen for better UI experience
    int count = 0; // To track the total bill amount
    bool close = false; // Flag to track when to close the loop

    while (!close) {
        int choice;
        // Display menu options
        cout << "\t1. Add Bill." << endl;
        cout << "\t2. Close Session." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice == 1) {
            string item;
            int quant;

            // Input item name and quantity required
            cout << "\tEnter Item: ";
            cin >> item;
            cout << "\tEnter Quantity: ";
            cin >> quant;

            ifstream in("C:/cpp-dsa-learning/projects/Bill.txt"); // Open the file to read item details
            ofstream out("C:/cpp-dsa-learning/projects/Bill Temp.txt"); // Temporary file to store updated data

            string line;
            bool found = false; // Flag to check if item is found

            // Read the file line by line
            while (getline(in, line)) {
                stringstream ss(line); // String stream to parse the line
                string itemName;
                int itemRate, itemQuant;
                char delimiter;

                // Extract item details from the line
                ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant;

                if (item == itemName) {
                    found = true; // Mark item as found
                    if (quant <= itemQuant) {
                        // Calculate the amount for the item
                        int amount = itemRate * quant;
                        cout << "\t Item | Rate | Quantity | Amount" << endl;
                        cout << "\t" << itemName << "\t " << itemRate << "\t " << quant << "\t " << amount << endl;

                        // Update the remaining quantity
                        int newQuant = itemQuant - quant;
                        out << itemName << " : " << itemRate << " : " << newQuant << endl;

                        count += amount; // Add to total bill
                    } else {
                        // If quantity is not sufficient
                        cout << "\tSorry, " << item << " is out of stock!" << endl;
                        out << line << endl; // Write original line to temp file
                    }
                } else {
                    // Write other items unchanged to the temp file
                    out << line << endl;
                }
            }

            if (!found) {
                // If item not found in the file
                cout << "\tItem Not Available!" << endl;
            }

            in.close();
            out.close();

            // Replace the original file with the updated file
            remove("C:/cpp-dsa-learning/projects/Bill.txt");
            rename("C:/cpp-dsa-learning/projects/Bill Temp.txt", "C:/cpp-dsa-learning/projects/Bill.txt");
        } else if (choice == 2) {
            // Exit the loop and calculate total bill
            close = true;
            cout << "\tCounting Total Bill..." << endl;
            Sleep(3000);
        }
    }

    // Display the total bill
    system("cls");
    cout << endl << endl;
    cout << "\t Total Bill ----------------- : " << count << endl << endl;
    cout << "\tThanks for Shopping!" << endl;
    Sleep(5000); // Pause to show the total bill message
}

// Main function
int main() {
    Bill b; // Create an object of the Bill class
    bool exit = false; // Flag to track when to exit the program

    while (!exit) {
        system("cls"); // Clear screen for better UI experience
        int val;

        // Display main menu options
        cout << "\tWelcome to Supermarket Billing System" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t1. Add Item." << endl;
        cout << "\t2. Print Bill." << endl;
        cout << "\t3. Exit." << endl;
        cout << "\tEnter Choice: ";
        cin >> val;

        if (val == 1) {
            // Call function to add items
            system("cls");
            addItem(b);
        } else if (val == 2) {
            // Call function to print the bill
            printBill();
        } else if (val == 3) {
            // Exit the program
            system("cls");
            exit = true;
            cout << "\tGoodbye!" << endl;
            Sleep(3000);
        }
    }

    return 0; // Indicate successful execution
}
