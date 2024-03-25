/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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

bool playerWon(std::string userMove, std::string computerMove)
{
    if(userMove == computerMove) {
        return false;
    }
    if(userMove == "rock" && computerMove == "scissors") {
        return true;
    }
    
    if(userMove == "paper" && computerMove == "rock") {
        return true;
    }
    if(userMove == "scissors" && computerMove == "paper") {
        return true;
    }
    return false;
    
}

int main()
{
    std::string playerMove;
    askMove(playerMove);
    std::cout << "You played the move: " << playerMove << std::endl; 
    std::string compMove = getRandomResponse();
    std::cout << "Computer played the move: " << compMove<<std::endl;
    if(playerWon(playerMove, compMove)) {
        std::cout << "Player won!" << std::endl;
        return 0;
    }
    std::cout << "Player lost!" << std::endl;
   
   
    
    return 0;
}
