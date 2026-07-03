#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

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

        // ================= MAIN MENU =================

        while (true)
        {
            cout << "\n=====================================\n";
            cout << "       NUMBER GUESSING GAME\n";
            cout << "=====================================\n";
            cout << "1. Start Game\n";
            cout << "2. Exit\n";
            cout << "=====================================\n";

            cout << "Enter your choice: ";

            if (!(cin >> choice))
            {
                cout << "\nInvalid input! Please enter 1 or 2.\n";

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (choice == 1 || choice == 2)
            {
                break;
            }

            cout << "\nInvalid choice! Please enter 1 or 2.\n";
        }

        if (choice == 2)
        {
            cout << "\nThank you for playing!\n";
            break;
        }

        // ================= DIFFICULTY =================

        while (true)
        {
            cout << "\n=====================================\n";
            cout << "       Choose Difficulty\n";
            cout << "=====================================\n";
            cout << "1. Easy (1-50)\n";
            cout << "2. Medium (1-100)\n";
            cout << "3. Hard (1-500)\n";

            cout << "Enter difficulty: ";

            if (!(cin >> difficulty))
            {
                cout << "\nInvalid input! Please enter a number between 1 and 3.\n";

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                continue;
            }

            if (difficulty == 1)
            {
                maxNumber = 50;
                cout << "\nEasy Mode Selected.\n";
                break;
            }
            else if (difficulty == 2)
            {
                maxNumber = 100;
                cout << "\nMedium Mode Selected.\n";
                break;
            }
            else if (difficulty == 3)
            {
                maxNumber = 500;
                cout << "\nHard Mode Selected.\n";
                break;
            }
            else
            {
                cout << "\nInvalid choice! Please choose a difficulty level between 1 and 3.\n";
            }
        }

        // ================= RANDOM NUMBER =================

        secretNumber = rand() % maxNumber + 1;

        cout << "\nYou have only " << MAX_ATTEMPTS << " attempts.\n";

        // ================= GAME LOOP =================

        while (attempts < MAX_ATTEMPTS)
        {
            attempts++;

            cout << "\n-------------------------------------\n";
            cout << "Attempt " << attempts << "/" << MAX_ATTEMPTS << endl;

            cout << "Enter your guess (1-" << maxNumber << "): ";

            if (!(cin >> guess))
            {
                cout << "\nInvalid input! Please enter numbers only.\n";

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                attempts--;

                continue;
            }

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

        // ================= GAME OVER =================

        if (!guessed)
        {
            cout << "\n=====================================\n";
            cout << "Game Over!\n";
            cout << "Better Luck Next Time.\n";
            cout << "The Secret Number was: " << secretNumber << endl;
            cout << "=====================================\n";
        }

        // ================= PLAY AGAIN =================

        while (true)
        {
            cout << "\nDo you want to play again? (Y/N): ";

            if (!(cin >> playAgain))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (playAgain == 'Y' || playAgain == 'y' ||
                playAgain == 'N' || playAgain == 'n')
            {
                break;
            }

            cout << "\nInvalid choice! Please enter Y or N.\n";
        }

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThanks for playing!\n";

    return 0;
}