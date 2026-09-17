// secretary.cpp
#include "secretary.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std ;
int finalects = 240 ;
int lastsemester = 8 ;
double mingrade = 5.0 ;

// Συνάρτηση constructor
Secretary::Secretary() {
    cout << "Constructed Secretary " << endl;
}

// Συνάρτηση destructor
Secretary::~Secretary() {
    for (int i = 0; i < catalogofStudent.size(); i++) {                                                
        delete catalogofStudent[i];                                     
    }
    for (int i = 0; i < catalogofProfessor.size(); i++) {                                                
        delete catalogofProfessor[i];                                     
    }
    for (int i = 0; i < catalogofCourses.size(); i++) {                                                
        delete catalogofCourses[i];                                     
    }
    cout << "Deconstructed Secretary" << endl;
}

// Συνάρτηση copy - constructor
Secretary::Secretary(const Secretary &s) {
    for (int i = 0; i < s.catalogofStudent.size(); i++ ){                                                           
        catalogofStudent.push_back( new Student(*(s.catalogofStudent[i])) );                                                  
    }
    for (int i = 0; i < s.catalogofProfessor.size(); i++ ){                                                                                   
        catalogofProfessor.push_back( new Professor(*(s.catalogofProfessor[i])) );                                                          
    }
    for (int i = 0; i < s.catalogofCourses.size(); i++ ){                                                                               
        catalogofCourses.push_back( new Course(*(s.catalogofCourses[i])) );                                                          
    }
}

// Συνάρτηση operator =
Secretary Secretary::operator=(const Secretary *s){
    for (int i = 0; i < catalogofStudent.size(); i++) {                                                
        delete catalogofStudent[i];                                     
    }
        for (int i = 0; i < catalogofProfessor.size(); i++) {                                                
        delete catalogofProfessor[i];                                     
    }
    for (int i = 0; i < catalogofCourses.size(); i++) {                                               
        delete catalogofCourses[i];                                     
    }
    Secretary temp(*s);                                                                          
    return temp;                                                                                 
}

// Συνάρτησεις GET για κάθε vector
vector<Student *> Secretary::getcatalogofStudents() const {  return catalogofStudent;  }
vector<Course *> Secretary::getcatalogofCourses() const {   return catalogofCourses;  }
vector<Professor *> Secretary::getcatalogofProfessor() const {   return catalogofProfessor;  }


//                                                                      FIND ΣΥΝΑΡΤΗΣΕΙΣ


// Συνάρτηση που βρισκει αν υπάρχει ο STUDENT με AM = c
Student* Secretary::FindStudent(const string c){
    for (int i = 0; i < catalogofStudent.size(); i++){             
        if (catalogofStudent[i]->getAM() == c) {                                                    
            return catalogofStudent[i];
        }
    }
    return NULL;
}

// Συνάρτηση που βρισκει αν υπάρχει το COURSE με title = c
Course* Secretary::FindCourse(const string c){
    for (int i = 0; i < catalogofCourses.size(); i++){                                                 
        if (catalogofCourses[i]->gettitle() == c) {                                                    
            return catalogofCourses[i];
        }
    }
    return NULL;
}  

// Συνάρτηση που βρισκει αν υπάρχει o PROFESSOR με employeeID = c
Professor* Secretary::FindProfessor(const string c){
    for (int i = 0; i < catalogofProfessor.size(); i++){
        if (catalogofProfessor[i]->getemployeeID() == c){
            return catalogofProfessor[i];
        }
    }
    return NULL;
}

//                                                                      ADD ΣΥΝΑΡΤΗΣΕΙΣ

// Συνάρτηση για προσθήκη καθηγητή στο Secretary
void Secretary::AddProfessorInSecretary(void) {
    Professor *p = new Professor;
    cin >> *p;
    if (FindProfessor(p->getemployeeID()) != NULL ) {
        cout << "The professor already exist" << endl;
        delete p;
        return ;
    }
    catalogofProfessor.push_back(p);
}

// Συνάρτηση για προσθήκη φοιτητή στο Secretary
void Secretary::AddStudentInSecretary(void) {
    Student *s = new Student;
    cin >> *s;
    if (FindStudent(s->getAM()) != NULL ) {
        cout << "The Student already exist"<<endl;
        delete s;
        return ;
    }
    catalogofStudent.push_back(s);
}

// Συνάρτηση για προσθήκη μαθήματος στο Secretary
void Secretary::AddCourseInSecretary(void) {
    Course *c = new Course;
    cin >> *c;
    if (FindCourse(c->gettitle())!=NULL ) {
        cout << "The lesson already exist" << endl;
        delete c;
        return ;
    }
    catalogofCourses.push_back(c); 
    cout << "Do you want to enroll teachers in the course? Write 1 for YES or 0 for NO "<< endl ;
    bool a;
    cin >> a;
    if (a) { 
        enrollAllProfessorsinCourse(c->gettitle()); 
    }
    cout << "Do you want to enroll students in the course? Write 1 for YES or 0 for NO " << endl;
    cin >> a;
    if (a) { 
        enrollAllStudentsinCourse(c->gettitle());
    }
}


//                                                          ENROLL PROFESSORS IN COURSE ΣΥΝΑΡΤΗΣΕΙΣ


