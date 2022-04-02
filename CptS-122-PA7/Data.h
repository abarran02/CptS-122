#pragma once

#include <iostream>
#include "Stack.h"

using std::string;

class Data {
public:
	Data();
	Data(int record, int id, string name, string email, int units, string program, string level);

	void setRecord(int record);
	int getRecord();

	void setID(int id);
	int getID();

	void setName(string name);
	string getName();

	void setEmail(string email);
	string getEmail();

	void setUnits(int units);
	int getUnits();

	void setProgram(string program);
	string getProgram();

	void setLevel(string level);
	string getLevel();

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