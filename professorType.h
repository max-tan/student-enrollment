#include "courseType.h"

class professorType: public personType {
private:
    string employeelD;     // employee ID
    string dept;           // department
    string degree;         // degree
    int numCrsTaught;      // number of courses taught
    courseType* courses[3]; // pointer array of courseType, assuming max load of 3 classes

public:
    // Constructor
    professorType() {
        employeelD = "";
        dept = "";
        degree = "";
        numCrsTaught = 0;
        for (int i = 0; i < 3; i++) {
            courses[i] = nullptr;
        }
    }

    // Member functions to set values
    void setEmployeelD(string professorID) {
        employeelD = professorID;
    }

    void setDept(string professorDept) {
        dept = professorDept;
    }

    void setDegree(string professorDegree) {
        degree = professorDegree;
    }

    // Member functions to assign a course
    void assignCourse(courseType* course) {
        if (numCrsTaught < 3) {
            courses[numCrsTaught++] = course;
        }
    }

    // Member functions to get values
    string getEmployeelD() {
        return employeelD;
    }

    string getDept() {
        return dept;
    }

    string getDegree() {
        return degree;
    }

    // Member function to print professor information
    void print() {
        cout << "Employee ID: " << employeelD << endl;
        cout << "Department: " << dept << endl;
        cout << "Degree: " << degree << endl;
        cout << "Number of Courses Taught: " << numCrsTaught << endl;
        cout << "Courses Taught: " << endl;
        for (int i = 0; i < numCrsTaught; i++) {
            if (courses[i] != nullptr) {
                courses[i]->print();
            }
        }
    }
    // Make print function virtual
    virtual void print() const {
    }
};