// Συνάρτηση για εγγραφή ενός καθηγητή με employeeid = profcode σto μάθημα με title = coursecode
void Secretary::enrollProfessorInCourse(const string&  profCode, const string& courseCode) {
    Professor* professor = FindProfessor(profCode);
    Course* course = FindCourse(courseCode);

    //Εάν υπάρχει το μάθημα και ο καθηγητής στη γραμματεία
    if (professor != NULL && course != NULL ) {
        //Αν ειναι αποθηκευμένο στο vector των καθηγητων του μαθήματος τοτε δεν πρέπει να ξανά αποθηκευτεί
        if (course->FindProfessor(professor)) {
            cout << "The professor with employee id "<< profCode << " is already enrolled in the lesson " << courseCode << endl;
            return;
        }
        // Εφόσον βρέθηκαν καθηγητής και μάθημα, προσθέστε τον καθηγητή στο μάθημα
        course->enrollProfessor(professor);
        cout << "Professor " << profCode << " enrolled in course " << courseCode << endl;
    } else if (professor == NULL) {
        //Aν δεν βρέθηκε ο καθηγητής
        cout << "Professor not found" << endl;
    }else if (course == NULL) {
        //Aν δεν βρέθηκε το μάθημα
        cout << "Course not found" << endl;
    }
}

// Συνάρτηση για να οριστουν ολοι οι καθηγητες ενός μαθήματος σto μάθημα με title = coursecode 
void Secretary::enrollAllProfessorsinCourse(const string coursecode){
    Course* course = FindCourse(coursecode);
    // //Εάν δεν υπάρχει το μάθημα στη γραμματεία
    if (course == NULL) {
        cout << "There is NOT course with title " << coursecode <<endl;
        return;
    }
    string profcode;
    bool a;
    cout << "Give the EmployeeID of the first professor you want to enroll" << endl;
    cin >> profcode;
    while (1){
        enrollProfessorInCourse(profcode, coursecode);
        cout << "Do you want enroll more professors? Write 1 for Yes and 0 for No" << endl;
        cin >> a;
        if (!a) return;
        else{
            cout << "Give the Employee's ID of the next professor you want to enroll" << endl;
            cin >> profcode;
        }
    }
} 

// Συνάρτηση για να οριστουν ολοι οι καθηγητες ενός μαθήματος (ερωτημα 4)
void Secretary::enrollAllProfessorsinCourse(void){
    string coursecode, profcode;
    cout << "Give the title of the lesson you want to enroll teachers" << endl;
    cin >> coursecode;
    enrollAllProfessorsinCourse(coursecode);
} 


//                                                          ENROLL STUDENTS IN COURSE ΣΥΝΑΡΤΗΣΕΙΣ


bool Secretary::semesterisok(Course* c, Student* s) {
    return (c->getsemester() <= s->getsemester());
}


// Συνάρτηση για εγγραφή φοιτητή σε μάθημα
void Secretary::enrollStudentInCourse(const string& studentCode, const string& courseCode) {
    Student* student = FindStudent(studentCode);
    Course* course = FindCourse(courseCode);
    //Εάν υπάρχει το μάθημα και ο μαθητής στη γραμματεία
    if (student != NULL && course != NULL) {
        // ελεγξε οτι ο μαθητής βρίσκεται στο ίδιο ή μεγαλύτερο εξάμηνο απο το μάθημα
        if (! semesterisok (course, student)){
            cout << " The student with AM "<< student->getAM() << " can't enroll because it is in smaller semester than lesson " << course->gettitle() << endl;
            return;
        }
        // ελεγξε αν ο μαθητής έχει περάσει το μάθημα
        if (course->FindStudentgrades(student) >= mingrade) {
            cout << " The student with AM "<< student->getAM() << " has passed the lesson " << course->gettitle() << endl;
            return;
        }
        // ελεγξε αν ο μαθητής έχει ήδη δηλώσει το μάθημα
        if (course->FindStudentRegistered(student) ) {
            cout << " The student with AM "<< student->getAM() << " is already registered in the lesson" << course->gettitle() << endl;
            return;
        }
        // Εαν είχε δώσει το μάθημα και δεν το είχε περάσει διέγραψε τον απο τους βαθμούς
        if (course->FindStudentgrades(student) >= 0.0 && course->FindStudentgrades(student) < 5.0) {
            course->RemoveStudentGrades(student);
        }
        // Εφόσον βρέθηκαν φοιτητής και μάθημα, προσθέστε τον φοιτητή στο μάθημα
        course->enrollStudentRegistered(student);
        cout << "Student " << student->getAM() << " enrolled in course " << course->gettitle() << endl;
    } 
    else if (student == NULL){
        //Aν δεν βρέθηκε ο φοιτητής
        cout << "Student not found" << endl;
    }
    else if (course == NULL){
        //Aν δεν βρέθηκε το μάθημα
        cout << "Course not found" << endl;
    }
}

// Συνάρτηση για να οριστεί ένας μαθητής ενός μαθήματος 
void Secretary::enrollStudentInCourse(void){
    string studentcode, coursecode;
    cout << "Give your AM" << endl;
    cin >> studentcode;
    cout << "Give the title of the lesson you want to enroll" << endl;
    cin >> coursecode;
    enrollStudentInCourse(studentcode, coursecode);
}


// Συνάρτηση για να οριστουν ολοι οι μαθητές ενός μαθήματος 
void Secretary::enrollAllStudentsinCourse(const string coursecode){
    Course* course = FindCourse(coursecode);
    if (course == NULL) {
        cout << "There is NOT course with title " << coursecode <<endl;
        return;
    }
    string studcode;
    bool a;
    cout << "Give the AM of the first Student you want to enroll" << endl;
    cin >> studcode;
    while (1){
        enrollStudentInCourse(studcode, coursecode);
        cout << "Do you want enroll more Students? Write 1 for YES and 0 for NO" << endl;
        cin >> a;
        if (!a) return;
        else{
            cout << "Give the AM of the next student you want to enroll" << endl;
            cin >> studcode;
        }
    }
}

