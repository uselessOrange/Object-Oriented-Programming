#include <iostream>
#include <vector>
#include <random>

void my_rand(std::vector<std::vector<int>>* randomNumberVector, int rows, int columns, int minNumber, int maxNumber) {
  for (int i = 0; i < rows; i++) {
    for (int k = 0; k < columns; k++) {
      std::random_device rd;
      std::mt19937 rng(rd());
      std::uniform_int_distribution<int> uni(minNumber, maxNumber);

      (*randomNumberVector)[i][k] = uni(rng);
    }
  }
}

int main() {
  const int rows = 3;
  const int columns = 4;
  std::vector<std::vector<int>> randomNumberVector(rows, std::vector<int>(columns));

  int minNumber = 0;  
  int maxNumber = 100;

  my_rand(&randomNumberVector, rows, columns, minNumber, maxNumber);

  // Print the elements of the vector
  for (int i = 0; i < rows; i++) {
    for (int k = 0; k < columns; k++) {
      std::cout << randomNumberVector[i][k] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
