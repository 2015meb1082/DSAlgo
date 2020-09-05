// Implement a function to check if a linked list is a palindrome

#include<iostream>
#include "LinkedList.hpp"

//Using two pointers approach, finding the mid node
Node* MiddleNode(Node *head){
    Node *slowPtr = head,*fastPtr = head;
    while(fastPtr!=NULL &&fastPtr->next!=NULL ){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    return slowPtr;
}
//Auxiliary Print function if the head is given
void Print(Node *head){
    Node* current = head;
    while(current!=NULL){
        std::cout<<current->data<<"--->";
        current=current->next;
    }
    std::cout<<"\n";
}
//Reverse a linked List. This function changes the intial linked list. So we can't compare it with reverse one.
Node* ReverseList(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node *prev =NULL, *nextNode=NULL;
    while(head->next!=NULL){
        nextNode= head->next;
        head->next = prev;
        prev =head;
        head=nextNode;
    }
    head->next =prev;
    return head;
}
//Reverse and clone it. It preserve the initial linked list
Node *ReverseAndClone(Node *head){
    LinkedList *reversedList = new LinkedList();
    Node* current = head;
    while(current!=NULL){
        reversedList->PushFront(current->data);
        current=current->next;
    }

    return reversedList->Head();
}
// Time O(n) , space - O(n)
bool CheckPalindrome(Node *head){
    Node *reverseListHead =  ReverseAndClone(head);
    Node *current1 =head,*current2 = reverseListHead;
    while(current1!=NULL && current2!=NULL){
        if(current1->data!=current2->data){
            return false;
        }
        current1 = current1->next;
        current2= current2->next;
    }
    return true;
}
int main(){
    LinkedList *list  = new LinkedList();
    list->PushBack(1);
    list->PushBack(2);
    list->PushBack(3);
    list->PushBack(5);
    list->PushBack(2);
    list->PushBack(2);
    list->PushBack(1);
    std::cout<<CheckPalindrome(list->Head())<<"\n";
    return 0;
}