// Συνάρτηση για να οριστουν ολοι οι μαθητές ενός μαθήματος (ερωτημα 4)
void Secretary::enrollAllStudentsinCourse(void){
    string coursecode;
    cout << "Give the title of the lesson you want to enroll students" << endl;
    cin >> coursecode;
    enrollAllStudentsinCourse(coursecode);
} 


//                                                                          MODIFY ΣΥΝΑΡΤΗΣΕΙΣ


// Συνάρτηση για τροποποίηση καθηγητή
void Secretary::ModifyProfessorInSecretary(void) {
    cout << "Write the EMPLOYEE's ID of the Professor which you want to modify " << endl;
    string code;
    cin >> code;
    Professor* prof = FindProfessor(code);

    if (prof != NULL) {
        // Εμφανιση μενού
        cout << "Write the number of data you want to modify:  name(1), lastname(2), fathername(3), birthdate(4), email(5), telephone(6), job(7), specialty(8), department(9), employeeID(10) ";
        int i;
        cin >> i;
        // Ερωτήσεις στον χρήστη για τροποποίηση ενος δεδομένου
        cout << "Enter new details: " << endl;
        string d;
        cin >> d;
        if (i > 10 || i < 1) {
            cout << "WRONG NUMBER " << endl;
            return; 
        }
        else if (i == 1) {prof->setname(d);}
        else if (i == 2){prof->setlastname(d);}
        else if (i == 3){prof->setfathername(d);}
        else if (i == 4){prof->setbirthdate(d);}
        else if (i == 5){prof->setemail(d);}
        else if (i == 6){prof->settelephone(d);}
        else if (i == 7){prof->setjob(d);}
        else if (i == 8){prof->setspecialty(d);}
        else if (i == 9){prof->setdepartment(d);}
        else if (i == 10){prof->setemployeeID(d);}
        cout << "Professor details modified successfully" << endl;
    } else {
        cout << "Professor not found" <<  endl;
    }
}

// Συνάρτηση για τροποποίηση φοιτητή
void Secretary::ModifyStudentInSecretary(void) {
    cout << "Write the AM of the student which you want to modify" << endl;
    string code;
    cin >> code;
    Student *s= FindStudent(code);

    if (s != NULL) {
        // Εμφάνιση μενού
        cout << "Write the number of data you want to modify: name(1), lastname(2), fathername(3), birthdate(4), email(5), telephone(6), job(7), AM(8), semester(9) ";
        int i;
        cin >> i;
        // Ερωτήσεις στον χρήστη για τροποποίηση ενος δεδομένου
        cout << "Enter new details:" << endl;
        if (i > 9 || i < 1) {
            cout << "WRONG NUMBER " << endl;
            return; 
        }
        else if (i == 1) {
            string d;
            cin >> d;
            s->setname(d);
        }
        else if (i == 2){
            string d;
            cin >> d;
            s->setlastname(d);
        }
        else if (i == 3){
            string d;
            cin >> d;
            s->setfathername(d);
        } 
        else if (i == 4){
            string d;
            cin >> d;
            s->setbirthdate(d);
        }
        else if (i == 5){
            string d;
            cin >> d;
            s->setemail(d);
        }
        else if (i == 6){
            string d;
            cin >> d;
            s->settelephone(d);
        }
        else if (i == 7){
            string d;
            cin >> d;
            s->setjob(d);
        }
        else if (i == 8){
            string d;
            cin >> d;
            s->setAM(d);
        }
        else if (i == 9){
            int d;
            cin >> d;
            s->setsemester(d);
        }
        cout << "Student details modified successfully" << endl;
    } else {
        cout << "Student not found" << endl ;
    }
}

// Συνάρτηση για τροποποίηση μαθήματος
void Secretary::ModifyCourseInSecretary(void) {
    cout << "Write the title of the course which you want to modify " << endl;
    string code;
    cin >> code;
    Course* course = FindCourse(code);

    if (course != NULL) {
        // Εμφάνιση μενού
        cout << "Write the number of data you want to modify: course_code(1), title(2), semester(3), ECTS(4), faculty(5), insert teacher(6), insert student(7) ";
        int i;
        cin >> i;
        // Ερωτήσεις στον χρήστη για τροποποίηση
        cout << "Enter new details:" << endl;        
        if (i > 7 || i < 0) {
            cout << "WRONG NUMBER " << endl;
            return; 
        }
        else if ( i == 1) {
            string d;
            cin >> d;
            course->setcourse_code(d);
        }
        else if (i == 2){
            string d;
            cin >> d;
            course->settitle(d);
        }
        else if (i == 3){
            int d;
            cin >> d;
            course->Change_Semester(d);
        }
        else if (i == 4){
            int d;
            cin >> d;
            course->setECTS(d);
        }
        else if (i == 5){
            bool d;
            cin >> d;
            course->setfaculty(d);
        }
        else if (i == 6){
            //εισαγωγη teacher 
            cout << "write employee id of teacher " << endl;
            string code;
            cin >> code;
            enrollProfessorInCourse(code, course->gettitle());
        }
        else if (i == 7){
            //εισαγωγη student
            cout << "write AM of student " << endl;
            string code;
            cin >> code;
            enrollStudentInCourse(code, course->gettitle());
        }   
        cout << "Course details modified successfully." << endl;
    } else {
        cout << "Course not found" << endl ;
    }
}


