using namespace std;
#include "courseType.h"


class studentType: public personType {
private:
    string id;            // student ID
    float gpa;            // GPA
    string classification; // classification
    int numCourses;       // number of courses taken
    courseType* courses[5]; // pointer array of courseType, assuming max load of 5 classes

public:
    // Constructor
    studentType() {
        id = "";
        gpa = 0.0;
        classification = "";
        numCourses = 0;
        for (int i = 0; i < 5; i++) {
            courses[i] = nullptr;
        }
    }

    // Member functions to set values
    void setGPA(float studentGPA) {
        gpa = studentGPA;
    }

    void setID(string studentID) {
        id = studentID;
    }

    void setClassification(string studentClassification) {
        classification = studentClassification;
    }

    // Member functions to add a course
    bool addCourse(courseType* course) {
        if (numCourses < 5) {
            courses[numCourses++] = course;
            return true;
        }
        return false;
    }

    // Member functions to get values
    float getGPA() const {
        return gpa;
    }

    string getID() const {
        return id;
    }

    string getClassification() const {
        return classification;
    }

    int getNumCourses() const {
        return numCourses;
    }

    courseType** getCourses() const {
        return const_cast<courseType**>(courses); // remove const-ness for returning a non-const pointer
    }


    // Member function to print student information
    void print() {
        cout << "ID: " << id << endl;
        cout << "GPA: " << gpa << endl;
        cout << "Classification: " << classification << endl;
        cout << "Number of Courses: " << numCourses << endl;
        cout << "Courses: " << endl;
        for (int i = 0; i < numCourses; i++) {
            if (courses[i] != nullptr) {
                courses[i]->print();
            }
        }
    }
    virtual void print() const override {
        // Implementation specific to studentType
        // You can call the base class print function if needed
        personType::print();
    }
};