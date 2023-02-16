/*
File: student.h
Student: Josh Breen
*/
#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student //This class represents a student
{
private:
	string studentID;  
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	DegreeProgram dProgram; 

public: //public items are visible everywhere in the application
//	Student();
	const static int dayArraySize = 3;
	Student(string ID, string fname, string lname, string eaddress, int age, int days[], DegreeProgram degree);

	//getters for each instance field
	string getID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getStudentAge();
	int* getDaysInCourse();
	DegreeProgram getDegreeProgram();

	//the setters
	void setID(string ID);
	void setFirstName(string fname);
	void setLastName(string lname);
	void setEmailAddress(string eaddress);
	void setStudentAge(int age);
	void setDaysInCourse(int days[]);
	void setDegreeProgram(DegreeProgram degree);
	void print();

	//The destructor
	~Student();
};

