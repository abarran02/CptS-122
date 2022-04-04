#include "Data.h"

Data::Data() {
	mRecord = -1;
	mID = -1;
	mName = "";
	mEmail = "";
	mUnits = -1;
	mProgram = "";
	mLevel = "";

	mAbsences = 0;
}

Data::Data(int record, int id, string name, string email, int units, string program, string level) {
	mRecord = record;
	mID = id;
	mName = name;
	mEmail = email;
	mUnits = units;
	mProgram = program;
	mLevel = level;

	mAbsences = 0;
}

void Data::setRecord(int record) {
	mRecord = record;
}

int Data::getRecord() const {
	return mRecord;
}

void Data::setID(int id) {
	mID = id;
}

int Data::getID() const {
	return mID;
}

void Data::setName(string name) {
	mName = name;
}

string Data::getName() const {
	return mName;
}

void Data::setEmail(string email) {
	mEmail = email;
}

string Data::getEmail() const {
	return mEmail;
}

void Data::setUnits(int units) {
	mUnits = units;
}

int Data::getUnits() const {
	return mUnits;
}

void Data::setProgram(string program) {
	mProgram = program;
}

string Data::getProgram() const {
	return mProgram;
}

void Data::setLevel(string level) {
	mLevel = level;
}

string Data::getLevel() const {
	return mLevel;
}

void Data::addAbsence() {
	mAbsences++;
	mAbsentDates.push(getDate());
}

void Data::addAbsence(string date) {
	mAbsences++;
	mAbsentDates.push(date);
}

void Data::setAbsences(int absences) {
	mAbsences = absences;
}

int Data::getAbsenceCount() const {
	return mAbsences;
}

void Data::clearAbsences() {
	string clear;

	while (mAbsentDates.pop(clear)) {
		mAbsences--;
	}
}

string Data::getRecentAbsence() const {
	string date;
	if (mAbsentDates.peek(date)) {
		return date;
	}
	else {
		return "";
	}
}

Stack<string> Data::getAbsenceStack() const {
	return mAbsentDates;
}

string getDate() {
	string date;
	char buffer[5];
	time_t t = time(0);   // get time now
	struct tm* now = localtime(&t);
	date.append(_itoa(now->tm_year + 1900, buffer, 10));
	date.append("-");
	date.append(_itoa(now->tm_mon + 1, buffer, 10));
	date.append("-");
	date.append(_itoa(now->tm_mday, buffer, 10));

	return date;
}

ostream& operator<<(ostream& lhs, const Data rhs) {
	lhs << "Student Record: " << rhs.getRecord() << endl;
	lhs << "ID: " << rhs.getID() << endl;
	lhs << "Name: " << rhs.getName() << endl;
	lhs << "Email: " << rhs.getEmail() << endl;

	// specify audit
	if (rhs.getUnits() == -1) {
		lhs << "Units: AU" << endl;
	}
	else {
		lhs << "Units: " << rhs.getUnits() << endl;
	}
	
	lhs << "Program: " << rhs.getProgram() << endl;
	lhs << "Level: " << rhs.getLevel() << endl;
	lhs << "Absences: " << rhs.getAbsenceCount() << endl;
	lhs << "Recent absence: " << rhs.getRecentAbsence() << endl;

	return lhs;
}