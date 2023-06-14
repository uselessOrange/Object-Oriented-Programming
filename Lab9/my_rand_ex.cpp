#include<iostream>
#include<cstdlib>
#include<vector>
#include "my_rand.cpp"
#include  "my_rand_ex.hpp"


int main(){



std::cout<<my_rand(0,9)<<std::endl;


int length=5;
int randomNumberVector[length];
my_rand(randomNumberVector,length,0,9);

for (int i = 0; i < length; i++)
{
  std::cout << randomNumberVector[i] <<std::endl;
}


const int rows = 3;
const int columns = 4;
  int minNumber = 0;  
  int maxNumber = 9;

std::vector<std::vector<int>>
randomNumberMatrix(rows, std::vector<int>(columns));

  my_rand(&randomNumberMatrix, rows, columns, minNumber, maxNumber);

  // Print the elements of the vector
  for (int i = 0; i < rows; i++) {
    for (int k = 0; k < columns; k++) {
      std::cout << randomNumberMatrix[i][k] << " ";
    }
    std::cout << std::endl;
  }

return 0;
}
