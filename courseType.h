#ifndef COURSETYPE_H
#define COURSETYPE_H

#include <iostream>
#include <string>
using namespace std;

class courseType {
private:
    string sectionID;
    string courseName;
    string title;
    string days;
    string time;
    string room;
    bool status; // true if open, false if closed
    int cap;
    int enrolled;
    static int census;

public:
    void setSectionID(string secID) { sectionID = secID; }
    void setCourseName(string name) { courseName = name; }
    void setTitle(string ttl) { title = ttl; }
    void setDays(string d) { days = d; }
    void setTime(string t) { time = t; }
    void setRoom(string r) { room = r; }
    void setStatus(bool s) { status = s; }
    void setCap(int c) { cap = c; }
    void setEnrolled(int e) { enrolled = e; }

    string getSectionID() { return sectionID; }
    string getCourseName() { return courseName; }
    string getTitle() { return title; }
    string getDays() { return days; }
    string getTime() { return time; }
    string getRoom() { return room; }
    bool getStatus() { return status; }
    int getCap() { return cap; }
    int getEnrolled() { return enrolled; }

    bool enrollStudent() {
        if (enrolled < cap && status) {
            enrolled++;
            census++;
            return true;
        }
        return false;
    }

    void print() {
        cout << "Section ID: " << sectionID << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Title: " << title << endl;
        cout << "Days: " << days << endl;
        cout << "Time: " << time << endl;
        cout << "Room: " << room << endl;
        cout << "Status: " << (status ? "Open" : "Closed") << endl;
        cout << "Capacity: " << cap << endl;
        cout << "Enrolled: " << enrolled << endl;
    }

    static int getCensus() { return census; }
};

int courseType::census = 0; // Initialize static member census to 0

#endif // COURSETYPE_H
