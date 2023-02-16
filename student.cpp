/*
File: student.cpp
Student: Josh Breen
*/
#include <iostream>
#include <iomanip>
#include "student.h"
using std::cout;
using std::left;
using std::setw;

Student::Student(string ID, string fname, string lname, string eaddress, int age, int days[], DegreeProgram degree)  //the full constructor establishing attributes
{
	this->studentID = ID;				
	this->firstName = fname;
	this->lastName = lname;
	this->emailAddress = eaddress;
	this->age = age;
	this->daysInCourse[0] = days[0];
	this->daysInCourse[1] = days[1];
	this->daysInCourse[2]= days[2];
	this->dProgram = degree;
}

//getters
string Student::getID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

int Student::getStudentAge()
{
	return age;
}

int* Student::getDaysInCourse()
{
	return daysInCourse;
}


DegreeProgram Student::getDegreeProgram()
{
	return dProgram;
}


//setters
void Student::setID(string ID)
{
	this->studentID = ID;
}

void Student::setFirstName(string fName) 
{
	this->firstName = fName;
}

void Student::setLastName(string lName)
{
	this->lastName = lName;
}

void Student::setEmailAddress(string eAddress)
{
	this->emailAddress = eAddress;
}

void Student::setStudentAge(int sAge)
{
	this->age = sAge;
}

void Student::setDaysInCourse(int days[])
{
	this->daysInCourse[0] = days[0];
	this->daysInCourse[1] = days[1];
	this->daysInCourse[2] = days[2];
}

void Student::setDegreeProgram(DegreeProgram degree)
{
	this->dProgram = degree;
}

void Student::print() 
{
	cout << studentID << "\t";                     //display student ID
	cout << "First Name: " << firstName << "\t";   //display first name
	cout << "Last Name: " << lastName << "\t";     //display last name
	cout << "Age: " << age << "\t";                //display age
	cout << "daysInCourse: " << "{" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}\t";  //display days in course with ugly formatting and no spaces for the text per the instructions
	cout << "Degree Program: " << degreeProgramString[dProgram] << endl;  //displays degree program

}
Student::~Student() {  //destructor

}

