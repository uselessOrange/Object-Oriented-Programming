#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

class Stock {
  public:
    std::string Product[5];
    int Quantity[5];
    float Price[5];

    void printInfo() {
        for (int i = 0; i < 5; i++)
        {
                std::cout << "\nProduct " << i << ", in stock: " << Quantity[i] <<" Price: "<<Price[i]<< std::endl;
        }
    }
};


void takeOrder(int* order)
{

    std::cout << "What Product do u wish to order? \n>>";
    std::cin >> order[0];
    std::cout << "What will be the quantity of your order? \n>>";
    std::cin >> order[1];
}


void execOrder(int order[2], int* quant)
{

    void transaction(float*,int*);


    if (order[1] > quant[order[0]])
        std::cout << "The quantity chosen exeeds the number in stock\n";
    else
    {
        Stock Products;
        void loadCost(float*);
        loadCost(Products.Price);
        transaction(Products.Price,order);
        std::cout << "\nDispenced Product " << order[0] << " in amount " << order[1] << "\n";
        quant[order[0]] -= order[1];
}
}

void transaction(float* cost,int order[2])
{
    float OrderCost;
    float paid;
    float toGiveBack;
    int moneyCheck=0;
    std::cout<<order[0]<<order[1]<<std::endl;
    OrderCost=order[1]*cost[order[0]];

    while (moneyCheck==0)
    {
        std::cout<<"Your order costs "<<OrderCost<<std::endl
        <<"Enter money>>"<<std::endl;
        std::cin>>paid;
        if (paid<order[1]*cost[order[0]])
            std::cout<<"Not enough credit"<<std::endl;
        else
            moneyCheck=1;   
    }

    
    toGiveBack=paid-OrderCost;
    std::cout<<"Your change>>"<<toGiveBack<<std::endl;
}

void loadCost(float* cost){
    //load cost.txt

        std::ifstream file;
        std::string char_array;

        file.open( "cost.txt", std::ios::in | std::ios::out );

        std::getline(file, char_array); 
        file.close();

        int length = char_array.length();

    
        for (int i = 0; i < length; i++)
        {

            cost[i] = static_cast<float>(char_array[i]) - '0';

    }

}



