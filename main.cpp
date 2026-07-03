#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    const int MAX_ATTEMPTS = 6;

    char playAgain;

    srand(time(0));

    do
    {
        int choice;
        int difficulty;
        int maxNumber;
        int secretNumber;
        int guess;
        int attempts = 0;
        bool guessed = false;

        cout << "\n=====================================\n";
        cout << "       NUMBER GUESSING GAME\n";
        cout << "=====================================\n";
        cout << "1. Start Game\n";
        cout << "2. Exit\n";
        cout << "=====================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 2)
        {
            cout << "\nThank you for playing!\n";
            break;
        }

        if (choice != 1)
        {
            cout << "\nInvalid Choice!\n";
            continue;
        }

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
            continue;
        }

        secretNumber = rand() % maxNumber + 1;

        cout << "\nYou have only " << MAX_ATTEMPTS << " attempts.\n";

        while (attempts < MAX_ATTEMPTS)
        {
            attempts++;

            cout << "\n-------------------------------------\n";
            cout << "Attempt " << attempts << "/" << MAX_ATTEMPTS << endl;

            cout << "Enter your guess (1-" << maxNumber << "): ";
            cin >> guess;

            if (guess < 1 || guess > maxNumber)
            {
                cout << "\nInvalid input! Please enter a number between 1 and "
                     << maxNumber << ".\n";

                attempts--;
                continue;
            }

            if (guess > secretNumber)
            {
                cout << "Too High! Try a smaller number.\n";
            }
            else if (guess < secretNumber)
            {
                cout << "Too Low! Try a larger number.\n";
            }
            else
            {
                guessed = true;

                cout << "\n=====================================\n";
                cout << "Congratulations! You Won!\n";
                cout << "You guessed the number in "
                     << attempts << " attempt(s).\n";
                cout << "=====================================\n";

                break;
            }
        }

        if (!guessed)
        {
            cout << "\n=====================================\n";
            cout << "Game Over!\n";
            cout << "Better Luck Next Time.\n";
            cout << "The Secret Number was: "
                 << secretNumber << endl;
            cout << "=====================================\n";
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThanks for playing!\n";

    return 0;
}