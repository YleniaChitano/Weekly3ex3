#include <iostream>
#include <cstdlib> // Needed for srand ()
#include <ctime> // Needed for time (0)
#include <vector>
#include <string>


int main() {
    std::vector <std::string> player(10); // Vector for player name
    std::vector <int> NewScore(10); // Vector for saving scores
    srand(std::time(0)); // Generates a new random number, using time as a seed.
    int i{ 0 }; // Counter for player number
beginning: // Will begin from here when a new random number is needed.
    
    int score{ 10000 }; // Max score points
    int times{ 1 }; // Guess counter variable that increments every time the user guesses a number.
    int random = rand(); // "random" is a fixed random number taken from srand above.
    int guess; // The guessed number

    std::cout << "Please enter your name\n";
    std::cin >> player.at(i);
    std::cout << "Try to guess the number I have thought. Please enter a number:\n";
question: // Will go back here when the guessed number is wrong.
    std::cin >> guess;
    std::cout << random;
   

    if (guess == random) {
        char yn;
        std::cout << "\nThat's correct! You won! It took you " << times << " guess(es). " << player.at(i) << ", your score is " << score << ". \n";
        
        if (i > 0) {
            if (score > NewScore.at(i-1)) {
                std::cout << "You beated the score of the previous player!\n";
            }

            else {
                std::cout << "You were not able to beat the score of the previous player :-(\n";
            }
        }
        
        NewScore.at(i) = score;
        

        for (int j = 0; j < player.size(); j++) {

            std::cout << player.at(j) << " "; // Prints out player name
            std::cout << NewScore.at(j) << std::endl; // Prints out score for player number
        }

            std::cout << "Do you want to play again (Y/N) ? \n";
            std::cin >> yn;
            yn = toupper(yn); // Makes yn case insensitive.
            if (yn == 'Y') {
                i++;
                goto beginning;
            }

        
    }

    else {
        times++;
        score = (score - 100);

        if (guess < random) {
            std::cout << "\nNope, try a higher number!\n";
            goto question;
        }
        else {
            std::cout << "\nNope, try a lower number!\n";
            goto question;
        }
    }

    return 0;
}