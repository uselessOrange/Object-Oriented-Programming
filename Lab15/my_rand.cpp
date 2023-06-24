#include <iostream>
#include <random>
#include <vector>

int my_rand(int minNumber,int maxNumber) {


  // Obtain a random seed from the system
  std::random_device rd;

  // Initialize the random number engine with the seed
  std::mt19937 rng(rd());

  // Define the distribution and bind it to the random number engine
  std::uniform_int_distribution<int> uni(minNumber, maxNumber);

  // Generate a random number
  int randomNumber = uni(rng);

  return randomNumber;
}


void my_rand(int* randomNumberVector,int rows,int minNumber,int maxNumber) {
for (int i = 0; i < rows; i++) {
   
  


  // Obtain a random seed from the system
  std::random_device rd;

  // Initialize the random number engine with the seed
  std::mt19937 rng(rd());

  // Define the distribution and bind it to the random number engine
  std::uniform_int_distribution<int> uni(minNumber, maxNumber);


  randomNumberVector[i] = uni(rng);
  }
}

void my_rand(std::vector<std::vector<int>>* randomNumberMatrix,int rows,int columns,int minNumber,int maxNumber) {



for (int i = 0; i < rows; i++) {
  for (int k = 0; k < columns; k++) {
    // Obtain a random seed from the system
    std::random_device rd;

    // Initialize the random number engine with the seed
    std::mt19937 rng(rd());

    // Define the distribution and bind it to the random number engine
    std::uniform_int_distribution<int> uni(minNumber, maxNumber);


    (*randomNumberMatrix)[i][k] = uni(rng);
  }
}
}


