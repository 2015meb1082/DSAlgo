// Given only access a node in the middle (i.e any node but the first and last node) of a single Linked list
// Delete the Node
// eg: a-->b-->c-->d-->e-->f    Input is the address of node c of the Linked List
// a->b->d->e->f                Output

#include<iostream>
#include "LinkedList.hpp"

// O(1) -Time complexity
void DeleteNode(Node *midNode){
    Node *nextToMidNode = midNode->next;
    midNode->data=nextToMidNode->data;
    midNode->next= nextToMidNode->next;
    delete nextToMidNode;
}

int main(){
    LinkedList *list = new LinkedList();
    for(int i=0;i<7;i++){
        list->PushBack(i+1);
    }
    list->Print();
    std::cout<<"mid node is : "<<list->FindMidNode()->data<<"\n";
    DeleteNode(list->FindMidNode());
    std::cout<<"Finally, after the deletion the mid node linked list looks like:\n";
    list->Print();
    return 0;
}

