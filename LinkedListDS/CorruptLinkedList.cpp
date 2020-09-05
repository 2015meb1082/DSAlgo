#include "CorruptLinkedList.hpp"
#include<iostream>
#include<stdlib.h>

CorruptLinkedList::CorruptLinkedList(){
    head=NULL;
    tail=NULL;
    count=0;
}
void CorruptLinkedList::PushBack(int data){
    ++count;
    Node *newNode = new Node(data);
    if(!head){
        head=newNode;
        tail =newNode;
    }
    tail->next=newNode;
    tail=newNode;
}
void CorruptLinkedList::Print(){
    Node *current= head;
    while(current!=NULL){
        std::cout<<current->data<<"->";
        current=current->next;
    }
    std::cout<<"\n";
}

Node* CorruptLinkedList::CorruptList(){
    Node *current =head;int k=0;
    srand((unsigned int)time(NULL));
    int randomPosition = rand()%(count)+1;
    std::cout<<randomPosition<<"\n";
    std::cout<<"Count is: "<<count<<"\n";
    while(current!=NULL && k<randomPosition-1){
        k++;
        current=current->next;
    }
    tail->next=current;
    return current;
}