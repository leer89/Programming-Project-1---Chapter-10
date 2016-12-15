/*
Project		: Chapter 10, Programming Project 1
Author		: Randy Lee
Date		: 2016-12-15
Abstract	: Create student objects that that take user input for 2 test grades
with a max score of 10 points, a midterm with a max score of 100 points,
a final score of 100 points, an average of all scored points, and a
final char type grade based on all double types passed to the student object
Course:		: CPSC230 - Algorithms and Computing with C++
Instructor:	: Professor Dada
*/

/*
include stdafx.h if using visual studio 2015+
*/
#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
// student struct
struct Student {
	double quiz1;
	double quiz2;
	double midterm;
	double final;
	double average;
	char grade;
};

double getGrade(string, int);
char getLetter(double);

int main()
{	
	// set mode to test/live for debugging/testing
	// mode = test 
	
	Student student; // instantiate Student object "student"
	cout << "Randy Lee ///\nEnter the grades for Quiz 1 & 2 (0-10)\n";

	// methods take string as assignment and a max value
	student.quiz1 = getGrade("Quiz 1", 10); // assignment "Quiz 1", with a max value 10
	student.quiz2 = getGrade("Quiz 2", 10); // assignment "Quiz 2", with a max value 10
	student.midterm = getGrade("MidTerm: ", 100); // assignment "Mid term", with a max value 100
	student.final = getGrade("Final: ", 100);

	cout << "\nRandy Lee ///\nStudent Summary\n";
	cout << "Quiz 1: " << student.quiz1 << endl;
	cout << "Quiz 2: " << student.quiz2 << endl;
	cout << "Mid term: " << student.midterm << endl;
	cout << "Final exam: " << student.final << endl;
	
	// calculate average
	student.average = (student.quiz1 + student.quiz2) / 20 * 100 * 0.25 + student.midterm * 0.25 + student.final * 0.5;
	student.grade = getLetter(student.average);
	
	cout << "Semester average: " << student.average << endl;
	cout << "Final Grade: " << student.grade << endl;
	cout << "Randy Lee /// Programming Project 1 - Chapter 10" << endl;
	system("pause"); // debugging mode if you want to set debug mode = 1 for testing/debugging

	return 0;
}

char getLetter(double sum)
{
	char letter;
	if (sum >= 90)
		letter = 'A';
	else
		if (sum >= 80)
			letter = 'B';
		else
			if (sum >= 70)
				letter = 'C';
			else
				if (sum >= 60)
					letter = 'D';
				else
					letter = 'F';
	return letter;
}

double getGrade(string assignment, int max)
{
	int score;
	cout << "Enter grade for " << assignment << ": ";
	cin >> score;

	while (score < 0 || score > max)
	{
		cout << "Must be between 0 and " << max << "\n";
		cout << "Enter grade for " << assignment << ": ";
		cin >> score;
	}
	return score;
}
