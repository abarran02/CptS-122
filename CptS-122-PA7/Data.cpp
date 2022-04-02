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

int Data::getRecord() {
	return mRecord;
}

void Data::setID(int id) {
	mID = id;
}

int Data::getID() {
	return mID;
}

void Data::setName(string name) {
	mName = name;
}

string Data::getName() {
	return mName;
}

void Data::setEmail(string email) {
	mEmail = email;
}

string Data::getEmail() {
	return mEmail;
}

void Data::setUnits(int units) {
	mUnits = units;
}

int Data::getUnits() {
	return mUnits;
}

void Data::setProgram(string program) {
	mProgram = program;
}

string Data::getProgram() {
	return mProgram;
}

void Data::setLevel(string level) {
	mLevel = level;
}

string Data::getLevel() {
	return mLevel;
}