#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

const int MAX_ATTEMPTS = 6;

int showMainMenu();

int chooseDifficulty();

void playGame(int maxNumber);

char askPlayAgain();

bool confirmQuit();

int main()
{
    srand(time(0));

    char playAgain;

    do
    {
        int choice = showMainMenu();

        if (choice == 2)
        {
            cout << "\nThank you for playing!\n";
            break;
        }

        int maxNumber = chooseDifficulty();

        playGame(maxNumber);

        playAgain = askPlayAgain();

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThanks for playing!\n";

    return 0;
}
int showMainMenu()
{
    int choice;

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
            return choice;
        }

        cout << "\nInvalid choice! Please enter 1 or 2.\n";
    }
}
int chooseDifficulty()
{
    int difficulty;
    int maxNumber;

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

        switch (difficulty)
        {
        case 1:
            cout << "\nEasy Mode Selected.\n";
            maxNumber = 50;
            return maxNumber;

        case 2:
            cout << "\nMedium Mode Selected.\n";
            maxNumber = 100;
            return maxNumber;

        case 3:
            cout << "\nHard Mode Selected.\n";
            maxNumber = 500;
            return maxNumber;

        default:
            cout << "\nInvalid choice! Please choose between 1 and 3.\n";
        }
    }
}
void playGame(int maxNumber)
{
    int secretNumber = rand() % maxNumber + 1;
    int guess;
    int attempts = 0;
    bool guessed = false;

    cout << "\nYou have only " << MAX_ATTEMPTS << " attempts.\n";
    cout << "Enter 0 anytime if you want to quit the game.\n";

    while (attempts < MAX_ATTEMPTS)
    {
        cout << "\n-------------------------------------\n";
        cout << "Attempt " << attempts + 1 << "/" << MAX_ATTEMPTS << endl;

        cout << "Enter your guess (1-" << maxNumber << "): ";

        if (!(cin >> guess))
        {
            cout << "\nInvalid input! Please enter numbers only.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        // ================= QUIT OPTION =================

        if (guess == 0)
        {
            if (confirmQuit())
            {
                cout << "\n=====================================\n";
                cout << "Thanks for playing!\n";
                cout << "The Secret Number was: " << secretNumber << endl;
                cout << "=====================================\n";

                return;
            }
            else
            {
                continue;
            }
        }

        // ================= RANGE VALIDATION =================

        if (guess < 1 || guess > maxNumber)
        {
            cout << "\nInvalid input! Please enter a number between 1 and "
                 << maxNumber << ".\n";

            continue;
        }

        attempts++;

        // ================= GUESS CHECK =================

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

if (attempts == 1)
{
    cout << "Performance: Outstanding! 🌟\n";
}
else if (attempts <= 3)
{
    cout << "Performance: Excellent! 🔥\n";
}
else if (attempts <= 5)
{
    cout << "Performance: Good Job! 😊\n";
}
else
{
    cout << "Performance: Nice Try! 👍\n";
}

cout << "=====================================\n";

            return;
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
}
bool confirmQuit()
{
    char choice;

    while (true)
    {
        cout << "\nAre you sure you want to quit? (Y/N): ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 'Y' || choice == 'y')
        {
            return true;
        }

        if (choice == 'N' || choice == 'n')
        {
            return false;
        }

        cout << "\nInvalid choice! Please enter Y or N.\n";
    }
}
char askPlayAgain()
{
    char choice;

    while (true)
    {
        cout << "\n=====================================\n";
        cout << "Do you want to play again? (Y/N): ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 'Y' || choice == 'y' ||
            choice == 'N' || choice == 'n')
        {
            return choice;
        }

        cout << "\nInvalid choice! Please enter Y or N.\n";
    }
}
