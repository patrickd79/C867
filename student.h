//
//  student.hpp
//  C867: Class Roster
//
//  Created by PATRICK DENNEY on 9/1/20.
//  Copyright © 2020 PATRICK DENNEY. All rights reserved.
//

#ifndef STUDENT_H
#define STUDENT_H
#include <stdio.h>
#include <vector>
#include "degree.h"
using namespace std;

    class Student{
        public:
            const static int numDaysSize = 3;
        private:
            string studentID;
            string firstName;
            string lastName;
            string emailAddress;
            int age;
            int numberOfDaysToComplete[numDaysSize];
            DegreeProgram degreeProgram;
        public:
        //default constructor
        Student();
        //full  constructor
        Student(string studentID, string firstName, string lastName, string emailAddress, int age, double numberOfDaysToComplete[], DegreeProgram degreeProgram);
        
        
        //prints student info
        void print();
            
          //Setter
       void setStudentID(string studentID);//{studentID = id;}
            //Getter
        string getStudentID();
            //Setter
        void setFirstName(string firstName);
            //Getter
        string getFirstName();
            //Setter
        void setLastName(string lastName);
            //Getter
        string getLastName();
            //Setter
        void setEmail(string emailAddress);
            //Getter
        string getEmail() ;
            //Setter
        void setAge(int age);
            //Getter
        int getAge() ;
            //Setter
        void setNumOfDays(int numberOfDaysToComplete[]);
            //Getter
            
       int* getNumOfDays();
            
            //Setter
        void setDegree(DegreeProgram degree);
        DegreeProgram getDegree();
        
            
            
};


#endif /* STUDENT */
