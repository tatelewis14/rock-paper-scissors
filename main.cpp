#include <iostream>
#include<string>
#include <cctype>
#include<vector>
#include <cstdlib>
#include <ctime> 


void askMove(std::string &move)
{
    std::cout << "Enter rock, paper, or scissors: " << std::endl;
    std::cin >> move;
    while(move!= "rock" && move!="paper" && move!="scissors") {
        std::cout<<"Invalid answer"<<std::endl;
        std::cin >> move;
        
    }
    
}


   std::string getRandomResponse()
{
    std::vector<std::string> responses = {"rock", "paper", "scissors"};  // Add your responses here
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
    int randomIndex = rand() % responses.size();  // Generate a random index
    return responses[randomIndex];  // Return the randomly selected response
}

std::string playerWon(std::string userMove, std::string computerMove)
{
    if(userMove == computerMove) {
        return "tied";
    }
    if(userMove == "rock" && computerMove == "scissors") {
        return "won";
    }
    
    if(userMove == "paper" && computerMove == "rock") {
        return "won";
    }
    if(userMove == "scissors" && computerMove == "paper") {
        return "won";
    }
    return "lost";
    
}

void game() {
    std::string playerMove;
    askMove(playerMove);
    std::cout << "You played the move: " << playerMove << std::endl; 
    std::string compMove = getRandomResponse();
    std::cout << "Computer played the move: " << compMove<<std::endl;
    std::cout <<"You "<<playerWon(playerMove, compMove) << "!"<< std::endl;
}


int main()
{
    
    game();
    bool playing = true;
    
   while(playing) {
       game();
   }
   
    
    return 0;
}
