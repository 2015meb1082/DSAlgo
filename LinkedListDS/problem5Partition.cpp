// Problem- Write code to partition a singly linked list around a value x, such that all values less than x comes
// before all values greater than and equal to x. If x appears in the list, then it can appear anywhere in
// the right partition. It doesn't need to appear between left and right partition
// eg: Input: 3->5->8->5->10->2->1   x=5
// output can be 3->1->2->10->5->5->8

#include<iostream>
#include "LinkedList.hpp"

//O(n) - Time complexity, O(1) - Space Complexity, It is not a stable algorithm. It rearranges elements
// in the output
Node* Partition(Node *current,int x){
    if(!current){
        return NULL;
    }
    Node *newHead=current,*newTail=current, *next ;
    
    while(current!=NULL){
        next = current->next;
        if(current->data<x){
            //Add in front
            current->next =newHead;
            newHead = current;

        }else{
            //Add in the back 
            newTail->next = current;
            newTail = current;
        }
        current=next;
    }
    newTail->next=NULL;
    return newHead;
}

int main(){
    LinkedList *list = new LinkedList();
    list->PushBack(3);
    list->PushBack(5);
    list->PushBack(8);
    list->PushBack(5);
    list->PushBack(10);
    list->PushBack(2);
    list->PushBack(1);
    list->Print();
    int x;
    std::cout<<"Enter x: \n";
    std::cin>>x;
    list->SetHead(Partition(list->Head(),x));
    list->Print();
    return 0;
}


