// You have two numbers represented by a linked list, where each node contains a single digit. The digits
// are stored in same order such that the 1's digit is in the end of the list. Write a function that 
// adds the two numbers and return the sum as a linked list
// e.g. Input: (7->1->6->2->5)+ (5->9->3). That is 71625 +593 
// Output : (7->2->2->1->8). That is 72218
// Note that the two input lists can be of different lengths

#include<iostream>
#include "LinkedList.hpp"

//Data structure for storing the result from recursive call
class ReturnedData{
    public:
        Node* returnedNode;
        int carry;
        ReturnedData(){
            returnedNode=NULL;
            carry =0;
        }
};
int Length(Node *head){
    Node *current =head;
    int count=0;
    while(current!=NULL){
        count++;
        current=current->next;
    }
    return count;
}

Node* PadList(Node* head, int lenDifference){
    while(lenDifference>0){
        Node* newNode = new Node(0);
        newNode->next= head;
        head = newNode;
        lenDifference--;
    }
    
    return head;
}

ReturnedData* AddListHelper(Node* head1, Node* head2){  
    if(head1==NULL && head2==NULL){  
        ReturnedData  *returnedData = new ReturnedData();  
        return returnedData;
    }
    ReturnedData  *returnedData = new ReturnedData();
    returnedData= AddListHelper(head1->next,head2->next);
    int value = head1->data + head2->data + returnedData->carry;
    
    if(value>=10){  
        value = value%10;
        returnedData->carry = 1;
    }else{    
        returnedData->carry =0;
    }
    
    Node *returnedNode = new Node(value);
    returnedNode->next = returnedData->returnedNode;
    returnedData->returnedNode = returnedNode;
    
    return returnedData;
}
Node* SumList(Node* head1, Node *head2){
    
    int n1 = Length(head1);
    int n2 =Length(head2);
    if(n1<n2){
        
        head1 = PadList(head1,n2-n1);
    }else{
        
        head2 = PadList(head2,n1-n2);
    }
    
    ReturnedData *returnedData = AddListHelper(head1,head2);
    
    if(returnedData->carry==0){
       
        return returnedData->returnedNode;
    }else{
      
        Node *newNode  = new Node(returnedData->carry);
        newNode->next = returnedData->returnedNode;
        return newNode;
    }


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
    std::cout<<"Input: \n";
    list1->Print();
    LinkedList *list2 = new LinkedList();
    list2->PushBack(5);
    list2->PushBack(9);
    list2->PushBack(3);
    list2->Print();
    Node* result = SumList(list1->Head(),list2->Head());
    std::cout<<"Output: \n";
    Print(result);
    return 0;
}