//
//  roster.cpp
//  C867: Class Roster
//
//  Created by PATRICK DENNEY on 9/1/20.
//  Copyright © 2020 PATRICK DENNEY. All rights reserved.
//
#include <iostream>
#include<sstream>
#include<vector>
#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;

void Roster::parseStudentData(string studentData)
{
    //go to first comma
    int goTo = studentData.find(",");
    //extract student ID, starting at index 0 and going to index just before the comma
    string studentID = studentData.substr(0, goTo);
    
    //set new starting index, at index just after the last comma used
    int comeFrom = goTo +1;
    //going to next comma, starting at new starting index
    goTo = studentData.find(",", comeFrom);
    //extract first name starting at index just after the last comma used
    string firstName = studentData.substr(comeFrom, goTo - comeFrom );
    
    //set new starting index, at index just after last used comma position
    comeFrom = goTo +1;
    //going to next comma, starting at new starting index
    goTo = studentData.find(",", comeFrom);
    //extract last name starting at index just after the last comma used
    string lastName = studentData.substr(comeFrom, goTo - comeFrom );
    
    //set new starting index, at index just after the last comma used
    comeFrom = goTo +1;
    //going to next comma, starting at new starting index
    goTo = studentData.find(",", comeFrom);
    //extract email starting at index just after the last comma used
    string email = studentData.substr(comeFrom, goTo - comeFrom );
    
    //set new starting index, at index just after the last comma used
    comeFrom = goTo +1;
    //going to next comma, starting at new starting index
    goTo = studentData.find(",", comeFrom);
    //extract age starting at index just after the last comma used
    double age = stod(studentData.substr(comeFrom, goTo - comeFrom ));
    
    //set new starting index, at index just after the last comma used
    comeFrom = goTo +1;
    //going to next comma, starting at new starting index
    goTo = studentData.find(",", comeFrom);
    //extract numDays1 starting at index just after the last comma used
    double numDays1 = stod(studentData.substr(comeFrom, goTo - comeFrom ));
    
    //set new starting index, at index just after the last comma used
    comeFrom = goTo +1;
    //going to next comma, starting at new starting index
    goTo = studentData.find(",", comeFrom);
    //extract nujDays2 starting at index just after the last comma used
    double numDays2 = stod(studentData.substr(comeFrom, goTo - comeFrom ));
    
    //set new starting index, at index just after the last comma used
    comeFrom = goTo +1;
    //going to next comma, starting at new starting index
    goTo = studentData.find(",", comeFrom);
    //extract numDays3 starting at index just after the last comma used
    double numDays3 = stod(studentData.substr(comeFrom, goTo - comeFrom ));
    
    //set new starting index, at index just after the last comma used
    comeFrom = goTo +1;
    //going to next comma, starting at new starting index
    goTo = studentData.find(",", comeFrom);
    //extract degree starting at index just after the last comma used
    string degree = studentData.substr(comeFrom, goTo - comeFrom );
    
    //use degree string to check program and assign correct program to student
    DegreeProgram degreeProg;
    if (degree.substr(0, 2) == "SE"){
        degreeProg = SECURITY;
    }else if (degree.substr(0, 2) == "NE"){
        degreeProg = NETWORK;
    }else {
        degreeProg = SOFTWARE;
    }
    //assign the variables to the add fucntion
    add(studentID, firstName, lastName, email, age, numDays1, numDays2, numDays3, degreeProg );
}
// build a student object and add to the roster array
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, double numDaysToComplete1, double numDaysToComplete2, double numDaysToComplete3, DegreeProgram degree){
    //put the num days into an array to be able to feed it into the student constructor
    double numDaysArr[3] = {static_cast<double>(numDaysToComplete1), static_cast<double>(numDaysToComplete2), static_cast<double>(numDaysToComplete3)};
    //adding new students to the roster
    classRosterArray[++endOfArray] = new Student( studentID,  firstName,  lastName,  emailAddress,  age,  numDaysArr,  degree);
};

