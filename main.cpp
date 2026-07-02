#include <iostream>

using namespace std;

int main()
{
    int choice;
    int difficulty;

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
        cout << "\n=====================================\n";
        cout << "       Choose Difficulty\n";
        cout << "=====================================\n";
        cout << "1. Easy (1-50)\n";
        cout << "2. Medium (1-100)\n";
        cout << "3. Hard (1-500)\n";

        cout << "\nEnter difficulty: ";
        cin >> difficulty;

        if (difficulty == 1)
        {
            cout << "\nEasy Mode Selected.\n";
        }
        else if (difficulty == 2)
        {
            cout << "\nMedium Mode Selected.\n";
        }
        else if (difficulty == 3)
        {
            cout << "\nHard Mode Selected.\n";
        }
        else
        {
            cout << "\nInvalid Difficulty!\n";
        }
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