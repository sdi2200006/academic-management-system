// course.h
using namespace std;
#include <iostream>
#include "professor.h"
#include "student.h"
#include <map>
#include <vector>
#include <algorithm>

class Course{
    protected:
        string course_code;
        string title;
        int semester;
        int ECTS;
        bool faculty;
        vector<Professor *> teacher;  
        vector<Student *> registered;
        map <Student *, double> grades;
        
    public:
        // Constructor
        Course();
        Course( string icode, const string ititle, const int isemester, const int iects, const bool ifaculty);

        // Copy-Constructor
        Course(const Course &c);
        
        // Destructor
        ~Course();

        vector<Professor *> getteacher() const;
        vector<Student *> getregistered() const;
        map <Student *, double> getgrades() const ;

        void setcourse_code(const string i);
        string getcourse_code() const; 

        void settitle(const string i);
        string gettitle() const;

        void setsemester( const int i);
        int getsemester() const;

        void setECTS(const int i);
        int getECTS() const;
        
        void setfaculty(const bool i);
        bool getfaculty() const;
         
        // Βοηθητικές συναρτήσεις για την εισαγωγή στα vector και στο map  
        void enrollProfessor(Professor* professor);
        void enrollStudentRegistered(Student* student);
        void enrollStudentgrades(Student* student, double grade);

        //Αλλάζει το εξάμηνο
        void Change_Semester(const int newsem);  

        //επιστρέφει 1 αν ειναι υποχρεωτικο αλλιώς 0
        bool IsCompulsory (void);

        // FIND συναρτήσεις 
        bool FindStudentRegistered(Student* student);
        bool FindProfessor(Professor* professor) ;
        double FindStudentgrades(Student* student);

        // REMOVE item συναρτήσεις
        void RemoveTeacher(Professor* professor);
        void RemoveStudent(Student* student) ;
        void RemoveStudentGrades(Student* student) ;

    friend ostream &operator<<(ostream &str, const Course &obj);
    friend istream &operator>>(istream &str, Course &obj); 
};