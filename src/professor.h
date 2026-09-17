// professor.h
#ifndef PROFESSOR_H
#define PROFESSOR_H
using namespace std;
#include <iostream>
#include "person.h"

class Professor: public person {
    protected: 
        string specialty;  
        string department;     
        string employeeID;  

    public:
        // Constructors
        Professor();
        Professor(const string n,const string ln,const string fn, const string em, const string telep, const string j, const string c, const string bd,string sp, string dep, string em_id);
        
        // Copy-constructor
        Professor(const Professor &pr);

        // Destructor
        virtual ~Professor(){ 
           cout << "Deconstructed professor " << name << " " << lastname << endl;
        }
        
        void setspecialty( const string i);
        string getspecialty() const;

        void setdepartment( const string i);
        string getdepartment() const;
        
        void setemployeeID( const string i);
        string getemployeeID() const;
        
        friend ostream &operator<<(ostream &str, const Professor &obj);
        friend istream &operator>>(istream &str, Professor &obj);  
};
#endif