//                                                                         DELETE ΣΥΝΑΡΤΗΣΕΙΣ

void Secretary::DeleteProfessorInSecretary() {
    string profCode;
    cout << "Enter Professor Code to delete: ";
    cin >> profCode;
    Professor* profToDelete = FindProfessor(profCode);
    if (profToDelete != NULL) {
       //διαγραφη του απο τα μαθηματα
        for (int i = 0 ; i < catalogofCourses.size(); i++) {
            catalogofCourses[i]->RemoveTeacher(profToDelete);
        }
        //οριστικη διαγραφη απο την γραμματεια
        catalogofProfessor.erase(remove(catalogofProfessor.begin(), catalogofProfessor.end(), profToDelete), catalogofProfessor.end());
        delete profToDelete; 
        cout << "Professor deleted successfully" << endl;
    } else {
        cout << "Professor not found" << endl;
    }
}

void Secretary::DeleteStudentInSecretary() {
    string studentCode;
    cout << "Enter Student Code to delete: ";
    cin >> studentCode;
    Student* studentToDelete = FindStudent(studentCode);
    if (studentToDelete != NULL) {
        //διαγραφη απο τα μαθηματα
        for (int i = 0 ; i < catalogofCourses.size(); i++) {
            catalogofCourses[i]->RemoveStudent(studentToDelete);
            catalogofCourses[i]->RemoveStudentGrades(studentToDelete);
        }
        //τελικη διαγραφη απο την γραμματεια
        catalogofStudent.erase(remove(catalogofStudent.begin(), catalogofStudent.end(), studentToDelete), catalogofStudent.end());
        delete studentToDelete; 
        cout << "Student deleted successfully" << endl;
    } else {
        cout << "Student not found" << endl;
    }
}

void Secretary::DeleteCourseInSecretary() {
    string courseCode;
    cout << "Enter Course Code to delete: ";
    cin >> courseCode;
    Course* courseToDelete = FindCourse(courseCode);
    if (courseToDelete != NULL) {
        //τελικη διαγραφη απο την γραμματεια
        catalogofCourses.erase(remove(catalogofCourses.begin(), catalogofCourses.end(), courseToDelete), catalogofCourses.end());
        delete courseToDelete; 
        cout << "Course deleted successfully" << endl;
    } else {
        cout << "Course not found" << endl;
    }
}


//                                                                   FRIEND OPERATOR ΣΥΝΑΡΤΗΣΕΙΣ



// Ανάγνωση δεδομένων του Secretar (καθηγητές, φοιτητές, μαθήματα)
istream &operator>>(istream &str, Secretary &obj) {
    ifstream teachersFile("../data/teachers.txt");
    ifstream studentsFile("../data/students.txt");
    ifstream coursesFile("../data/courses.txt");
    if (!teachersFile.is_open() || !studentsFile.is_open() || !coursesFile.is_open()) {
        throw 2;
    }
    int count=0;
    // Διάβασμα καθηγητών
    string name, lastname, fathername, email, birthdate, telephone, job, code, department, specialty, employeeID, line;
    while (getline(teachersFile, line)){
        count++;
        if(count <= 2){
            continue;
        }
        istringstream teachersFile(line);
        teachersFile >> name >> lastname >> fathername >> birthdate >> email >> telephone >> job >> code >> department >> specialty >> employeeID;
        Professor *p = new Professor(name, lastname, fathername, email, telephone, job, code, birthdate, specialty, department, employeeID);
        obj.catalogofProfessor.push_back(p);
    }

    // Διάβασμα φοιτητών
    int semester;
    string AM;
    count = 0;
    while(getline(studentsFile, line)){
        count++;
        if(count <= 2){
            continue;
        }
        istringstream studentsFile(line);
        studentsFile >> name >> lastname >> fathername >> birthdate >> email >> telephone >> job >> code >> AM >> semester;
        Student *p = new Student(name, lastname, fathername, email, telephone, job, code, birthdate, AM, semester);
        obj.catalogofStudent.push_back(p);
     }

    // Διάβασμα μαθημάτων
    string title;
    int  ects;
    bool faculty;
    count = 0;
    while(getline(coursesFile, line)){
        count++;
        if(count <= 2){
            continue;
        }
        istringstream coursesFile(line);
        coursesFile >> title >> code >> semester >> ects >> faculty;    
        Course *p = new Course(code, title, semester, ects, faculty);
        obj.catalogofCourses.push_back(p);
    }
    teachersFile.close();
    studentsFile.close();
    coursesFile.close();
    obj.InsertGradesFromFile();
    obj.InsertProfessorsFromFile();
    obj.InsertStudentsFromFile();
    return str;
}

