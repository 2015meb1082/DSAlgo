// Given a linked list. Find if there is a cycle in it. If yes then find the starting point of the loop.

#include<iostream>
#include "CorruptLinkedList.hpp"
#include "LinkedList.hpp"
Node* CheckLoopAndFindBeginningOfLoop(Node *head){
    Node *slowPtr=head,*fastPtr=head;bool loop=false;
    while(fastPtr!=NULL && fastPtr->next!=NULL){
        slowPtr=slowPtr->next;
        fastPtr=fastPtr->next->next;
        if(slowPtr==fastPtr){
            loop=true;
            break;
        }
        
    }
    if(loop){
        fastPtr=head;
        while(slowPtr!=fastPtr){
            slowPtr=slowPtr->next;
            fastPtr=fastPtr->next;
        }
        return slowPtr;
    }

    return NULL;
}

int main(){
    CorruptLinkedList *list = new CorruptLinkedList();
    LinkedList *simpleList = new LinkedList();
    for(int i=0;i<10;i++){
        simpleList->PushBack(i+1);
        list->PushBack(i+1);
    }
    list->Print();
    //Corrupt list
    Node* corruptedNode =list->CorruptList();
    std::cout<<"Corrupted Node: "<<corruptedNode->data<<"\n";
    //Node *loopNode =CheckLoopAndFindBeginningOfLoop(simpleList->Head());
    Node *loopNode =CheckLoopAndFindBeginningOfLoop(list->head);
    if(loopNode!=NULL){  
        std::cout<<"Loop Node: "<<loopNode->data<<"\n";
    }else{    
        std::cout<<"NO LOOP\n";
    }
    return 0;
}