#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("falloutBoy.txt"); // Replace "example.txt" with the path to your text file

    if (!inputFile.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }
    std::cout << "hello" << std::endl;
    inputFile.close();

    return 0;
}