ostream &operator<<(ostream &str, const Secretary &obj){
    // Εκτύπωση όλων των φοιτητών στο secretary
    if ( obj.catalogofStudent.size()==0) {
        cout << "There are NOT students in Secretary" << endl << endl;
    }
    else{
        cout << "\033[1;32mThe students are:\033[1;0m" << endl << endl ;
        cout << left << setw(15) << "Name" << left << setw(20) << "Lastname" << left << setw(15) << "Fathername" << left << setw(15) << "Birthdate" << left << setw(22) << "Email" << left << setw(14) << "Telephone" << left << setw(10) << "Job" << left << setw(10) << "Code" << left << setw(16) << "AM" << left << setw(10) << "Semester" << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------- "<< endl;
        for (int i = 0; i < obj.catalogofStudent.size(); i++) {                                                
            str <<  *obj.catalogofStudent[i]; 
            str << endl;                                    
        }
    }
    // Εκτύπωση όλων των καθηγητών στο secretary
    if ( obj.catalogofProfessor.size()==0) {
        cout << "There are NOT professors in Secretary" << endl << endl;
    }
    else{
        cout << "\033[1;32mThe professors are:\033[1;0m" << endl << endl;
        cout << left << setw(15) << "Name" << left << setw(20) << "Lastname" << left << setw(15) << "Fathername" << left << setw(15) << "Birthdate" << left << setw(22) << "Email" << left << setw(14) << "Telephone" << left << setw(10) << "Job" << left << setw(10) << "Code"<< left <<  setw(12) << "Department" <<  left << setw(12) << "Specialty" <<  left << setw(12) << "EmployeeID" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ "<< endl;
        for (int i = 0; i < obj.catalogofProfessor.size(); i++) {                                                
            str << *obj.catalogofProfessor[i];   
            str << endl;                                      
        }
    }
    // Εκτύπωση όλων των μαθηματων στο secretary
    if ( obj.catalogofCourses.size()==0) {
        cout << "There are NOT courses in Secretary" << endl << endl;
    }
    else{
        cout << "\033[1;32mThe courses are:\033[1;0m" << endl << endl;
        for (int i = 0; i < obj.catalogofCourses.size(); i++) {                                               
            str << *obj.catalogofCourses[i];  
            str << endl;                                       
        }
    }
    return str;
}


void Secretary::updateFiles(void){  

    ofstream Students("students.txt");
    if ( !Students.is_open() ) {
        throw 2;
    }
    Students << left << setw(15) << "Name" << left << setw(20) << "Lastname" << left << setw(15) << "Fathername" << left << setw(15) << "Birthdate" << left << setw(22) << "Email" << left << setw(14) << "Telephone" << left << setw(10) << "Job" << left << setw(10) << "Code" << left << setw(16) << "AM" << left << setw(10) << "Semester" << endl;
    Students << "----------------------------------------------------------------------------------------------------------------------------------------------------------- "<< endl;
    for (int i = 0 ; i < catalogofStudent.size(); i++){
       Students << *catalogofStudent[i];
    }
    Students.close();

    ofstream Teachers("teachers.txt");
    if ( !Teachers.is_open() ) {
        throw 2;
    }
    Teachers << left << setw(15) << "Name" << left << setw(20) << "Lastname" << left << setw(15) << "Fathername" << left << setw(15) << "Birthdate" << left << setw(22) << "Email" << left << setw(14) << "Telephone" << left << setw(10) << "Job" << left << setw(10) << "Code"<< left <<  setw(12) << "Department" <<  left << setw(12) << "Specialty" <<  left << setw(12) << "EmployeeID" << endl;
    Teachers << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ "<< endl;
    for (int i = 0 ; i < catalogofProfessor.size(); i++){
       Teachers << *catalogofProfessor[i];
    }
    Teachers.close();
    ofstream Course("courses.txt");
    if ( !Course.is_open() ) {
        throw 2;
    }
    Course << left << setw(40) << "Title" << left << setw(6) << "Code" << left << setw(11) << "Semester" << left << setw(7) << "Ects" << left << setw(7) << "Faculty" << endl;
    Course << "---------------------------------------------------------------------------------------------------" << endl;
    ofstream Grades("grades.txt");
      if ( !Grades.is_open() ) {
        throw 2;
    }
    Grades << left << setw(16) << "AM" << left << setw(40) << "Title" << left << setw(8) << "Grade" << endl;
    Grades << "------------------------------------------------------------------" << endl;
    ofstream registered("registeredstudents.txt");
      if ( !registered.is_open() ) {
        throw 2;
    }
    registered << left << setw(16) << "AM" << left << setw(40) << "Title" << endl;
    registered << "------------------------------------------------------------------" << endl;
    ofstream Teachercourse("registeredteacher.txt");
      if ( !Teachercourse.is_open() ) {
        throw 2;
    }
    Teachercourse << left << setw(16) << "EmployeeID" << left << setw(40) << "Title" << endl;
    Teachercourse << "------------------------------------------------------------------" << endl;
    for (int i = 0 ; i < catalogofCourses.size(); i++){
        string title = catalogofCourses[i]->gettitle() ;
        Course << left << setw(40 ) << title << left << setw(6) << catalogofCourses[i]->getcourse_code() << left << setw(11) << catalogofCourses[i]->getsemester() << left << setw(7) << catalogofCourses[i]->getECTS() << left << setw(7) << catalogofCourses[i]->getfaculty() << endl;
        for (int j = 0 ; j < catalogofCourses[i]->getteacher().size(); j++){
            Teachercourse << left << setw(16) << catalogofCourses[i]->getteacher()[j]->getemployeeID() << left << setw(40) <<  title << endl;
        }
        for (int j = 0 ; j < catalogofCourses[i]->getregistered().size(); j++){
            registered << left << setw(16) << catalogofCourses[i]->getregistered()[j]->getAM() << left << setw(40) <<  title << endl;
        }
        auto gradesMap = catalogofCourses[i]->getgrades();
        for (auto it = gradesMap.begin(); it != gradesMap.end(); ++it) {
            Grades << left << setw(16) << it->first->getAM() << left << setw(40) <<  title << left << setw(8) << it->second << endl;
        } 
    }
    Course.close();
    Grades.close();
    registered.close();
    Teachercourse.close();
}


