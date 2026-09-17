// student.h
#ifndef STUDENT_H
#define STUDENT_H
using namespace std;
#include <iostream>
#include <vector>  
#include "person.h"

class Student: public person {
    protected:
        string AM;
        int semester;

    public:
        // Constructors
        Student();
        Student(const string n,const string ln,const string fn, const string em, const string telep, const string j, const string c, const string bd, const string am, const int sem);
        
        // Copy-constructor
        Student(const Student &s);

        // Destructors
        virtual ~Student( ){
            cout << "Constructed student " << name << " " << lastname << endl;
        };
        
        void setAM( const string n);
        string getAM() const; 
        void setsemester( const int n);
        int getsemester() const;   

    friend ostream &operator<<(ostream &str, const Student &obj);
    friend istream &operator>>(istream &str, Student &obj);  
};
#endif