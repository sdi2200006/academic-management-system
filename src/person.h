//person.h
#ifndef PERSON_H
#define PERSON_H

using namespace std;
#include <iostream>
#include <string>

class person {
protected:
    string name;
    string lastname;
    string fathername;
    string birthdate;
    string email;
    string telephone;
    string job;
    string code;                   //ID

public:
    // Constructors
    person();
    person(const string n,const string ln,const string fn, const string em, const string telep, const string j, const string c, const string bd);
    
    // Copy-constructor
    person(const person &p);
    
    // Destructors
    virtual ~person() {
        cout << "Deconstructed person  " << name << " " << lastname << endl;
    }

    void setname( const string n);
    string getname() const;

    void setlastname(const string ln);
    string getlastname() const;

   void setfathername( const string n);
    string getfathername() const;

    void setemail(const string em);
    string getemail() const;

    void settelephone(const string telep);
    string gettelephone() const;

    void setjob( const string j);
    string getjob() const;

    void setcode(const string c);
    string getcode() const;

    void setbirthdate(const string bd);
    string getbirthdate() const;
};
#endif 