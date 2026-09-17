// main.cpp
#include <iostream>
#include "secretary.h"
using namespace std;

int main() {
    int selection;
	Secretary departmentSecretary;
	try{
		cin >> departmentSecretary;
		while(1){
	    	cout << "\033[1;36mMENU:\033[1;0m" << endl;
		    cout << "\033[1;36m1. Add/modify/Delete a Professor\033[1;0m" << endl;
		    cout << "\033[1;36m2. Add/Modify/Delete a Student\033[1;0m" << endl;
	    	cout << "\033[1;36m3. Add/Modify/Delete a Course\033[1;0m" << endl;
		    cout << "\033[1;36m4. Define the Professors of a Course\033[1;0m" << endl;
		    cout << "\033[1;36m5. Enroll a Student in a Course\033[1;0m" << endl;
	    	cout << "\033[1;36m6. File of Students who passed a Course\033[1;0m" << endl;
		    cout << "\033[1;36m7. Semester statistics for all Courses of a Professor\033[1;0m" << endl;
		    cout << "\033[1;36m8. Student's Courses rating\033[1;0m" << endl;
	    	cout << "\033[1;36m9. Print the students who can graduate\033[1;0m" << endl;
			cout << "\033[1;36m10. Insert Grades\033[1;0m" << endl;
			cout << "\033[1;36m11. Print all the data in Secretary\033[1;0m" << endl;
		    cout << "\033[1;36m12. EXIT\033[1;0m" << endl;
		    cout << "\033[1;31mGive a number (1-10) depending on the function you want to implement.\033[1;0m" << endl;	
	    	cin >> selection;
	    	if (selection<=0 || selection>=13){
		    	throw 1;
	    	}
	    	if (selection == 1){
			    cout << "\033[1;36mMENU:\033[1;0m" << endl;
			    cout << "\033[1;36m1. Add a Professor\033[1;0m" << endl;
		    	cout << "\033[1;36m2. Modify a Professor\033[1;0m" << endl;
			    cout << "\033[1;36m3. Delete a Professor\033[1;0m" << endl;
				cout << "\033[1;36m4. Back to the first Menu\033[1;0m" << endl;
			    cout << "\033[1;31mGive a number (1-4) depending on the function you want to implement.\033[1;0m" << endl;	
		    	cin >> selection;
			    if (selection<=0 || selection>=5){
		    	throw 1;
	    	}
			    if (selection == 1){
			    	departmentSecretary.AddProfessorInSecretary();
		    	}
		    	else if(selection == 2){
					departmentSecretary.printProfessors();
				    departmentSecretary.ModifyProfessorInSecretary();
			    }
			    else if(selection == 3){
					departmentSecretary.printProfessors();
			    	departmentSecretary.DeleteProfessorInSecretary();
		    	}
	    	}
    		else if(selection == 2){
	    		cout << "\033[1;36mMENU:\033[1;0m" << endl;
			    cout << "\033[1;36m1. Add a Student\033[1;0m" << endl;
    			cout << "\033[1;36m2. Modify a Student\033[1;0m" << endl;
		    	cout << "\033[1;36m3. Delete a Student\033[1;0m" << endl;
				cout << "\033[1;36m4. Back to the first Menu\033[1;0m" << endl;
			    cout << "\033[1;31mGive a number (1-4) depending on the function you want it to implement.\033[1;0m" << endl;
	    		cin >> selection;
		    	if (selection<=0 || selection>=5){
		    		throw 1;
	    		}
			    if (selection == 1){
			    	departmentSecretary.AddStudentInSecretary();
		    	}
    	    	else if(selection == 2){
					departmentSecretary.printStudents();
			    	departmentSecretary.ModifyStudentInSecretary();
		    	}
		    	else if(selection == 3){
					departmentSecretary.printStudents();
				    departmentSecretary.DeleteStudentInSecretary();
		    	}	
	    	}
		    else if(selection == 3){
			    cout << "\033[1;36mMENU:\033[1;0m" << endl;
		    	cout << "\033[1;36m1. Add a Course\033[1;0m" << endl;
		    	cout << "\033[1;36m2. Modify a Course\033[1;0m" << endl;
			    cout << "\033[1;36m3. Delete a Course\033[1;0m" << endl;
				cout << "\033[1;36m4. Back to the first Menu\033[1;0m" << endl;
			    cout << "\033[1;31mGive a number (1-4) depending on the function you want it to implement.\033[1;0m" << endl;
			    cin >> selection;
			    if (selection<=0 || selection>=5){
		    		throw 1;
	    		}
		    	if (selection == 1){
			    	departmentSecretary.AddCourseInSecretary();
		    	}
		    	else if(selection == 2){
					departmentSecretary.printCourses();
				    departmentSecretary.ModifyCourseInSecretary();
    			}
		    	else if(selection == 3){
					departmentSecretary.printCourses();
		    		departmentSecretary.DeleteCourseInSecretary();
		    	}
	    	}
	    	else if(selection == 4){
		    	departmentSecretary.enrollAllProfessorsinCourse();
	    	}
	    	else if(selection == 5){
		    	departmentSecretary.enrollStudentInCourse();
	    	}
    		else if(selection == 6){
				departmentSecretary.passedcourse();
	    	}
	    	else if(selection == 7){
				departmentSecretary.GetStatistic();
	    	}
    		else if(selection == 8){
				departmentSecretary.StudentAnalyticalGrades();
		    }
		    else if(selection == 9){
				departmentSecretary.GetDegree();
		    }
		    else if(selection == 10){
				departmentSecretary.InsertGrades();
	    	}
			else if(selection == 11){
				cout << departmentSecretary;
				cout << endl << endl;
	    	}
			else if(selection == 12){
				departmentSecretary.updateFiles();
		    	return 0;
	    	}
		}
	}
	catch (int n){
		if (n == 1)  cout << "Wrong Input !" << endl;
		if (n == 2)  cout << "Failed to open one or more files !" << endl;
	}
	catch (bad_alloc){
		cout << "There is no memory available !" << endl; 
	}
	catch(...){
		cout << "Unknown Exception !" << endl;
	}
}