#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip> // For std::setw

using namespace std;

// Function to display the game header
void displayHeader() {
    cout << "+-------------------------------+" << endl;
    cout << "|   Welcome to the Guessing Game!  |" << endl;
    cout << "+-------------------------------+" << endl;
}

// Function to display the footer
void displayFooter() {
    cout << "+-------------------------------+" << endl;
    cout << "|   Thank you for playing!       |" << endl;
    cout << "+-------------------------------+" << endl;
}

// Function to display the game rules
void displayInstructions(int maxAttempts) {
    cout << "I've picked a number between 1 and 100." << endl;
    cout << "You have " << maxAttempts << " attempts to guess it." << endl;
    cout << "Good luck!" << endl << endl;
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int targetNumber = rand() % 100 + 1;

    int userGuess = 0;
    int attempts = 0;
    const int maxAttempts = 7; // Limit the number of attempts
    bool correctGuess = false;

    displayHeader();
    displayInstructions(maxAttempts);

    while (!correctGuess && attempts < maxAttempts) {
        cout << setw(30) << left << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        if (userGuess < targetNumber) {
            cout << "Too low! Try again." << endl;
        } else if (userGuess > targetNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            correctGuess = true;
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts!" << endl;
        }

        if (!correctGuess) {
            cout << "Attempts left: " << maxAttempts - attempts << endl;
        }
        cout << endl;
    }

    if (!correctGuess) {
        cout << "Sorry, you've used all your attempts. The number was " << targetNumber << "." << endl;
    }

    displayFooter();

    return 0;
}