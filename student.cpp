//
//  student.cpp
//  C867: Class Roster
//
//  Created by PATRICK DENNEY on 9/1/20.
//  Copyright © 2020 PATRICK DENNEY. All rights reserved.

#include <iostream>
#include "student.h"
#include "degree.h"
using namespace std;

//Setter
void Student::setStudentID(string studentID){
    this->studentID = studentID;
}
          //Getter
      string Student::getStudentID(){
          return this->studentID;
      }
          //Setter
      void Student::setFirstName(string firstName){
          this->firstName = firstName;
      }
          //Getter
      string Student::getFirstName(){
          return this->firstName;
      }
          //Setter
      void Student::setLastName(string lastName){
          this->lastName = lastName;
      }
          //Getter
      string Student::getLastName(){
          return this->lastName;
      }
          //Setter
      void Student::setEmail(string emailAddress){
          this->emailAddress = emailAddress;
      }
          //Getter
      string Student::getEmail() {
          return this->emailAddress;
      }
          //Setter
      void Student::setAge(int age){
          this->age = age;
      }
          //Getter
      int Student::getAge() {
          return this->age;
      }
          //Setter
      void Student::setNumOfDays(int numberOfDaysToComplete[]){
         for(int i = 0; i < numDaysSize; i++)
         {this->numberOfDaysToComplete[i] = numberOfDaysToComplete[i];}
      }
          //Getter
        int* Student::getNumOfDays(){
         return this->numberOfDaysToComplete;
     }
          
          //Setter
      void Student::setDegree(DegreeProgram degree){
          this->degreeProgram = degree;
      }
      DegreeProgram Student::getDegree(){
          return this->degreeProgram;
      }
         
        

//default constructor
Student::Student(){
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for(int i = 0; i < numDaysSize; i++)
        {this->numberOfDaysToComplete[i] = 0;}
    this->degreeProgram = DegreeProgram::NONE;
}
    Student::Student(string studentID, string firstName, string lastName, string emailAddress,int age, double numberOfDaysToComplete[], DegreeProgram degreeProgram){
        Student::studentID = studentID;
        this->firstName = firstName;
        this->lastName = lastName;
        this->emailAddress = emailAddress;
        this->age = age;
        for(int i = 0; i < numDaysSize; i++)
            {this->numberOfDaysToComplete[i] = numberOfDaysToComplete[i];}
        this->degreeProgram = degreeProgram;
    }
    
void Student::print(){
    cout << this->getStudentID() << endl;
    cout << this->getFirstName() << endl;
    cout << this->getLastName() << endl;
    cout << this->getEmail() << endl;
    
    for(int i = 0; i < Student::numDaysSize; i++){
        if(i < (Student::numDaysSize -1)){
    cout << this->getNumOfDays()[i] << ',';
        }else{
            cout << this->getNumOfDays()[i] << endl;
        }
    }
    cout << degreeProgFeed[this->getDegree()]<< endl;
}
