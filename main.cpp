#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include "personType.h"
#include "studentType.h"
#include "professorType.h"
#include "courseType.h"


using namespace std;

int main() {
    vector<personType*> people;
    vector<courseType*> courses;
    int choice = 0;

    while (true) {
        cout << "Number of Courses: " << courses.size() << endl;
        cout << "Number of People: " << people.size() << endl;

        int professorCount = 0;
        int studentCount = 0;
        int personCount = 0;

        for (personType* person : people) {
            if (dynamic_cast<professorType*>(person) != nullptr) {
                professorCount++;
            } else if (dynamic_cast<studentType*>(person) != nullptr) {
                studentCount++;
            } else {
                personCount++;
            }
        }

        cout << "---personType Count: " << professorCount << endl;
        cout << "---professorType Count Count: " << studentCount << endl;
        cout << "---studentType Count: " << personCount << endl;
        cout << "<1> Create NEW course" << endl;
        cout << "<2> Create NEW person" << endl;
        cout << "<3> Enroll Student" << endl;
        cout << "<4> Assign Instructor" << endl;
        cout << "<5> Print all People" << endl;
        cout << "<6> Print all Courses" << endl;
        cout << "<7> Print Census" << endl;
        cout << "<8> Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0)
            break;
        else if (choice == 1) {
            // Menu Option #1: Create a new course
            courseType* newCourse = new courseType();

            // Print Header
            cout << "********** CREATING NEW COURSE **********" << endl;

            // Print Current Course Count
            cout << "* Current Course Count: " << courses.size() << endl;

            // Ask for Course Section ID
            cout << "Course Section ID (i.e. 14295): ";
            string sectionID;
            cin >> sectionID;
            newCourse->setSectionID(sectionID);

            // Ask for Course Name
            cout << "Course Name (i.e. CS 1B): ";
            string courseName;
            cin.ignore(); // Ignore the newline character left in the buffer
            getline(cin, courseName);
            newCourse->setCourseName(courseName);

            // Ask for Title
            cout << "Course Title (i.e. INTRO TO CS I): ";
            string title;
            getline(cin, title);
            newCourse->setTitle(title);

            // Ask for Course Days
            cout << "Course Days (i.e. MW,TTH,MWF): ";
            string days;
            cin >> days;
            newCourse->setDays(days);

            // Ask for Course Time
            cout << "Course Time (i.e. 5:50 PM - 7:45 PM): ";
            string time;
            cin.ignore(); // Clear the input buffer
            getline(cin, time);
            newCourse->setTime(time);

            // Ask for Room
            cout << "Room (i.e. SM 202): ";
            string room;
            cin >> room;
            newCourse->setRoom(room);

            // Clear the input buffer to ensure no leftover data from previous inputs
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // Ask for Student Cap
            cout << "Cap (i.e. 30): ";
            int cap;
            // It's important to ensure that 'cap' receives the correct input
            while (!(cin >> cap)) { 
                cin.clear(); // Clear the error flags
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear out the buffer
                cout << "Invalid input. Please enter a numeric value for cap: ";
            }
            newCourse->setCap(cap);

            // Set initial values
            newCourse->setStatus(true); // Assume the course is open initially
            newCourse->setEnrolled(0); // No students enrolled initially

            // Add the new course to the vector
            courses.push_back(newCourse);

            // Inform the user that the course has been added
            cout << "Course added successfully!" << endl;
            (void) system("clear"); // Clear screen
        } else if (choice == 2) {
          // Choose the type of person (student, professor, or a general person)
          cout << "Which type? 1-personType 2-studentType 3-professorType: ";
          int personTypeChoice;
          cin >> personTypeChoice;
          (void)system("clear");

          // Menu Option #2: Create a new person
          cout << "********** CREATING NEW PERSON **********" << endl;
          cout << "* Current User Count: " << people.size() << endl;
          personType* newPerson = nullptr;
          cin.ignore(); // Ignore the newline character left in the buffer after cin >>
          if (personTypeChoice == 1) {
              newPerson = new personType();
          } else if (personTypeChoice == 2) {
              newPerson = new studentType();
          } else if (personTypeChoice == 3) {
              newPerson = new professorType();
          } else {
              cout << "Invalid person type choice. Aborting person creation." << endl;
              continue; // Go to the next iteration
          }
          string fname, lname, addr, dob;
          double height;
          char gender;
          // Standard input for all person types
          cout << "First Name: ";
          getline(cin, fname);
          newPerson->setFName(fname);
          cout << "Last Name: ";
          getline(cin, lname);
          newPerson->setLName(lname);
          cout << "Address: ";
          getline(cin, addr);
          newPerson->setAddress(addr);
          cout << "DOB (YYYY-MM-DD): ";
          getline(cin, dob);
          newPerson->setDOB(dob);
          cout << "Height (in inches): ";
          cin >> height;
          cin.ignore(); // Ignore the newline character left in the buffer
          newPerson->setHeight(height);
          cout << "Gender (M or F): ";
          cin >> gender;
          cin.ignore(); // Ignore the newline character left in the buffer
          newPerson->setGender(gender);
          // Additional input for studentType or professorType if applicable
          if (studentType* s = dynamic_cast<studentType*>(newPerson)) {
              // student-specific input prompts
              cout << "Student ID: ";
              string id;
              getline(cin, id);
              s->setID(id);
              cout << "Student GPA: ";
              float gpa;
              cin >> gpa;
              cin.ignore(); // Ignore the newline after reading numerical value
              s->setGPA(gpa);
              cout << "Student Classification: ";
              string classification;
              getline(cin, classification);
              s->setClassification(classification);
          } else if (professorType* p = dynamic_cast<professorType*>(newPerson)) {
              // professor-specific input prompts
              cout << "Employee ID: ";
              string id;
              getline(cin, id);
              p->setEmployeelD(id);
              cout << "Department: ";
              string dept;
              getline(cin, dept);
              p->setDept(dept);
              cout << "Degree: ";
              string degree;
              getline(cin, degree);
              p->setDegree(degree);
          }
          // Add the new person to the vector
          people.push_back(newPerson);
          // Inform the user that the person has been added
          cout << "Person added successfully!" << endl;
          (void)system("clear"); // Clear screen
        } else if (choice == 3) {
          // Menu Option #3: Enroll a student in a course
          int studentIndex;
          int courseIndex;
          cout << "********** ENROLLMENT SCREEN **********" << endl;
          // List all students
          cout << left << setw(10) << "Index" << setw(20) << "First Name" << setw(20) << "Last Name" << endl;
          for(size_t i = 0; i < people.size(); i++) {
              studentType* studentPtr = dynamic_cast<studentType*>(people[i]);
              if(studentPtr) {
                  cout << left << setw(10)  << i << setw(20) << studentPtr->getFname() << setw(20) << studentPtr->getLname() << endl;
              }
          }
          // User selects a student
          cout << "Enter the number corresponding to the student: ";
          cin >> studentIndex;
          // Guard against invalid input and index
          if(cin.fail() || studentIndex < 0 || studentIndex >= people.size() ||
             dynamic_cast<studentType*>(people[studentIndex]) == nullptr) {
              cout << "Invalid selection. Returning to main menu." << endl;
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              continue;
          }
          // List all courses
          cout << "Select a course for enrollment:" << endl;
          cout << left << setw(10) << "Index" << setw(30) << "Course Name" << setw(30) << "Title" << endl;
          for(size_t i = 0; i < courses.size(); ++i) {
              cout << left << setw(10) << i << setw(30) << courses[i]->getCourseName() << setw(30) << courses[i]->getTitle() << endl;
          }
          // User selects a course
          cout << "Enter the number corresponding to the course: ";
          cin >> courseIndex;
          // Guard against invalid input and index
          if(cin.fail() || courseIndex < 0 || courseIndex >= courses.size()) {
              cout << "Invalid selection. Returning to main menu." << endl;
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              continue;
          }
          // Enroll the student in the course using addCourse
          studentType* studentPtr = dynamic_cast<studentType*>(people[studentIndex]);
          if (studentPtr->addCourse(courses[courseIndex])) {
              courses[courseIndex]->enrollStudent();
              cout << "Student enrolled successfully!" << endl;
          } else {
              cout << "Failed to enroll student. The student might already be enrolled in the maximum number of courses." << endl;
          }
          (void)system("clear"); // Clear screen
          
        } else if (choice == 4) {
            // Menu Option #4: Assign a professor to a course
            // Implement code to assign a professor to a course here

          int professorIndex;
          int courseIndex;
          cout << "Select a professor to assign:" << endl;
          for(size_t i = 0; i < people.size(); ++i) {
              professorType* professorPtr = dynamic_cast<professorType*>(people[i]);
              if(professorPtr) {
                  cout << std::left << i << ": " << setw(5) << professorPtr->getFname() << " " << setw(20) << professorPtr->getLname() << endl;
              }
          }
          // User selects a professor
          cout << "Enter the number corresponding to the professor: ";
          cin >> professorIndex;
          // Guard against invalid input and index
          if(cin.fail() || professorIndex < 0 || professorIndex >= people.size() || dynamic_cast<professorType*>(people[professorIndex]) == nullptr) {
              cout << "Invalid selection. Returning to main menu." << endl;
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              continue;
          }
          cout << "Select a course for the professor to teach:" << endl;
          for(size_t i = 0; i < courses.size(); ++i) {
              cout << std::left << i << ": " << setw(15) << courses[i]->getCourseName() << " - "  << courses[i]->getTitle() << endl;
          }
          // User selects a course
          cout << "Enter the number corresponding to the course: ";
          cin >> courseIndex;
          // Guard against invalid input and index
          if(cin.fail() || courseIndex < 0 || courseIndex >= courses.size()) {
              cout << "Invalid selection. Returning to main menu." << endl;
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              continue;
          }
          // Assign the professor to the course
          dynamic_cast<professorType*>(people[professorIndex])->assignCourse(courses[courseIndex]);
          cout << "Course assigned to professor successfully!" << endl;
          (void)system("clear"); // Clear screen
            } else if (choice == 5) {
              // Print headings for person information  
              cout << left << setw(20) << "Name" 
                   << left << setw(40) << "Address" 
                   << left << setw(15) << "DOB"
                   << left << setw(15) << "Height" 
                   << left << setw(8) << "Gender" 
                   << endl;
              cout << left << setw(20) << "----" 
                 << left << setw(40) << "-------" 
                 << left << setw(15) << "---"
                 << left << setw(15) << "------" 
                 << left << setw(8) << "------" 
                 << endl;
              for (personType* person : people) {
                  // Print common information on one line
                std::ostringstream heightStream; // create an output string stream
                heightStream << person->getHeight() << " inches"; // append the numeric height and the string " inches"
                std::cout << std::setw(20) << (person->getFname() + " " + person->getLname())
                          << std::setw(40) << person->getAddress()
                          << std::setw(15) << person->getDOB()
                          << std::setw(15) << heightStream.str()
                          << std::setw(8) << person->getGender();
                  // Attempt to cast the Person pointer to a Student pointer and check if successful
                  studentType* studentPtr = dynamic_cast<studentType*>(person);
                  if (studentPtr != nullptr) {
                      // The person is a student; print courses they are taking
                      int numCourses = studentPtr->getNumCourses();
                      courseType** enrolledCourses = studentPtr->getCourses();
                      // Print headings for course information only if there are courses to be printed
                      if (numCourses > 0) {
                          cout << endl;
                          cout << endl
                          << left << setw(100) << ""  // Offset for personal data
                          << left << setw(20) << "Section ID"
                          << left << setw(20) << "Course Name"
                          << left << setw(25) << "Title"
                          << left << setw(10) << "Days"
                          << left << setw(20) << "Time"
                          << left << setw(15) << "Room"
                          << left << setw(10) << "Cap";
                          cout << endl
                            << left << setw(100) << ""  // Offset for personal data
                            << left << setw(20) << "----------"
                            << left << setw(20) << "-----------"
                            << left << setw(25) << "-----"
                            << left << setw(10) << "----"
                            << left << setw(20) << "----"
                            << left << setw(15) << "----"
                            << left << setw(10) << "---";
                      }

                      for (int i = 0; i < numCourses; i++) {
                          courseType* course = enrolledCourses[i];
                          if (course) { // Make sure the course pointer is not null
                              cout << endl
                                << left << setw(100) << ""  // Offset for personal data
                                << left << setw(20) << course->getSectionID()
                                << left << setw(20) << course->getCourseName()
                                << left << setw(25) << course->getTitle()
                                << left << setw(10) << course->getDays()
                                << left << setw(20) << course->getTime()
                                << left << setw(15) << course->getRoom()
                                << left << setw(10) << course->getCap();
                          }
                      }
                  }
                  cout << endl;
              }
              // Prompt the user to press Enter to continue
              cout << "Press Enter to continue...";
              cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
              cin.get();
              (void)system("clear"); // Clear screen
          } else if (choice == 6) {
            // Print headings for courses information
             cout << setw(20) << left << "Section ID" 
                  << setw(20) << left << "Course Name" 
                  << setw(30) << left << "Title"
                  << setw(10) << left << "Days" 
                  << setw(20) << left << "Time" 
                  << setw(12) << left << "Room"
                  << setw(10) << left << "Capacity" 
                  << setw(10) << left  << "Enrolled" 
                  << setw(8) << left << "Status"
                  << endl;
              cout << setw(20) << left << "----------" 
                << setw(20) << left << "-----------" 
                << setw(30) << left << "-----"
                << setw(10) << left << "----" 
                << setw(20) << left << "----" 
                << setw(12) << left << "----"
                << setw(10) << left << "--------" 
                << setw(10) << left  << "-------" 
                << setw(8) << left << "------"
                << endl;
            for (courseType* course : courses) {
                // Print course information on one line
                cout << setw(20) << left << course->getSectionID()
                     << setw(20) << left << course->getCourseName()
                     << setw(30) << left << course->getTitle()
                     << setw(10) << left << course->getDays()
                     << setw(20) << left << course->getTime()
                     << setw(12) << left << course->getRoom()
                     << setw(10) << left << course->getCap()
                     << setw(10) << left << course->getEnrolled()
                     << setw(8) << left << (course->getStatus() ? "Open" : "Closed") << endl;
            }
            // Prompt the user to press Enter to continue
            cout << "Press Enter to continue...";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            (void)system("clear"); // Clear screen
        } else if (choice == 7) {
            // Menu Option #7: Print the course census
            cout << "Course Census: " << courseType::getCensus() << endl;
        } else if (choice == 8) {
          break;
        } else {
            cout << "Invalid choice. Try again." << endl;
        }
        cin.clear();
    }


    return 0;
}
