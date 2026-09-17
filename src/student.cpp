// Student.cpp
#include <iostream>
#include "student.h"
using namespace std;
#include <iomanip>

// Constructors
Student::Student():person(){
    AM = "unknown";
    cout << "Constructed the unknown Student" << endl;
}

Student::Student(const string n,const string ln,const string fn, const string em, const string telep, const string j, const string c, const string bd,const string am, const int sem) :person(n, ln, fn, em, telep, j, c, bd) {
    AM = am;
    semester = sem;
    cout << "Constructed student " << name << " " << lastname << endl;
}

// Copy - Constructor του Student
Student::Student(const Student &s) {                                                    
    name = s.name;
    lastname = s.lastname; 
    fathername = s.fathername;
    birthdate = s.birthdate;
    email = s.email;
    telephone = s.telephone;
    job = s.job;
    code = s.code;
    AM = s.AM; 
    semester = s.semester;
    cout << "Copy - constructed professor " << name << " " << lastname << endl;
}

void Student:: setAM( const string n){   AM = n;   }
string Student::getAM() const {   return AM;   }
void  Student::setsemester( const int n){ semester = n;}
int Student::getsemester() const {return semester;} 

// Εκτύπωση δεδομένων του person
ostream &operator<<(ostream &str, const Student &obj) {                                 
    str << left << setw(15) << obj.name ;
    str << left << setw(20) << obj.lastname; 
    str << left << setw(15) << obj.fathername; 
    str << left << setw(15) << obj.birthdate ;
    str << left << setw(22) << obj.email ;
    str << left << setw(14) << obj.telephone ;
    str << left << setw(10) << obj.job ;
    str << left << setw(10) << obj.code ;
    str << left << setw(16) << obj.AM ;
    str << left << setw(10) << obj.semester << endl;
    return str;
}

// Ανάγνωση δεδομένων του person
istream &operator>>(istream &str, Student &obj) {                                       
    cout << "\033[1;31mGive Name:    \033[1;0m";
    str >> obj.name;
    cout << "\033[1;31mGive Lastname:    \033[1;0m";
    str >> obj.lastname;
    cout << "\033[1;31mGive Fathername:    \033[1;0m";
    str >> obj.fathername;
    cout << "\033[1;31mGive Birthdate like this -> date(_ _)/month(_ _)/year(_ _ _ _):    \033[1;0m";
    str >> obj.birthdate;
    cout << "\033[1;31mGive Email:    \033[1;0m";
    str >> obj.email;
    cout << "\033[1;31mGive Telephone number:    \033[1;0m";
    str >> obj.telephone;
    cout << "\033[1;31mGive Code of ID:    \033[1;0m";
    str >> obj.code;
    cout << "\033[1;31mGive job:    \033[1;0m";
    str >> obj.job;
    cout << "\033[1;31mGive AM in university:    \033[1;0m";
    str >> obj.AM; 
    cout << "\033[1;31mGive semester:    \033[1;0m";
    str >> obj.semester;    
    cout << endl;
    return str;
}