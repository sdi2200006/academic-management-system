// secretary.h
using namespace std;
#include <iostream>
#include "course.h"

class Secretary {
protected:
    vector<Professor *> catalogofProfessor;
    vector<Student *> catalogofStudent;
    vector<Course *> catalogofCourses;
    
public:
    // Constructor
    Secretary();

    // Destructor
    ~Secretary();

    // Copy-constructor
    Secretary(const Secretary &s);

    // operator =
    Secretary operator=(const Secretary *s);

    vector<Student *> getcatalogofStudents() const ;
    vector<Course *> getcatalogofCourses() const ;
    vector<Professor *> getcatalogofProfessor() const ;

    // Συνάρτησεις για εύρεση αντικειμένων σε κάθε vector:
    Student* FindStudent(const string c);
    Course* FindCourse(const string c);
    Professor* FindProfessor(const string c);

    // Συναρτήσεις για προσθήκη αντικειμένων σε κάθε vector:
    void AddProfessorInSecretary(void);
    void AddStudentInSecretary(void) ;
    void AddCourseInSecretary(void) ;

    // Συναρτήσεις για επεξεργαία αντικειμένων σε κάθε vector:
    void ModifyProfessorInSecretary(void);
    void ModifyStudentInSecretary(void) ;
    void ModifyCourseInSecretary(void) ;

    // Συναρτήσεις για διαγραφή αντικειμένων σε κάθε vector:
    void DeleteProfessorInSecretary(void);
    void DeleteStudentInSecretary(void) ;
    void DeleteCourseInSecretary(void) ;

    // Συναρτήσεις για εισαγωγη μαθητών σε μαθήματα:
    void enrollStudentInCourse(void);
    void enrollStudentInCourse(const string& studentCode, const string& courseCode) ;
    void enrollAllStudentsinCourse(void);
    void enrollAllStudentsinCourse(const string coursecode);

    // Συναρτήσεις για εισαγωγη καθηγητών σε μαθήματα:
    void enrollAllProfessorsinCourse(void);
    void enrollAllProfessorsinCourse(const string coursecode);
    void enrollProfessorInCourse(const string&  profCode, const string& courseCode);

    // Συναρτήσεις για εισαγωγη βαθμών σε μαθήματα:
    void InsertGrades();

    // Βοηθητικη συναρτηση που ελέγχει αν το εξάμηνο ειναι οκ:
    bool semesterisok(Course* c, Student*s);

    //Συναρτήσεις για πτυχιο:
    void GetDegreeStudent(Student* student, ofstream& outFile);
    void GetDegree(void);

    //Συναρτήσεις για στατιστικα καθηγητή σε συγκεκριμενο εξάμηνο:
    void GetStatistic(void);

    //Συναρτήσεις για εισαγωγη μέσω αρχείων :
    void InsertGradesFromFile();
    void InsertProfessorsFromFile();
    void InsertStudentsFromFile();

    //αναλυτικη βαθμολογια: 
    void StudentAnalyticalGrades();

    //Τυπώνει τους μαθητές που πέρασαν ένα συγκεκριμένο μαθημα:
    void passedcourse(void);

    //Συναρτηση για εισαγωγη ενημέρωση αρχείων :
    void updateFiles(void);

    //Συναρτησεις print 
    void printStudents();
    void printProfessors ();
    void printCourses();

    friend istream &operator>>(istream &str, Secretary &obj);
    friend ostream &operator<<(ostream &str, const Secretary &obj);
};

