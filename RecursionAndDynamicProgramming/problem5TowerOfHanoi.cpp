// Tower of Hanoi problem - recursive solution

#include<iostream>

void TowerOfHanoi(int n, char fromTower,char toTower,char auxTower)
{
    if(n<=0){
        return;
    }
    if(n==1){
        std::cout<<"Move disk "<<n<<" from "<<fromTower<<" to "<<toTower<<"\n";
        return;
    }

    TowerOfHanoi(n-1,fromTower,auxTower,toTower);
    std::cout<<"Move disk "<<n<<" from "<<fromTower<<" to "<<toTower<<"\n";
    TowerOfHanoi(n-1,auxTower,toTower,fromTower);
}

int main(){
    int n;
    std::cout<<"Enter n\n";
    std::cin>>n;
    TowerOfHanoi(n,'A','C','B');
    return 0;
}