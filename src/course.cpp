//course.cpp
using namespace std;
#include <iostream>
#include "course.h"

// Constructors
Course::Course(){
    title = "unknown";
    semester = -1;
    ECTS = -1;
    faculty = 0;
    course_code = "unknown";
    cout << "Constructed unknown course" << endl;
}

Course::Course( string icode, const string ititle, const int isemester, const int iects, const bool ifaculty){
    course_code = icode;
    title = ititle;
    semester = isemester;
    ECTS = iects;
    faculty = ifaculty;
    cout << "Constructed course with title " << title << endl;
}

// Copy - constructor του course
Course::Course(const Course &c){
    course_code = c.course_code;
    title = c.title;
    semester = c.semester;
    ECTS = c.ECTS;
    faculty = c.faculty;
    // Αντιγράφει professors
    for (int i = 0; i < c.teacher.size(); i++){
        teacher.push_back(new Professor(*c.teacher[i]));
    }
    // Αντιγραφει students
    for (int i = 0; i < c.registered.size(); i++){
        registered.push_back(new Student(*c.registered[i]));
    }
    // Αντιγραφει grades
    for (auto it = c.grades.begin(); it != c.grades.end(); ++it) {
        grades[it->first] = it->second; 
    }
}

// Destructor
Course::~Course(){
    grades.clear();
    cout << "Deconstructed course with title " << title << endl;
}

vector<Professor *> Course::getteacher() const{ return teacher;}
vector<Student *> Course::getregistered() const{ return registered;}
map <Student *, double> Course::getgrades() const {return grades; }

void Course::setcourse_code(const string i){    course_code = i;    }
string Course::getcourse_code() const{  return course_code;   }
        
void Course::settitle(const string i){    title = i;    }
string Course::gettitle() const{    return title;    }

void Course::setsemester(const int i){   semester = i;  }
int Course::getsemester() const{  return semester;   }

void Course::setECTS( const int i){   ECTS = i;   }
int Course::getECTS() const{   return ECTS;   }

void Course::setfaculty(const bool i){    faculty = i ;   }
bool Course::getfaculty() const{    return faculty;    }


//Αλλάζει το εξάμηνο
void Course::Change_Semester(const int newsem){
    cout << "Move the course with title " << title << " from semester " << semester << " to semester " << newsem << endl;
    semester = newsem;
}

// Εισάγει εναν student στο registered
void Course::enrollStudentRegistered(Student* student) {
    registered.push_back(student);
}

// Εισάγει εναν student στο grades με τον βαθμό του 
void Course::enrollStudentgrades(Student* student, double grade) {
    grades[student] = grade;
}

// Εισάγει εναν professor στο teacher
void Course::enrollProfessor(Professor* professor) {
    teacher.push_back(professor);
}

//Επιστρέφει 1 αν ειναι υποχρεώτικο και 0 αν δεν είναι
bool Course::IsCompulsory (void){
    return faculty;
}

//Επιστρέφει 1 αν ειναι ο μαθητής ηδη δηλωμένος το μάθημα και 0 αν δεν είναι
bool Course::FindStudentRegistered(Student* student) {
    for (int i = 0; i < registered.size(); i++){                                                 
        if (registered[i]->getAM() == student->getAM()) {                                                    
            return 1;
        }
    }
    return 0;
}

//Επιστρέφει -1 αν ο μαθητής δεν έχει δωσει το μάθημα αλλιως τον βαθμο του
double Course::FindStudentgrades(Student* student) {
    auto it = grades.find(student);
    if (it != grades.end()) {
        return it->second;  // Επιστροφή του βαθμού αν υπάρχει ο φοιτητής
    } else {
        return -1.0;  // Επιστροφή -1 αν ο φοιτητής δεν βρέθηκε
    }
}
//Επιστρέφει 1 αν ειναι ο καθηγητής ηδη δηλωμένος το μάθημα και 0 αν δεν είναι
bool Course::FindProfessor(Professor* professor) {
    for (int i = 0; i < teacher.size(); i++){                                                 
        if (teacher[i]->getemployeeID() == professor->getemployeeID()) {                                                    
            return 1;
        }
    }
    return 0;
}

//Αν υπαρχει ο professor στο teacher, τον αφαιρεί
void Course::RemoveTeacher(Professor* professor) {
    teacher.erase(remove(teacher.begin(), teacher.end(), professor), teacher.end());
}

//Αν υπαρχει ο student στο registered, τον αφαιρεί
void Course::RemoveStudent(Student* student) {
    registered.erase(remove(registered.begin(), registered.end(), student), registered.end());
}

//Αν υπαρχει ο student στο grades, τον αφαιρεί
void Course::RemoveStudentGrades(Student* student) {
    grades.erase(student);
}


// Εκτύπωση δεδομένων του course
ostream &operator<<(ostream &str, const Course &obj) {                                 
    str << "\033[1;33mTitle             \033[1;0m" << obj.title<< endl;
    str << "\033[1;33mECTS:             \033[1;0m" << obj.ECTS << endl;
    str << "\033[1;33mFaculty:          \033[1;0m" << obj.faculty << endl;
    str << "\033[1;33mSemester :        \033[1;0m" << obj.semester<< endl;
    str << "\033[1;33mCourse code :     \033[1;0m" << obj.course_code<< endl << endl; 
    cout << "The teachers in this subject are:" ;
    if (obj.teacher.size() == 0) cout <<" NONE"  ;
    cout << endl ;
    for (int i = 0; i < obj.teacher.size(); i++){
        cout << *obj.teacher[i];
    }
    cout << endl << "The students which have registered in this subject are : " ;
    if (obj.registered.size() == 0) cout <<" NONE" ;
    cout << endl;
    for (int i = 0; i < obj.registered.size(); i++){
        cout << *obj.registered[i];
    }
    cout << endl << "The students which have grades this subject are: ";
    if (obj.grades.size() == 0) cout <<" NONE" ;
    cout << endl;
    int count = 1;
    for (auto it = obj.grades.begin(); it != obj.grades.end(); ++it) {
        cout << "Grade  " << it->second << endl;     // Print the grade of the student
        cout << *(it->first);                        // Print the data of the student
    }    
    return str;
}


// Ανάγνωση δεδομένων του Course
istream &operator>>(istream &str, Course &obj) {                                       
    cout << "\033[1;31mGive title:    \033[1;0m";
    str >> obj.title;
    cout << "\033[1;31mGive Ects:    \033[1;0m";
    str >> obj.ECTS;
    cout << "\033[1;31mGive faculty (1 if it is a compulsory course and 0 if it is not):    \033[1;0m";
    str >> obj.faculty;
    cout << "\033[1;31mGive semester:    \033[1;0m";
    str >> obj.semester;
    cout << "\033[1;31mGive course code:    \033[1;0m";
    str >> obj.course_code;
    cout << endl;    
    return str;
}