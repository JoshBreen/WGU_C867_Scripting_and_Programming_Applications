/*
File: main.cpp
Student: Josh Breen
*/

#include "roster.h"
#include "student.h"
#include "degree.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;

int main() //MAIN
{
	//Course title, language, StudentID, name
	cout << "C867 - Scripting and Programming - Applications " << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID# 001175784" << endl;
	cout << "Josh Breen" << endl;
	cout << endl;

	const string studentData[5] = {                                //the data we are working with to be put into the class roster array
"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Josh,Breen,jbreen9@wgu.edu,36,90,54,28,SOFTWARE" };  

	Roster* classRoster = new Roster[5];  //creating our Roster

	for (int i = 0; i < 5; i++) {
		classRoster->parse(studentData[i]);  //cycles through the data and sends the strings to be parsed
	}

	classRoster->printAll();  //prints the full roster
	
	classRoster->printInvalidEmails();  //prints any invalid email addresses

	for (int i = 0; i < 5; i++) {
		string c = classRoster->classRosterArray[i]->getID(); //sets string c to the class ID
		classRoster->printAverageDaysInCourse(c);			  //sends c to print the average days for each student
	}
	classRoster->printByDegreeProgram(SOFTWARE);              //prints the students in a specific degree program, in this case Software
	
	classRoster->remove("A3");			//removes student A3 
	classRoster->printAll();			//prints all
	classRoster->remove("A3");			//checks if student was removed
	classRoster->~Roster();				//runs destructor

	system("pause");
	return 0;
}