void Roster::remove(string studentID){
    // is the student in the list?
    bool isStudentInList = false;
    //index of the student we want to remove
    int indexOfStudentToRemove = 0;
    //current student id being checked against our input
    string thisStudentID;
    //loop though array to check for the id of the student we want to remove
    for(int i = 0; i <= Roster::endOfArray; i++){
        //id of the student currently being checked against our input
        thisStudentID = classRosterArray[i]->getStudentID();
        //does the current student match our input?
        if(thisStudentID == studentID){
            //if a match then set this to true
            isStudentInList = true;
            //set this to the current index value
            indexOfStudentToRemove = i;
            if(indexOfStudentToRemove < (numOfStudents -1)){
                //place student into a placeholder
                Student* placeHolder = classRosterArray[indexOfStudentToRemove];
                //move student at the end of the array to the index of the student to be removed
                classRosterArray[indexOfStudentToRemove] = classRosterArray[numOfStudents -1];
                //move student to be removed from the placeholder to the end of the array
                classRosterArray[numOfStudents-1] = placeHolder;
            cout << "Student number " << thisStudentID << " has been removed from the roster." << endl;
            }
            // decriment the end of the array to hide the student to be removed
            Roster::endOfArray--;
            cout << endl;
            cout << endl;

        
        }else if((thisStudentID != studentID) && (isStudentInList == false)){
            isStudentInList = false;
            //checks is ID is not a match and still no match was found before
        }
        
    }
    //if no matches found, prints message
    if(isStudentInList == false){
        cout << "No student matching that ID found." << endl;
        cout << endl;
        cout << endl;

    }
    
}
       //pretty self-explanatory
void Roster::printAll(){
    for(int i = 0; i <= Roster::endOfArray; i++){
        cout << "Student ID: " << classRosterArray[i]->getStudentID() << '\t';
        cout << "First Name: " << classRosterArray[i]->getFirstName() << '\t';
        cout << " Last Name: " << classRosterArray[i]->getLastName() << '\t';
        cout << "Email Address: " << classRosterArray[i]->getEmail() << '\t';
        cout << "Age: " << classRosterArray[i]->getAge() << '\t';
        cout << "Number of days in each course: { ";
        cout << classRosterArray[i]->getNumOfDays()[0] << ", ";
        cout << classRosterArray[i]->getNumOfDays()[1]<< ", ";
        cout << classRosterArray[i]->getNumOfDays()[2];
        cout << " }" << '\t';
        cout << degreeProgFeed[classRosterArray[i]->getDegree()] << endl;
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID){
   
    for(int i = 0; i <= Roster::endOfArray; i++){
        //variable holding the calculation of the average
        double averageDays = (classRosterArray[i]->getNumOfDays()[0] + classRosterArray[i]->getNumOfDays()[1] + classRosterArray[i]->getNumOfDays()[2]) / 3.0;
        string thisStudentID = classRosterArray[i]->getStudentID();
        if(thisStudentID == studentID){
            cout << "Student number " << thisStudentID << " averages: " << averageDays << " days in each course." << endl;
            cout << endl;
        }
    }
        
    
};

void Roster::printInvalidEmails(){
    bool invalid = false;
    for(int i = 0; i <= Roster::endOfArray; i++){
        //checking if entered email contains "@", "." , or space.
        if((classRosterArray[i]->getEmail().find('@') == string::npos) || (classRosterArray[i]->getEmail().find('.') == string::npos) || (classRosterArray[i]->getEmail().find(' ') != string::npos)){
            invalid = true;
            cout << "The email address for Student: " << classRosterArray[i]->getStudentID() << " is invalid. Email address entered: " << classRosterArray[i]->getEmail() << endl;
            cout << endl;
        }
        
    }if(invalid == false){
        cout << "All student email addresses are valid." << endl;
    }
    cout << endl;
    cout << endl;
}
// also pretty self-explanatory
void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
    for(int i = 0; i <= Roster::endOfArray; i++){
        if(Roster::classRosterArray[i]-> getDegree() == degreeProgram){
            cout << "Student ID: " << classRosterArray[i]->getStudentID() << '\t';
            cout << "First Name: " << classRosterArray[i]->getFirstName() << '\t';
            cout << " Last Name: " << classRosterArray[i]->getLastName() << '\t';
            cout << "Email Address: " << classRosterArray[i]->getEmail() << '\t';
            cout << "Age: " << classRosterArray[i]->getAge() << '\t';
            cout << "Number of days in each course: { ";
            cout << classRosterArray[i]->getNumOfDays()[0] << ", ";
            cout << classRosterArray[i]->getNumOfDays()[1]<< ", ";
            cout << classRosterArray[i]->getNumOfDays()[2];
            cout << " }" << '\t';
            cout << degreeProgFeed[classRosterArray[i]->getDegree()] << endl;
            cout << endl;
        }
        cout << endl;
        
    }
}
//destructor
Roster::~Roster(){
    for(int i = 0; i < Roster::numOfStudents; i++){
        //delete each object
        delete classRosterArray[i];
        //deallocate the memory
        classRosterArray[i] = nullptr;
    }
}
