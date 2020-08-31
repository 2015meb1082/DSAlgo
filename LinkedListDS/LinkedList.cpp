#include<iostream>
#include "LinkedList.hpp"


//Implementation should be in cpp file

//Constructor 
LinkedList::LinkedList(){
    head=NULL;
    count=0;
}

//Push an element to the front
void LinkedList::PushFront(int data){
    Node *newNode = new Node(data);
    count++;
    if(!head){
        head =newNode;
        return;
    }
    newNode->next = head;
    head =newNode;
    
}

void LinkedList::PushBack(int data){
    Node *newNode = new Node(data);
    count++;
    if(!head){
        head =newNode;
        return;
    }
    Node *current = head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next =newNode;
    
}

//Print the Linked List
void LinkedList::Print(){
    if(!head){
        std::cout<<"Ahh! Linked List is Empty\n";
        return;
    }

    Node *current = head;
    while(current!=NULL){
        std::cout<<current->data<<"--->";
        current =current->next;
    }
    std::cout<<"\n";
}

//Number of elements in the list
int LinkedList::Size(){
    return count;
}

//Delete

void LinkedList::PopFront(){
    count--;
    if(!head){
        std::cout<<"Sorry! Empty List!\n";
        return;
    }
    Node *temp = head;
    head =head->next;
    delete temp;
    
}

void LinkedList::PopBack(){
    count--;
    if(!head){
        std::cout<<"Sorry! Empty List!\n";
        return;
    }
    Node *current =head, *prev;
    while(current->next!=NULL){
        prev = current;
        current= current->next;
    }
    prev->next = NULL;
    delete current;
   

}

//Deleting the Entire Linked List

void LinkedList::DeleteLinkedList(){
    Node *temp;
    while(head!=NULL){
        temp = head;
        head=head->next;
        delete temp;
    }
    count=0;
    std::cout<<"LINKED LIST DELETED\n";
}

Node* LinkedList::Head(){
    return head;
}
void LinkedList::DecreamentSize(){
    --count;
}
void LinkedList::IncreamentSize(){
    ++count;
}
Node* LinkedList::FindMidNode(){
    Node *slowPtr=head, *fastPtr = head;
    while(fastPtr!=NULL && fastPtr->next!=NULL){
      
        slowPtr= slowPtr->next;
        fastPtr= fastPtr->next->next;
    }
    return slowPtr;
}