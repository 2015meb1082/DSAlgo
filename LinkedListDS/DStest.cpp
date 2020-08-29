#include<iostream>
#include "LinkedList.hpp"

int main(){
    LinkedList *list = new LinkedList();
    list->Print();
    std::cout<<"Size is : "<<list->Size()<<"\n";

    list->PushFront(10);
    list->PushFront(1);
    list->PushFront(89);

    list->Print();
    std::cout<<"Size is : "<<list->Size()<<"\n";

    list->PushFront(67);
    list->PushFront(36);

    list->Print();
    std::cout<<"Size is : "<<list->Size()<<"\n";

    list->PushFront(0);
    list->PushFront(111);

    list->Print();
    std::cout<<"Size is : "<<list->Size()<<"\n";

    list->PopBack();

    list->Print();
    std::cout<<"Size is : "<<list->Size()<<"\n";

    list->PushBack(78);
    list->PopFront();

    list->Print();
    std::cout<<"Size is : "<<list->Size()<<"\n";
    
    list->PopFront();
    
    list->Print();
    std::cout<<"Size is : "<<list->Size()<<"\n";

    list->DeleteLinkedList();
    list->Print();
    list->Size();
    return 0;
}