// professor.cpp
using namespace std;
#include <iostream>
#include <iomanip>
#include "professor.h"

// Constructors
Professor::Professor(): person(){
    employeeID = "unknown";
    department = "unknown";
    employeeID = "unknown";
    cout << "Constructed  unknown Professor" << endl;
}

Professor::Professor(const string n,const string ln,const string fn, const string em, const string telep, const string j, const string c, const string bd, string sp, string dep, string em_id):person(n, ln, fn, em, telep, j, c, bd) { 
    specialty = sp;
    department = dep;
    employeeID = em_id;
    cout << "Constructed professor " << name << " " << lastname << endl;
} 

//  Copy - Constructor του Professor 
Professor::Professor(const Professor &pr) {                                                    // arxikopoihsh dedomenwn trexontos person me ta antistoixa dedomena tou p 
    name = pr.name;
    lastname = pr.lastname; 
    fathername = pr.fathername;
    birthdate = pr.birthdate;
    email = pr.email;
    telephone = pr.telephone;
    job = pr.job;
    code = pr.code;
    department = pr.department;
    specialty = pr.specialty;
    employeeID = pr.employeeID;
    cout << "Copy constructed Professor " << name << " " << lastname << endl;
}

void Professor::setspecialty( const string i){   specialty = i;   }
string Professor::getspecialty() const{   return specialty;   }

void Professor::setdepartment( const string i){   department = i;   }
string Professor::getdepartment() const{   return department;   }

void Professor::setemployeeID( const string i){   employeeID = i;   }
string Professor::getemployeeID() const{   return employeeID;   }
   
// Εκτύπωση των δεδομένων του Professor
ostream &operator<<(ostream &str, const Professor &obj) {                               
    str << left << setw(15) << obj.name ;
    str << left << setw(20) << obj.lastname; 
    str << left << setw(15) << obj.fathername; 
    str << left << setw(15) << obj.birthdate ;
    str << left << setw(22) << obj.email ;
    str << left << setw(14) << obj.telephone ;
    str << left << setw(10) << obj.job ;
    str << left << setw(10) << obj.code ;
    str << left << setw(12) << obj.department;
    str << left << setw(12) << obj.specialty;
    str << left << setw(12) << obj.employeeID << endl;
    return str;
}

// Ανάγνωση των δεδομένων του Professor
istream &operator>>(istream &str, Professor &obj) {                                       //diabasma dedomenvn person (obj)
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
    cout << "\033[1;31mGive the department in university:    \033[1;0m";
    str >> obj.department;
    cout << "\033[1;31mGive the specialty:    \033[1;0m";
    str >> obj.specialty;
    cout << "\033[1;31mGive the employee's ID:    \033[1;0m";
    str >> obj.employeeID;
    cout << endl;
    return str;
}