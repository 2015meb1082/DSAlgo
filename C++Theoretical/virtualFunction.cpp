#include<iostream>

class Person{
    int id;
    std::string name;
    public:
        virtual void AboutMe(){
            std::cout<<"I am a person\n";
        }
        virtual void Course()=0;
};

class Student: public Person{
    public:
        void AboutMe(){
            std::cout<<"I am a student\n";
        }
        void Course(){
            std::cout<<"This is a student's course\n";
        }

};

class Teacher: public Person{
    public:
        void AboutMe(){
            std::cout<<"I am a teacher\n";
        }
        void Course(){
            std::cout<<"This is a teacher's course\n";
        }
};
int main(){
    
    //Person *p = new Person(); --- not possible because of virtual function and it cannot be instantiated
    Student *s = new Student();
    Teacher *t = new Teacher();
    s->AboutMe();
    s->Course();

    t->AboutMe();
    t->Course();
    delete s;
    delete t;
    return 0;
}