//                                                                 DEGREE ΣΥΝΑΡΤΗΣΕΙΣ



// Συνάρτηση που ελέγχει αν ένας φοιτητής μπορει να πάρει πτυχιο. Αν μπορει το γραφει στο outfile
void Secretary::GetDegreeStudent(Student* student, ofstream& outFile) {
    double sum = 0, g;
    int ects = 0, pl = 0;
    // Ελέγχει αν είναι στο τελευταίο εξάμηνο
    if (student->getsemester() <= 7) {
        // outFile << "Has more semester to pass. So the student " << student->getname() << " " << student->getlastname() << " with AM " << student->getAM() << " can't get Degree." << endl;
        return;
    }
    // Για κάθε μάθημα
    for (int i = 0; i < catalogofCourses.size(); i++) {
        //Παίρνει τον βαθμό
        g = catalogofCourses[i]->FindStudentgrades(student);
        // Εαν το έχει περάσει τοτε προσθέτει τα ECTS 
        if (g >= mingrade) {
            sum+=g;
            pl++;
            ects += catalogofCourses[i]->getECTS();
        }
        //Αν δεν το έχει περάσει και ειναι υποχρεωτικό
         else if ((g < mingrade) && catalogofCourses[i]->IsCompulsory() == 1) {
            //outFile << "The student " << student->getname() << " " << student->getlastname() << " with AM " << student->getAM() << " can't get Degree." << endl;
            return;
        }
    }
    // Αν έχει όλους τους πόντους και εχει περασει τα υποχρεωτικα μαθηματα
    if (ects >= finalects) {
        outFile << *student;
        outFile << "can get degree with Grade = " << sum/pl << endl << endl; 
        cout << *student;
        cout << "can get degree with Grade = " << sum/pl << endl << endl;
    } 
    //else {outFile << "The student with name " << student->getname() << ", lastname " << student->getlastname() << " and AM " << student->getAM() << " can't get Degree." << endl;}
}

// Συνάρτηση που εκτυπώνει τους μαθητές που μπορούν να πάρουν πτυχίο
void Secretary::GetDegree() {
    //ανοίγει το αρχείο
    ofstream outFile("degree.txt");  
    if (outFile.is_open()) {
        //Για κάθε μαθητή
        for (int i = 0; i < catalogofStudent.size(); i++) {
            GetDegreeStudent(catalogofStudent[i], outFile);
        }
        //κλείνει αρχείο
        outFile.close();  
        cout << "Results written to 'degree.txt' successfully" << endl;
    } else {
        cout << "Error opening the file 'degree.txt' " << endl;
        throw 2;
    }
}


//                                                                   GRADES ΣΥΝΑΡΤΗΣΕΙΣ


//Συνάρτση που ο καθηγητής μπορεί να τυπώσει τα στατιστικά του εξαμήνου για όλα τα μαθήματα του
void Secretary::GetStatistic(void) {
    int sem;
    string em_id;
    cout << "Give the employee id of the professor you want to print the statistics of one semester" << endl;
    cin >> em_id;
    cout << "Give the semester you want to print its statistics" << endl;
    cin >> sem;
    Professor* prof = FindProfessor(em_id);
    if (prof == NULL) {
        cout << "Professor not found" << endl;
        return;
    }
    double sum = 0;
    bool found = 0;
    // Για κάθε μάθημα
    for (int i = 0; i < catalogofCourses.size(); i++) {
        if (catalogofCourses[i] == NULL) continue;
        // Ελέγξτε ότι το μάθημα έχει το ίδιο εξάμηνο
        if (catalogofCourses[i]->getsemester() == sem) {
            // Εάν είναι καθηγητής σε αυτό το μάθημα
            if (catalogofCourses[i]->FindProfessor(prof) == 1) {
                found = 1;
                int all = 0, passed = 0;
                // Από τον πρώτο μέχρι τον τελευταίο βαθμό που έχει αποθηκευτεί στο μάθημα της θέσης i του catalogofCourses
                auto gradesMap = catalogofCourses[i]->getgrades();
                for (auto it = gradesMap.begin(); it != gradesMap.end(); ++it) {
                    all++;
                    sum += (it ->second);
                    if ((it->second) >= mingrade) {
                        passed++;
                    }
                }
                // Υπολόγισε το ποσοστό των φοιτητών που πέρασαν το μάθημα και το μέσο ορο της βαθμολογίας στο μάθημα αυτό
                double passPercentage = (all > 0) ? ((double)passed * 100) / all : 0;
                double gradeaverage =  (all > 0) ? ((double)sum / all) : 0;
                cout << "At the lesson " << catalogofCourses[i]->gettitle() << " " << passPercentage << " % of students passed the lesson and its grade point average is "  << gradeaverage << endl;
            }
        }
    }
    if (found == 0) cout << "At the semester number " << sem << "the professor with employeeId" << em_id << " isn't a teacher at any lesson";
}


