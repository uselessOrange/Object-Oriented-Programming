#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Lab6_Functions.cpp"






int main()
{
    std::ifstream file;
    std::string char_array;

//load quant
    file.open( "quant.txt", std::ios::in | std::ios::out );

    std::getline(file, char_array); 
    file.close();

    int length = char_array.length();

    Stock Products;


for (int i = 0; i < length; i++)
    {

        Products.Quantity[i] = static_cast<int>(char_array[i]) - '0';

     

    }
//replenish
for (int i = 0; i < 5; i++)
{
    if (Products.Quantity[i]==0)
    {
        Products.Quantity[i]=5;
    }
    else;
}



    
    int code;

    int order[2]={0,0};


    void takeOrder(int*);
    void execOrder(int*,int*);

    while (code != 1234)
    {
        std::cout << "To start ordering enter 1 >>";
        std::cin >> code;

        if (code != 1234)
        {
            void loadCost(float*);
            loadCost(Products.Price);
            //Display products

            Products.printInfo();
            
            
            takeOrder(order);

            execOrder(order,Products.Quantity);
        }
        else code=1234;


        
    }
//save quant to txt file
    std::ofstream outputFile("quant.txt");
    for (int i = 0; i < 5; i++) {
        outputFile << std::to_string(Products.Quantity[i]);
    }
    return 0;
}






