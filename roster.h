/*
File: roster.h
Student: Josh Breen
*/
#pragma once
#include <string>
#include <iostream>
#include "student.h"

class Roster {
public:
	int lastIndex;


	Roster(); //Empty constructor creates roster
	Roster(int capacity); //Empty constructor creates roster
	Student* classRosterArray[5];
	void parse(string datarow); //called at the end of the....
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void printAll();
	void remove(string studentID); //removes a student based on its ID
	void printAverageDaysInCourse(string studentID); //Prints average days
	void printInvalidEmails(); //Locates and prints invalid emails
	void printByDegreeProgram(DegreeProgram degreeProgram); //Prints all degrees of the specified type
	~Roster();
	

//private:
//	Student* classRosterArray[5];
};