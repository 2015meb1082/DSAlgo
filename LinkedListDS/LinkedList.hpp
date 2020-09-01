//For duplicate addition of header file. You can use "#pragma once" instead of "ifndef"
#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.hpp"

class LinkedList{
    private:
        Node *head; 
        int count;
    public:
        LinkedList();
        void PushBack(int data);
        void PushFront(int data);
        int Size();
        void Print();
        void PopBack();
        void PopFront();
        void DeleteLinkedList();
        Node* Head();
        void SetHead(Node* newHead);
        void DecreamentSize();
        void IncreamentSize();
        Node* FindMidNode();
};

#endif