// Συνάρτηση που εισάγει τους βαθμούς στο vector grades του αντίστοιχου μαθήματος
void Secretary::InsertGrades() {
    cout << "Give a course title" << endl;
    string coursetitle;
    cin >> coursetitle;
    Course* course = FindCourse(coursetitle);
    // Εάν βρέθηκε το μάθημα
    if (course != NULL) {
        while (1) {
            cout << "Write the student ID" << endl;
            string code;
            cin >> code;
            Student* student = FindStudent(code);
            // Εάν βρέθηκε ο μαθητής
            if (student != NULL) {
                // Εάν ο φοιτητής έχει ήδη λάβει βαθμό για αυτό το μάθημα
                if (course->FindStudentgrades(student) != -1.0) {
                    cout << "The student has already a grade in this course" << endl;
                    continue;
                }
                 // Έλεγχος εάν ο φοιτητής δεν έχει εγγραφεί στο μάθημα
                else if (find(course->getregistered().begin(), course->getregistered().end(), student) == course->getregistered().end()) {
                        cout << "The student isn't registered at this lesson" << endl;
                }
                // Έλεγχος εάν ο φοιτητής έχει εγγραφεί στο μάθημα
                else  {
                    cout << "Write the student's grade for this course " << endl;
                    double grade;
                    cin >> grade;
                    
                    // Έλεγχος για έγκυρο βαθμό (0-10)
                    while (grade < 0 || grade > 10) {
                        cout << "Invalid grade. Please enter a grade between 0 and 10" << endl;
                        cin >> grade;
                    }
                    // Εισαγωγή βαθμού
                    course->enrollStudentgrades(student, grade);
                    // Διαγραφή από το registered
                    course->RemoveStudent(student);
                    cout << "Do you want to enter the grades of other students in this course? Write 1 for YES and 0 for NO" << endl;
                    int a;
                    cin >> a;
                    if (!a) return;
                }
            } else {
                cout << "Student not foud." << endl;
            }
        }
    } else {
        cout << "Course not found" << endl;
    }
}


// FILE INSERT GRADES 
void Secretary::InsertGradesFromFile() {
    ifstream gradesFile("../data/grades.txt");
    if (!gradesFile.is_open()) {
        throw 2;
    }
    int count=0;
    // Διάβασμα 
    double grade;
    string AM,title, line;
    while (getline(gradesFile, line)){
        count++;
        if(count <= 2){
            continue;
        }
        istringstream gradesFile(line);
        gradesFile >> AM >> title >> grade;
        Course* course = FindCourse(title);
        Student* student = FindStudent(AM);
        course->enrollStudentgrades(student,grade);
    }
    gradesFile.close();
}


// FILE INSERT STUDENTS 
void Secretary::InsertStudentsFromFile() {
    ifstream studentsFile("../data/registeredstudents.txt");
    if (!studentsFile.is_open()) {
        throw 2;
    }
    int count=0;
    // Διάβασμα
    string AM,title, line;
    while (getline(studentsFile, line)){
        count++;
        if(count <= 2){
            continue;
        }
        istringstream studentsFile(line);
        studentsFile >> AM >> title ;
        Course* course = FindCourse(title);
        Student* student = FindStudent(AM);
        course->enrollStudentRegistered(student);
    }
    studentsFile.close();
}


// FILE INSERT PROFESSORS 
void Secretary::InsertProfessorsFromFile() {
    ifstream teacherFile("../data/registeredteacher.txt");
    if (!teacherFile.is_open()) {
        throw 2;
    }
    int count=0;
    // Διάβασμα
    string employeeID,title, line;
    while (getline(teacherFile, line)){
        count++;
        if(count <= 2){
            continue;
        }
        istringstream teacherFile(line);
        teacherFile >> employeeID >> title ;
        Course* course = FindCourse(title);
        Professor* professor = FindProfessor(employeeID);
        course->enrollProfessor(professor);
    }
    teacherFile.close();
}



//Επιστρέφει τους φοιτητές που πέρασαν το μάθημα σε συγκεκριμένο εξάμηνο
void Secretary::passedcourse(void) {
    cout << "Write the title of the course" << endl;
    string code;
    cin >> code;
    Course* course = FindCourse(code);
    //Εάν βρέθηκε το μάθημα
    if (course != NULL) {
        bool studentsPassed = false;
        // Άνοιγμα αρχείου για εγγραφή
        ofstream outputFile("passed_students.txt");
        //map με βαθμους μαθήματος
        auto gradesMap = course->getgrades();
        //Επανάληψη με την χρήση map
        for (auto it = gradesMap.begin(); it != gradesMap.end(); ++it) {
            //Χρησιμοποιεί it->first για να πάρει το student pointer και το it->second για να παρει το βαθμο
            Student* student = it->first; 
            double grade = it->second;
            if (student != NULL) {
                // Έλεγχος αν ο φοιτητής πέρασε το μάθημα
                if (grade >= mingrade) {
                    //Γράφει στο αρχείο τα στοιχεία του φοιτητή και τον βαθμό του στην οθονη
                    cout << "Student: " << student->getname() << " " << student->getlastname() << "     Grade: " << grade << endl;
                    //Γράφει στο αρχείο τα στοιχεία του φοιτητή και τον βαθμό του στο αρχείο
                    outputFile << "Student: " << student->getname() << " " << student->getlastname() << "     Grade: " << grade << endl;
                    studentsPassed = true;
                }
            }
        }
         // Κλείσιμο του αρχείου
        outputFile.close();
        // Εάν δεν έχει περάσει κανένας φοιτητής το μάθημα
        if (!studentsPassed) {
            cout << "No students have passed the course" << endl;
        } else {
            cout << "Passed students' information saved to 'passed_students.txt' " << endl;
        }
    } else {
        cout << "Course not found" << endl;
    }
}


