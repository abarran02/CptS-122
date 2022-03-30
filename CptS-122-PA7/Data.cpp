#include "Data.h"

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