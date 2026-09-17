// person.cpp
#include <iostream>
#include "person.h"
using namespace std;


// Constructors
person::person() {
    name = "unknown"; 
    lastname = "unknown";
    fathername = "unknown";  
    email = "unknown";
    telephone = "unknown";
    job = "unknown";
    code = "unknown";
    birthdate = "unknown";
    cout << "Constructed unknown person " << endl;
}

person::person(const string n, const string ln, const string fn, const string em, const string telep, const string j, const string c, const string bd) { 
    name = n;
    lastname = ln;
    email = em;
    fathername = fn;
    telephone = telep;
    job = j;
    code = c;
    birthdate = bd;
    cout << "Constructed person "<< name << " " << lastname <<endl;
}

// Copy - Constructor του Person
person::person(const person &p) {                                                    
    name = p.name;
    lastname = p.lastname; 
    fathername = p.fathername;
    email = p.email;
    telephone = p.telephone;
    job = p.job;
    code = p.code;
    birthdate = p.birthdate;
    cout << "Copy-constructed person " << name << " " << lastname << endl;
}

void person::setname(const string n) {   name = n;   }
string person::getname() const {   return name;   }

void person::setlastname(const string ln) {   lastname = ln;   }
string person::getlastname() const {   return lastname;   }

void person::setfathername(const string fn) {   fathername = fn;   }
string person::getfathername() const {   return fathername;   }

void person::setemail(const string em) {   email = em;   }
string person::getemail() const {   return email;   }

void person::settelephone(const string telep) {   telephone = telep;   }
string person::gettelephone() const {   return telephone;   }

void person::setjob(const string j) {   job = j;   }
string person::getjob() const {   return job;   }

void person::setcode(const string c) {   code = c;   }
string person::getcode() const {   return code;   }

void person::setbirthdate(const string bd) {   birthdate = bd;   }
string person::getbirthdate() const {   return birthdate;   }
