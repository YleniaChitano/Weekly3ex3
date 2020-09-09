#include <iostream>
#include <cstdlib>


int main() {
    std::srand(8346);
    int player{ 1 };
beginning:
    
     

        std::string name;
        std::cout << "What's your name?\n";
        std::cin >> name;
        int score{ 10000 };
        int times{ 1 };
        int random = std::rand();
        int guess;
    question:

        std::cout << "Try to guess the number I have thought. Please enter a number:\n";
        std::cin >> guess;





        if (guess == random) {
            char yn;
            std::cout << "That's correct! You won! It took you " << times << " guess(es).\n";
            std::cout << "Your score is " << score << ". You are player number " << player <<".\n";
            std::cout << "HIGH SCORE LIST: \n";
            
            player++;
            std::cout << "Do you want to play again (Y / N) ? \n";
            std::cin >> yn;
            yn = toupper(yn);
            if (yn == 'Y') {
                int random = std::rand();
                goto beginning;
            }

        }


        else {
            times++;
            score = (score - 100);
            if (guess < random) {
                std::cout << "Nope, try a higher number!\n";
                goto question;
            }
            else {
                std::cout << "Nope, try a lower number!\n";
                goto question;
            }
        }
    
        return 0;
    
}
