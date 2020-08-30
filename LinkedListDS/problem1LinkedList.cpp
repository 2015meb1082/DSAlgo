// Problem:- Write code to remove duplicates from an unsorted linked list.
//Follow up- What if temporary buffer is not allowed? How would you solve it. 
//State the time and space complexity of both

#include<iostream>
#include "LinkedList.hpp"
#include<unordered_set>


//With unordered_set - Time Complexity O(n), Space Complexity- O(n)
void RemoveDups(LinkedList* list){
    std::unordered_set<int> numberSet;
    Node *head = list->Head();
    Node *current = head,*prev,*temp;
    while(current!=NULL){
        
        if(numberSet.find(current->data)==numberSet.end()){
            //It means not found
            numberSet.insert(current->data);
            prev= current;
            current=current->next;
        }else{
            //number already found
            temp = current;
            current=current->next;
            prev->next = current;
            delete temp;
            list->DecreamentSize();
        }
    }
   
}

/*
//Follow up - No extra space- Time Complexity O(n^2) and Space Complexity O(1)

void RemoveDups(LinkedList* list){
    Node *head = list->Head();
    Node *current = head,*runner,*temp;
    while(current!=NULL){
        runner=current;
        while(runner->next!=NULL){
            if(current->data ==runner->next->data){
                temp =runner->next;
                runner->next = runner->next->next;
                delete temp;
                list->DecreamentSize();
            }else{
                runner =runner->next;
            }
        }
        current=current->next;
    }
   
}
*/
int main(){
    LinkedList *list = new LinkedList();
    for(int i=0;i<10;i++){
        list->PushBack(i+1);
    }
    for(int i=4;i<8;i++){
        list->PushFront(i+1);
    }
    std::cout<<"Linked List Initially\n";
    list->Print();
    std::cout<<"Linked List Finally\n";
    RemoveDups(list);
    list->Print();
    std::cout<<list->Size()<<"\n";
    return 0;
}
