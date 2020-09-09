#include<iostream>

class Person{
    int id;
    std::string name;
    public:
        void AboutMe(){
            std::cout<<"I am a person\n";
        }
};

class Student: public Person{
    public:
        void AboutMe(){
            std::cout<<"I am a student\n";
        }

};
int main(){
    Student *s = new Student();
    Person *p = new Student();

    s->AboutMe();
    p->AboutMe();

    delete s;
    delete p;
    return 0;
}