//Συνάρτηση που να μπορεί να τυπώσει ένας φοιτητής την αναλυτική του βαθμολογία για το τρέχων εξάμηνο αλλά και για όλα τα έτη.
void Secretary::StudentAnalyticalGrades() {
    cout << "Write the student ID" << endl;
    string code;
    cin >> code;
    Student* student = FindStudent(code);
    //Εάν βρέθηκε ο φοιτητής
    if (student != NULL) {
        //Εκτύπωση αναλυτικής του βαθμολογίας για το τρέχων εξάμηνο
        cout << "Do you want detailed scores for the current semester? Write 1 for YES and 0 for NO" << endl;
        int x;
        cin >> x;
        if (x) {
            int currentSemester = student->getsemester();
            bool semesterFound = false;
            // Αναζήτηση βαθμολογιών για το τρέχον εξάμηνο
            for (int i = 0; i < catalogofCourses.size(); i++) {
                //Αν το μαθημα στην θέση i διδάσκεται στο τρέχων εξάμηνο
                if (catalogofCourses[i]->getsemester() == currentSemester) {
                    double grade = catalogofCourses[i]->FindStudentgrades(student);
                    //Εάν δεν έχει λάβει βαθμολογία, θα ορίζει τον βαθμό σε 0
                    if (grade == -1.0) {
                        grade = 0;
                    }
                    cout << "In the course " << catalogofCourses[i]->gettitle() << " the grade is " << grade << endl;
                    semesterFound = true;
                }
            }
            //Εαν δεν είχε κανένα μάθημα σε αυτο το εξάμηνο
            if (!semesterFound) {
                cout << "No courses found for the current semester" << endl;
            }
        }
        //Εκτύπωση αναλυτικής του βαθμολογίας για όλα τα έτη
        cout << "Do you want detailed scores for all years (all semesters)? Write 1 for YES and 0 for NO" << endl;
        cin >> x;
        if (x) {
            bool anyCourseFound = false;
            int sem;
            //Εάν ο φοιτητής βρίσκεται σε εξάμηνο μεγαλύτερο του 8ου, τότε θέσε το sem=8 αλλιως =εξαμηνο του φοιτητη
            if (student->getsemester() > lastsemester ) {
                sem = lastsemester;
            }
            else {
                sem = student->getsemester();
            }
            //Επανάληψη για κάθε εξάμηνο, μέχρι αυτό που βρίσκεται ο φοιτητής ή εώς το 8ο εάν το έχει ξεπεράσει
            for (int semester = 1; semester <= sem ; semester++) {
                cout << "For Semester " << semester << ":" << endl;
                bool semesterFound = false;
                // Αναζήτηση βαθμολογιών για το τρέχον εξάμηνο (semester) κάθε φορά
                for (int i = 0; i < catalogofCourses.size(); i++) {
                    if (catalogofCourses[i]->getsemester() == semester) {
                        double grade = catalogofCourses[i]->FindStudentgrades(student);
                        //Εάν δεν έχει λάβει βαθμολογία, θα ορίζει τον βαθμό σε 0
                        if (grade == -1.0) {
                            grade = 0;
                        }
                        cout << "In the course " << catalogofCourses[i]->gettitle() << " the grade is " << grade << endl;
                        semesterFound = true;
                        anyCourseFound = true;
                    }
                }
                if (!semesterFound) {
                    cout << "No courses found for Semester " << semester << endl;
                }
            }
            if (!anyCourseFound) {
                cout << "No courses found for any semester" << endl;
            }
        }
    } else {
        cout << "Student not found" << endl;
    }
}

void Secretary::printStudents (){
    if ( catalogofStudent.size()==0) {
        cout << "There are NOT students in Secretary" << endl << endl;
    }
    else{
        cout << "\033[1;32mThe students are:\033[1;0m" << endl << endl ;
        cout << left << setw(15) << "Name" << left << setw(20) << "Lastname" << left << setw(15) << "Fathername" << left << setw(15) << "Birthdate" << left << setw(22) << "Email" << left << setw(14) << "Telephone" << left << setw(10) << "Job" << left << setw(10) << "Code" << left << setw(16) << "AM" << left << setw(10) << "Semester" << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------- "<< endl;
        for (int i = 0; i < catalogofStudent.size(); i++) {                                                
            cout <<  *catalogofStudent[i]; 
            cout << endl;                                    
        }
    }
}

void Secretary::printProfessors (){
    if (catalogofProfessor.size()==0) {
        cout << "There are NOT professors in Secretary" << endl << endl;
    }
    else{
        cout << "\033[1;32mThe professors are:\033[1;0m" << endl << endl;
        cout << left << setw(15) << "Name" << left << setw(20) << "Lastname" << left << setw(15) << "Fathername" << left << setw(15) << "Birthdate" << left << setw(22) << "Email" << left << setw(14) << "Telephone" << left << setw(10) << "Job" << left << setw(10) << "Code"<< left <<  setw(12) << "Department" <<  left << setw(12) << "Specialty" <<  left << setw(12) << "EmployeeID" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ "<< endl;
        for (int i = 0; i < catalogofProfessor.size(); i++) {                                                
            cout << *catalogofProfessor[i];   
            cout << endl;                                      
        }
    }
}
void Secretary::printCourses(){
    if (catalogofCourses.size()== 0) {
        cout << "There are NOT courses in Secretary" << endl << endl;
    }
    else{
        cout << "\033[1;32mThe courses are:\033[1;0m" << endl << endl;
        for (int i = 0; i < catalogofCourses.size(); i++) {                                               
            cout << *catalogofCourses[i];  
            cout << endl;                                       
        }
    }
}