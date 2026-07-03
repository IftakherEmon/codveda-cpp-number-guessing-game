#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
int choice;
int difficulty;
int maxNumber;
int secretNumber;
int guess;
int attempts = 0;

    // Initialize random seed
    srand(time(0));

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
            maxNumber = 50;
            cout << "\nEasy Mode Selected.\n";
        }
        else if (difficulty == 2)
        {
            maxNumber = 100;
            cout << "\nMedium Mode Selected.\n";
        }
        else if (difficulty == 3)
        {
            maxNumber = 500;
            cout << "\nHard Mode Selected.\n";
        }
        else
        {
            cout << "\nInvalid Difficulty!\n";
            return 0;
        }

        // Generate random number
        secretNumber = rand() % maxNumber + 1;

        // Temporary output for testing
        cout << "\n[DEBUG] Secret Number: " << secretNumber << endl;
do
{
    attempts++;

    cout << "\n-------------------------------------\n";
    cout << "Attempt #" << attempts << endl;

    cout << "Enter your guess (1-" << maxNumber << "): ";
    cin >> guess;
    // Validate guess range
if (guess < 1 || guess > maxNumber)
{
    cout << "\nInvalid input! Please enter a number between 1 and "
         << maxNumber << ".\n";

    attempts--;

    continue;
}

    if (guess > secretNumber)
    {
        cout << "Too High! Try again.\n";
    }
    else if (guess < secretNumber)
    {
        cout << "Too Low! Try again.\n";
    }
    else
    {
        cout << "\n=====================================\n";
        cout << "Congratulations! \n";
        cout << "You guessed the correct number.\n";
        cout << "Total Attempts: " << attempts << endl;
        cout << "=====================================\n";
    }

} while (guess != secretNumber);
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