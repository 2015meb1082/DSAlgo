//Check if a linked list is a palindrome 
//using STL stack ADT
//Stack is a LIFO data structure. so we are pushing the first half elements of the list onto the stack
// Then we compare the popped elements of stack with the second half of the list to check if it is a palindrome

#include<iostream>
#include "LinkedList.hpp"
#include<stack>

bool CheckPalindrome(Node *head){
    std::stack<int> s;
    Node* slowPtr = head,*fastPtr =head;

    //Two runner pointers. One is moving twice as fast as other 
    while(fastPtr!=NULL && fastPtr->next!=NULL){
        s.push(slowPtr->data);
        slowPtr=slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    //If linked list is of odd length
    if(fastPtr!=NULL){
        slowPtr =slowPtr->next;
    }

    //Compare the second half elements of the list with the stacks popped elements
    while(slowPtr!=NULL){
        int top = s.top();
        if(top!=slowPtr->data){
            return false;
        }
        s.pop();
        slowPtr=slowPtr->next;
    }

    return true;

}
int main(){
    LinkedList *list  = new LinkedList();
    list->PushBack(1);
    list->PushBack(2);
    list->PushBack(3);
    list->PushBack(5);
    list->PushBack(3);
    list->PushBack(2);
    list->PushBack(1);
    std::cout<<CheckPalindrome(list->Head())<<"\n"; 
    return 0;
}