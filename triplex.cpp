#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
  // Prints welcome message to terminal
  if (Difficulty ==1)
  {
      std::cout << "\n\nAfter a brutal struggle, Jigsaw lies dead at your feet; you come to a door with a screen and a keypad...\n";
  }
  else
  {
    std::cout << "\n\nYou proceed to a short hallway to yet another door...\n";
  }
  std::cout << "The screen says 'The level of difficulty is " << Difficulty;
  std::cout << ". Enter the correct code and you are one step closer to being free'!\n\n";
}

bool PlayGame(int Difficulty)
{
  PrintIntroduction(Difficulty);
  // Declare three number code
  const int CodeA = rand() % Difficulty + Difficulty;
  const int CodeB = rand() % Difficulty + Difficulty;
  const int CodeC = rand() % Difficulty + Difficulty;
  /*
  this is a multi-line comment
  */

  const int CodeSum = CodeA + CodeB + CodeC;
  const int CodeProduct = CodeA * CodeB * CodeC;
  // Print CodeSum and CodeProduct
  std::cout << std::endl;
  std::cout << "+ There are three numbers in the code";
  std::cout << "\n+ The code adds up to: " << CodeSum;
  std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

  // Store player guess
  int GuessA, GuessB, GuessC;
  
  // Player input
  std::cin >> GuessA >> GuessB >> GuessC;

  int GuessSum = GuessA + GuessB + GuessC;
  int GuessProduct = GuessA * GuessB * GuessC;

  // Check if answers are correct
  if (GuessSum == CodeSum && GuessProduct == CodeProduct)
  {
    std::cout << "\nYou have guessed the correct numbers. You win!";
    return true;
  } 
  else
  {
    std::cout << "\nYou lose. You may never get out!";
    return false;
  }
}

int main()
{
  srand(time(NULL)); // seeds rand with time value to make more random numbers

  int LevelDifficulty = 1;
  const int MaxDifficulty = 5;

  while (LevelDifficulty <= MaxDifficulty) // Loop the game until all levels are completed
  {
    bool bLevelComplete = PlayGame(LevelDifficulty);
    std::cin.clear(); // Clears any errors
    std::cin.ignore(); // Discards the buffer

    if (bLevelComplete)
    {
      ++LevelDifficulty;
    }
  }

  std::cout << "\n***You've outwitted the puzzle master and survived his deadly traps***\n";
  return 0;
}
