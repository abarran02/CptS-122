/*******************************************************************************
 * Programmer: Alec Barran                                                     *
 * Class: CptS 122; Lab Section 06                                             *
 * Programming Assignment: PA7                                                 *
 * Date: 04/06/2022                                                            *
 *                                                                             *
 * Description: Read class list from .csv and modify absences for each student *
 *		and re-store the data in a relevent .txt format. Used data structures  *
 *		include stacks and linked lists.                                       *
 *                                                                             *
 * Relevant Formulas: Refer to each function definition.                       *
 *                                                                             *
 * Format of record in input file (classList.csv): see csv header              *
 ******************************************************************************/

#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Stack.h"

using std::string;
using std::ostream;
using std::endl;

class Data {
public:
	Data();
	Data(int record, int id, string name, string email, int units, string program, string level);

	void setRecord(int record);
	int getRecord() const;

	void setID(int id);
	int getID() const;

	void setName(string name);
	string getName() const;

	void setEmail(string email);
	string getEmail() const;

	void setUnits(int units);
	int getUnits() const;

	void setProgram(string program);
	string getProgram() const;

	void setLevel(string level);
	string getLevel() const;

	void addAbsence();
	void addAbsence(string date);
	void setAbsences(int absences);
	int getAbsenceCount() const;
	void clearAbsences();

	string getRecentAbsence() const;
	Stack<string> getAbsenceStack() const;

private:
	int mRecord;
	int mID;
	string mName;
	string mEmail;
	int mUnits;
	string mProgram;
	string mLevel;

	int mAbsences;
	Stack<string> mAbsentDates;
};

string getDate();
ostream& operator<<(ostream& lhs, const Data rhs);