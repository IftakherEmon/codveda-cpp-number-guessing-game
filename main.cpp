#include <iostream>

using namespace std;

int main()
{
    int choice;

    cout << "=====================================\n";
    cout << "       NUMBER GUESSING GAME\n";
    cout << "=====================================\n";
    cout << "1. Start Game\n";
    cout << "2. Exit\n";
    cout << "=====================================\n";

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "\nStarting the game...\n";
    }
    else if (choice == 2)
    {
        cout << "\nThank you for playing!\n";
    }
    else
    {
        cout << "\nInvalid choice!\n";
    }

    return 0;
}