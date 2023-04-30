#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

int main()
{
    std::ifstream file;
    std::string char_array;

//load quant
    file.open( "quant.txt", std::ios::in | std::ios::out );

    std::getline(file, char_array); 
    file.close();

    int length = char_array.length();

    int quant[5];
for (int i = 0; i < length; i++)
    {

        quant[i] = static_cast<int>(char_array[i]) - '0';

    }
//replenish
for (int i = 0; i < 5; i++)
{
    if (quant[i]==0)
    {
        quant[i]=5;
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
//Display products
            for (int i = 0; i < 5; i++)
            {
                std::cout << "\nProduct " << i << ", in stock: " << quant[i] << std::endl;
            }

            
            
            takeOrder(order);

            execOrder(order,quant);
        }
        else code=1234;


        
    }
//save quant to txt file
    std::ofstream outputFile("quant.txt");
    for (int i = 0; i < 5; i++) {
        outputFile << std::to_string(quant[i]);
    }
    return 0;
}

void takeOrder(int* order)
{

    std::cout << "What Product do u wish to order? \n>>";
    std::cin >> order[0];
    std::cout << "What will be the quantity of your order? \n>>";
    std::cin >> order[1];
}

void execOrder(int order[2], int* quant)
{
    if (order[1] > quant[order[0]])
        std::cout << "The quantity chosen exeeds the number in stock\n";
    else
    {
        std::cout << "\nDispenced Product " << order[0] << " in amount " << order[1] << "\n";
        quant[order[0]] -= order[1];
    }
}
