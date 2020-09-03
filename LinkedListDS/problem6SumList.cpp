// You have two numbers represented by a linked list, where each node contains a single digit. The digits
// are stored in reverse order such that the 1's digit is at the headd of the list. Write a function that 
// adds the two numbers and return the sum as a linked list
// e.g. Input: (7->1->6)+ (5->9->2). That is 617+295 
// Output : (2->1->9). That is 912
// Note that the two input lists can be of different lengths

#include<iostream>
#include "LinkedList.hpp"

//Do it recursively. Time Complexity O(n), space complexity- O(n)
//Can do it iteratively but the code gets larger and complex Time- O(n), Space - O(1) for iterative
Node* SumList(Node *head1, Node *head2,int carry){
    
    if(head1==NULL && head2 ==NULL && carry==0){
        return 0;
    }
    int value = carry;
    
    if(head1!=NULL){
        value +=head1->data;
    }
    if(head2!=NULL){
        value +=head2->data;
    }

    if(value>=10){
        value-=10;
        carry=1;
    }else{
        carry=0;
    }
    //Recursive Case
    Node *result = new Node(value);
    if(head1!=NULL || head2 !=NULL){
        result->next = SumList(head1==NULL?NULL:head1->next,head2==NULL?NULL:head2->next,carry);
    }
    return result;
}

//Auxiliary Print Function
void Print(Node *head){
    Node *current =head;
    while(current!=NULL){
        std::cout<<current->data<<"-->";
        current=current->next;
    }
    std::cout<<"\n";
}

int main(){
    LinkedList *list1 = new LinkedList();
    list1->PushBack(7);
    list1->PushBack(1);
    list1->PushBack(6);
    list1->PushBack(2);
    list1->PushBack(5);
    list1->Print();
    LinkedList *list2 = new LinkedList();
    list2->PushBack(5);
    list2->PushBack(9);
    list2->PushBack(3);
    list2->Print();
    Node* result = SumList(list1->Head(),list2->Head(),0);
    
    Print(result);
    return 0;
}
