/*
File: roster.cpp
Student: Josh Breen
*/

#include "roster.h"
#include <iostream>
#include <sstream>
using namespace std;
using std::cout;
using std::cerr;
using std::stoi;

Roster::Roster()
{
	this->lastIndex = -1;

}

void Roster::parse(string row)
{
	if (lastIndex < 5) {
		

		//read Student ID
		int rhs = row.find(",");          //establishes rhs for parsing
		string s1 = row.substr(0, rhs);  //stores Student ID taken from the substring and stores it in s1

		//read First Name
		int lhs = rhs + 1;				 //establishes lhs for parsing
		rhs = row.find(",", lhs);
		string s2 = row.substr(lhs, rhs - lhs);   //takes First Name from the substring and stores it into S2

		//read Last Name
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string s3 = row.substr(lhs, rhs - lhs); //takes last name and stores it into s3

		//read Email Address
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string s4 = row.substr(lhs, rhs - lhs); //takes email address and stores it into s4

		//read Age
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int sCon = stoi(row.substr(lhs, rhs - lhs));  //converts age from string to integer and stores it into sCon

		//read each day
		//each day needs to be converted from string
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int dcon1 = stoi(row.substr(lhs, rhs - lhs));  //converts day1 from string into integer and stores in dcon1

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int dcon2 = stoi(row.substr(lhs, rhs - lhs));  //converts day2 from string into integer and stores in dcon2

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int dcon3 = stoi(row.substr(lhs, rhs - lhs));   //converts day3 from string into integer and stores into dcon3

		lhs = rhs + 1;
		string dstring = row.substr(lhs, row.length() - lhs);  //stores degree from the string into dstring
		DegreeProgram degreeProgram = SOFTWARE;					//sets default degreeProgram variable to Software
		if (dstring == "SECURITY") {							//compares dstring to Security
			degreeProgram = SECURITY;							//if match degreeProgram is set to Security
		}
		if (dstring == "NETWORK") {								//compares dstring to Network
			degreeProgram = NETWORK;							//if match degreeProgram is set to Network, if it doesn't match Security or Network it is Software and doesn't change
		}
		add(s1, s2, s3, s4, sCon, dcon1, dcon2, dcon3, degreeProgram);  //sends the parsed string data into add
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
		lastIndex++;									//sets starting position in array
		int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };		//creates days in course array
		Student *student = new Student(studentID,firstName, lastName, emailAddress, age, daysInCourse, degreeprogram); //creates our student object
		student->setID(studentID);						//sets ID
		student->setFirstName(firstName);				//sets first name
		student->setLastName(lastName);					//sets last name
		student->setEmailAddress(emailAddress);			//sets email address
		student->setStudentAge(age);					//sets age
		student->setDaysInCourse(daysInCourse);			//sets days in course
		student->setDegreeProgram(degreeprogram);		//sets degree program

		classRosterArray[lastIndex] = student;			//sets array position as student object
	
}

void Roster::printAll() {
	for (int i = 0; i <= lastIndex; i++) {		//cycles through to print all students
		classRosterArray[i]->print();
	}
	cout << endl;
}


void Roster::remove(string studentID) {
	for (int i = 0; i < lastIndex; i++)
	{
		string d = classRosterArray[i]->getID(); //set variable to student ID

		if (d == studentID) {
			classRosterArray[i] = nullptr;
			cout << "Student " << studentID << " removed." << endl;
			classRosterArray[i] = classRosterArray[i + 1];				//I was told to not make the array dynamic so this was my solution to meet the requriements
			classRosterArray[i + 1] = classRosterArray[lastIndex];		//I shifted the two array positions up and lowered
			lastIndex--;												//the lastIndex so the 5th position would now be removed because you can't remove
			return;														//something from an array if it isn't dynamic
		}
	}
	cout << "Student " << studentID <<" not found!" << endl;
}


void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < lastIndex; i++)		//loop to go through the array
	{
		if (classRosterArray[i]->getID() == studentID) {  //check the student id
			int* days = classRosterArray[i]->getDaysInCourse();  //transfer the array over here
			int d1 = days[0];		//break the array into 3 parts
			int d2 = days[1];
			int d3 = days[2];
			cout << "Student ID: " << studentID << "\t" << "Average days courses: " << ((d1 + d2 + d3) / 3) << endl;  //perform the math to find the average and print out the message

		}
	}
	cout << endl;
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i <= lastIndex; ++i) {
		string e = classRosterArray[i]->getEmailAddress();             //set variable to email address
		if ((e.find("@") == string::npos) || (e.find(" ") != string::npos) || (e.find(".") == string::npos)) {  //check email address string @ and period, if those are missing it fails, checking for whitespace if present, it fails
			cout << "Student: " << classRosterArray[i]->getID() << " " << " has an invalid email: " << e << endl; //prints message
			cout << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	cout << "Students in the " << degreeProgramString[degreeProgram] << " Degree Program: " << endl;  //degree printing message
	for (int i = 0; i <= lastIndex; i++) {
		DegreeProgram d = classRosterArray[i]->getDegreeProgram(); //set variable to DegreeProgram for comparison
		if (d == degreeProgram) {                                       //if proper DegreeProgram
			classRosterArray[i]->print();						   //Print
		}


	}
	cout << endl;                                                 //I format documents for a living spacing issues bug me
}



Roster::~Roster() { //destructor
	for (int i = 0; i > 5; i++)
	{
		classRosterArray[i]->~Student(); //cycles through and destructs all the student objects in the array
	}
	
}