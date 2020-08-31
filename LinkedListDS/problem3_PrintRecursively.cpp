// Print the reverse single linked list 
// It is done recursively
#include<iostream>
#include "LinkedList.hpp"

void PrintReverse(Node *head){
    if(!head){
        return;
    }
    PrintReverse(head->next);
    std::cout<<head->data<<"--->";
}

int main(){
    LinkedList *list = new LinkedList();
    
    for(int i=0;i<10;i++){ 
        list->PushBack((i+1)*10);
    }
    std::cout<<"Forward Print\n";
    list->Print();

    std::cout<<"Reverse Print\n";
    PrintReverse(list->Head());
    std::cout<<std::endl;
    return 0;
}