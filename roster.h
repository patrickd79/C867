//
//  roster.hpp
//  C867: Class Roster
//
//  Created by PATRICK DENNEY on 9/1/20.
//  Copyright © 2020 PATRICK DENNEY. All rights reserved.
//

#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

class Roster
{
private:
    const static int numOfStudents = 5;
    Student* classRosterArray[numOfStudents];
    int endOfArray = -1;
    
public:
    void parseStudentData(string studentData);
    
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, double numDaysToComplete1, double numDaysToComplete2, double numDaysToComplete3, DegreeProgram degree);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);

    ~Roster();
    
    
};


