//Given two singly linked list, determine if the two lists intersect. Return the intersecting node.
#include<iostream>
#include "Node.hpp"

Node* FindIntersection(Node *head1, Node *head2){
    Node* current1= head1,*tail1;
    Node* current2 =  head2,*tail2;
    int m=0;
    //Find both linked list lengths
    while(current1!=NULL){
        tail1 = current1;
        current1 = current1->next;
        m++;
    }
    int n=0;
    while(current2!=NULL){
        tail2 = current2;
        current2=current2->next;
        n++;
    }

    //If the linked lists are not intersecting
    if(tail1!=tail2){
        return NULL;
    }

    Node *larger,*smaller;
    larger = (m>n)?head1:head2;
    smaller = (m>n)?head2:head1;

    current1 = larger;
    current2 = smaller;
    int count=0;
    while(current1!=NULL && count<m-n){
        count++;
    }

    while(current1!=current2){
        return current1;
    }

    return NULL;
}

