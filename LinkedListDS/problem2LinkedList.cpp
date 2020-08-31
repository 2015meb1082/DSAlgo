//Problem2 - Implement an algorithm to find the Kth to last element of a linked list

#include<iostream>
#include "LinkedList.hpp"

// Approach 1- In two passes.  Time Complexity- O(n)+O(n) = O(n), Space - O(1)
Node* FindKthToLastNode(LinkedList *list,int k){

    Node *head =list->Head(),*current;
    //Pass 1
    int n =list->Size();
    int positionFromBeginning = n-k+1,positionCounter=1;
    current =head;
    
    //Pass 2
    while(current!=NULL && positionCounter<positionFromBeginning){
        positionCounter++;
        current=current->next;
    }

    return current;
}


// Approach 2 is using Hash Tables(unordered_map) Time Complexity -O(n), Space - O(n)
// Not implementing coz it's not space efficient


//Approach 3 - Only in 1 Pass. Using two pointers approach or tortoise Hare approach or floyd cycle detection
//Time Complexity - O(n), Space - O(1)
Node* FindKthToLastNodeInOnePass(LinkedList *list,int k){

    Node *head =list->Head(),*current,*prev;
    int counter=0;current = head, prev =head;
    
    //Move the current pointer k steps forward
    while(counter<k && current!=NULL){
        counter++;
        current=current->next;
    }

    // Now move both pointers simultaneously till current reaches the end that is NULL
    while(current!=NULL){
        current=current->next;
        prev =prev->next;
    }

    if(!current){
        std::cout<<"K exceeds number of elements in the linked list. Returning head element\n";
    }
    return prev;

}



int main(){
    LinkedList *list = new LinkedList();
    std::cout<<"Enter k\n";
    int k;
    std::cin>>k;
    if(k<=0){
        std::cout<<"Enter a positive integer number only!\n";
        
    }else{
        for(int i=0;i<10;i++){
        list->PushBack((i+1)*10);
        }
        list->Print();
        Node *KthToLastNode = FindKthToLastNodeInOnePass(list,k);
        std::cout<<"Kth Node from the last is : "<<KthToLastNode->data<<"\n";
    }
    

    
    return 0;
}

