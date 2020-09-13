//
//  main.cpp
//  C867: Class Roster
//
//  Created by PATRICK DENNEY on 9/1/20.
//  Copyright © 2020 PATRICK DENNEY. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "student.h"
#include "roster.h"
using namespace std;




int main(int argc, const char * argv[]) {
    //Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
    cout << "Scripting and Programming - Applications – C867, Programming language: C++, Student ID: #000508793, Patrick Denney" << endl;
    cout << endl;
    cout << endl;
    
    //provided student data
    const string studentData[] =
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Patrick,Denney,pdenney@wgu.edu,41,25,28,30,SOFTWARE"};
    
    //number of student in the data
    const int numOfStudents = 5;
    
    //Create an instance of the Roster class called classRoster.
    Roster classRoster;
    
    //Add each student to classRoster.
    //parse the student data into a roster
    for(int i = 0; i < numOfStudents; i++){
        classRoster.parseStudentData(studentData[i]);
    }
    
    
    classRoster.printAll();
    
    
    classRoster.printInvalidEmails();
    
    //loop through classRosterArray and for each element:
    //classRoster.printAverageDaysInCourse(/*current_object's student id*/);
    for(int i = 0; i < numOfStudents; i++){
        string currentStudent = "A" + to_string(i + 1);
    classRoster.printAverageDaysInCourse(currentStudent);
    }
    
    classRoster.printByDegreeProgram(SOFTWARE);
    
    classRoster.remove("A3");
    
    
    classRoster.printAll();
    
    classRoster.remove("A3");
    //expected: the above line should print a message saying such a student with this ID was not found.
    
    //Implement the destructor to release the memory that was allocated dynamically in Roster.
    classRoster.~Roster();
    
    
    
    return 0;
}

