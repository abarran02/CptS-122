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

#include "Data.h"

 /*************************************************************
  * Function: Data ()                                         *
  * Description: default constructor for Data class           *
  * Input parameters:                                         *
  * Returns:                                                  *
  * Preconditions:                                            *
  * Postconditions:                                           *
  *************************************************************/
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

/*************************************************************
 * Function: Data ()                                         *
 * Description: overload constructor for Data class          *
 * Input parameters: int record, int id, string name,        *
 *		string email, int units, string program,             *
 *		string level                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
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


/*************************************************************
 * Function: get/setMember ()                                *
 * Description: getters and setters for member attributes,   *
 *		there are too many for me to write comments for each *
 * Input parameters: read each declaration                   *
 * Returns: read each declaration                            *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
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

/*************************************************************
 * Function: addAbsence ()                                   *
 * Description: add today's date to students absence Stack   *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void Data::addAbsence() {
	mAbsences++;
	mAbsentDates.push(getDate());
}

/*************************************************************
 * Function: addAbsence ()                                   *
 * Description: add given date to students absence Stack     *
 * Input parameters: string date                             *
 * Returns:                                                  *
 * Preconditions: date is in given format (yyyy-mm-dd)       *
 * Postconditions:                                           *
 *************************************************************/
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

/*************************************************************
 * Function: clearAbsences ()                                *
 * Description: delete all of a student's absence Stack      *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void Data::clearAbsences() {
	string clear;

	while (mAbsentDates.pop(clear)) {
		mAbsences--;
	}
}

/*************************************************************
 * Function: getRecentAbsence ()                             *
 * Description: get date of student's most recent absence    *
 * Input parameters:                                         *
 * Returns: string                                           *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
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

/*************************************************************
 * Function: getDate ()                                      *
 * Description: get string of today's date                   *
 * Input parameters:                                         *
 * Returns: string                                           *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
string getDate() {
	char date[12];
	time_t t = time(0);   // get time now
	struct tm* now = localtime(&t);

	// get current date
	int year = now->tm_year + 1900, 
		month = now->tm_mon + 1,
		day = now->tm_mday;

	// format string with zero padding
	sprintf(date, "%04d-%02d-%02d", year, month, day);

	return string(date);
}

/*************************************************************
 * Function: operator <<                                     *
 * Description: << overload to print Data to screen          *
 * Input parameters: ostream& lhs, const Data rhs            *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
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