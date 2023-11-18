#include <iostream>
#include <string>

using namespace std;

class personType {
private:
    string fName;   // first name
    string lName;   // last name
    string address; // address
    double height;  // height
    string dob;     // date of birth
    char gender;    // gender

public:
    // Constructor
    personType() {
        fName = "";
        lName = "";
        address = "";
        height = 0.0;
        dob = "";
        gender = ' ';
    }

    // Member functions to set values
    void setFName(string firstName) {
        fName = firstName;
    }

    void setLName(string lastName) {
        lName = lastName;
    }

    void setAddress(string addr) {
        address = addr;
    }

    void setHeight(double h) {
        height = h;
    }

    void setDOB(string dateOfBirth) {
        dob = dateOfBirth;
    }

    void setGender(char g) {
        gender = g;
    }

    // Member functions to get values
    string getFname() const {
        return fName;
    }

    string getLname() const {
        return lName;
    }

    string getAddress() const {
      return address;
    }

    string getDOB() const {
      return dob;
    }

    double getHeight() const {
      return height;
    }

    char getGender() const {
      return gender;
    }

    

    // Make print function virtual
    virtual void print() const {
        cout << "Name: " << fName << " " << lName << endl;
        cout << "Address: " << address << endl;
        cout << "Height: " << height << " inches" << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Gender: " << gender << endl;
    }

    // Virtual destructor (recommended when using polymorphism)
    virtual ~personType() = default;
};
