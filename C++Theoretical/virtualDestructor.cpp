#include<iostream>

class Person{
    public:
        virtual ~Person(){
            std::cout<<"Person Deleted\n";
        }
};
class Student:public Person{
    public:
        ~Student(){
            std::cout<<"Student Deleted\n";
        }
};

int main(){
    Person *p =new Student();
    delete p;
    return 0;
}