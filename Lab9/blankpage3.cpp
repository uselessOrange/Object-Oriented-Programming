#include <iostream>

void my_rand(int* randomNumberVector, int rows, int minNumber, int maxNumber) {
  for (int i = 0; i < rows; i++) {
    randomNumberVector[i] = i;
    std::cout << randomNumberVector[i] << std::endl;
  }
}

int main() {
  const int rows = 5;
  int randomNumberVector[rows];
  int minNumber = 0;
  int maxNumber = 100;

  my_rand(randomNumberVector, rows, minNumber, maxNumber);

  return 0;
}
