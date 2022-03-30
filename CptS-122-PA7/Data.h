#pragma once

#include <iostream>
#include "Stack.h"

using std::string;

class Data {
public:
	Data(int record, int id, string name, string email, int units, string program, string level);

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