#include <iostream>
#include <cstdlib> 
#include <ctime>    
using namespace std;
void welcomePlayer() {
    cout << "========================================" << endl;
    cout << "  Welcome to the Guessing Number Game!   " << endl;
    cout << "========================================" << endl;
    cout << "I am thinking of a number between 1 and 50." << endl;
    cout << "Can you guess what it is? Let's find out!" << endl;
    cout << "I will help you with hints like 'too high' or 'too low'." << endl;
    cout << "Good luck! \n" << endl;
}

int generateSecretNumber() {
    srand(static_cast<unsigned int>(time(0)));  
    return rand() % 50 + 1;  
}

int getGuessFromPlayer() {
    int guess;
    cout << "Your guess: ";
    while (!(cin >> guess) || guess < 1 || guess > 50) {
        cin.clear();  
        cin.ignore(1000, '\n');  
        cout << "Please enter a valid number between 1 and 50: ";
    }
    return guess;
}

void giveFeedback(int guess, int secretNumber) {
    if (guess > secretNumber) {
        cout << "Too high! Try a smaller number.\n" << endl;
    } else if (guess < secretNumber) {
        cout << "Too low! Try a larger number.\n" << endl;
    } else {
        cout << " Hooray! You got it right! \n" << endl;
    }
}

int main() {
    welcomePlayer();

    int secretNumber = generateSecretNumber();
    int guess;
    int attempts = 0;
    bool isCorrect = false;

    while (!isCorrect) {
        guess = getGuessFromPlayer();
        attempts++;

        giveFeedback(guess, secretNumber);

        if (guess == secretNumber) {
            isCorrect = true;
        }
    }

    cout << "You guessed the secret number in " << attempts << " attempts!" << endl;
    cout << "Thanks for playing! Come back soon!" << endl;

    return 0;
}
