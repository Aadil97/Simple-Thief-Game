#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    //Welcome message
    std::cout << "\nYou are a master thief hacking to a level " << Difficulty << " vault\n";
    std::cout << "There are three numbers in the code\n";
}

bool Play(int Difficulty){

    const int CodeA = (rand() % Difficulty)+Difficulty;
    const int CodeB = (rand() % Difficulty)+Difficulty;
    const int CodeC = (rand() % Difficulty)+Difficulty;

    int sum = CodeA+CodeB+CodeC;
    int product = CodeA*CodeB*CodeC;
    PrintIntroduction(Difficulty);
    std::cout << "\nthe sum of the numbers is: " << sum;
    std::cout << "\nthe product of the numbers is: " << product << std::endl;

    //Player guesses
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;
    std::cout << "\nYou entered: " << GuessA << GuessB << GuessC;
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if the player has won the game
    if (GuessSum == sum && GuessProduct == product){
        std::cout << "\nYou win";
        return true;
    }
    else {
        std::cout << "\nYou lose\n";
        std::cout << "The answer was: " << GuessA << GuessB << GuessC << std::endl;
        return false;
    }
}

int main()
{
    srand(time(NULL)); //Creates a new random sequence based on time of day
    int LevelDifficulty = 1;
    int const MaxDifficulty = 7;
    while(LevelDifficulty<= MaxDifficulty)
    {
        bool LevelComplete = Play(LevelDifficulty);
        std::cin.clear(); //clears errors
        std::cin.ignore(); //discards errors
        if (LevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    std::cout << "\nCongradulations!\n You've completed the game!";
    return 0;
}