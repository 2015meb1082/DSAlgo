#ifndef _CORRUPTLINKEDLIST
#define _CORRUPTLINKEDLIST

#include "Node.hpp"


class CorruptLinkedList{
    public:
        Node *head,*tail; int count;
        CorruptLinkedList();
        void PushBack(int data);
        void Print();
        Node* CorruptList();

};

#endif