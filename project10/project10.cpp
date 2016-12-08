// project10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
struct Student {
	double q1;
	double q2;
	double mt;
	double final;
	double average;
	char grade;
};

double getGrade(string, int);
char getLetter(double);

int main()
{
	Student s;
	cout << "Enter the grades for Quiz 1 & 2 (0-10)\n";

	s.q1 = getGrade("Quiz 1", 10);
	s.q2 = getGrade("Quiz 2", 10);
	s.mt = getGrade("Mid term: ", 100);
	s.final = getGrade("Final: ", 100);

	cout << "\nStudent Summary\n";
	cout << "Quiz 1: " << s.q1 << endl;
	cout << "Quiz 2: " << s.q2 << endl;
	cout << "Mid term: " << s.mt << endl;
	cout << "Final exam: " << s.final << endl;

	s.average = (s.q1 + s.q2) / 20 * 100 * 0.25 + s.mt * 0.25 + s.final *0.5;
	s.grade = getLetter(s.average);
	cout << "Semester average: " << s.average << endl;
	cout << "Final Grade: " << s.grade << endl;
	cout << "Randy Lee /// Programming Project 10" << endl;
	system("pause");

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

double getGrade(string mess, int max)
{
	int score;
	cout << "Enter grade for " << mess << ": ";
	cin >> score;

	while (score < 0 || score > max)
	{
		cout << "Must be between 0 and " << max << "\n";
		cout << "Enter grade for " << mess << ": ";
		cin >> score;
	}
	return score;
}