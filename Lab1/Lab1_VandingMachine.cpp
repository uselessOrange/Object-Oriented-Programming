#include <stdlib.h> 
#include <iostream>
// using namespace std;

int main()
{
    int p1 = 5;
    int p2 = 5;
    int p3 = 5;
    int p4 = 5;
    int p5 = 5;

    int quant[5] = {p1, p2, p3, p4, p5};
    int code;

    int takeOrder(int);
    int takeQuantity(int);
    void execOrder(int,int,int*);

    while (code != 1234)
    {
        std::cout << "To start ordering enter 1 >>";
        std::cin >> code;

        if (code != 1234)
        {

            for (int i = 0; i < 5; i++)
            {
                std::cout << "\nProduct " << i << ", in stock: " << quant[i] << std::endl;
            }

            int order = 0;
            int Porder = 1;

            Porder = takeOrder(Porder);
            order = takeQuantity(order);

            execOrder(Porder,order,quant);
        }
        else exit(1);


        
    }
    return 0;
}

int takeOrder(int Porder)
{

    std::cout << "What Product do u wish to order? \n>>";
    std::cin >> Porder;
    return Porder;
}

int takeQuantity(int order)
{
    std::cout << "What will be the quantity of your order? \n>>";
    std::cin >> order;
    return order;
}

void execOrder(int Porder, int order, int* quant)
{
    if (order > quant[Porder])
        std::cout << "The quantity chosen exeeds the number in stock\n";
    else
    {
        std::cout << "\nDispenced Product " << Porder << " in amount " << order << "\n";
        quant[Porder] -= order;
    }
}
