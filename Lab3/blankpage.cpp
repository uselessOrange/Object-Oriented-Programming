#include <iostream>

int main() {
    void transaction(float[5],int[2]);
     

    float cost[5]={1,1,1,1,1};
    int order[2]={1,4};

    transaction(cost,order);
return 0;
}

void transaction(float* cost,int order[2])
{
    float OrderCost;
    float paid;
    float toGiveBack;

    OrderCost=order[1]*cost[order[0]];
    std::cout<<"Your order costs "<<OrderCost<<std::endl
    <<"Enter money>>"<<std::endl;
    std::cin>>paid;
    toGiveBack=paid-OrderCost;
    std::cout<<"Your change>>"<<toGiveBack<<std::endl;
}