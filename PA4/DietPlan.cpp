/*******************************************************************************
 * Programmer: Alec Barran                                                     *
 * Class: CptS 122; Lab Section 06                                             *
 * Programming Assignment: PA4                                                 *
 * Date: 03/02/2022                                                            *
 *                                                                             *
 * Description: Read and write diet and exercise plans to text files, and edit *
 *		their and display their contents in C++ using classes                  *
 * 		and class templates.                                                   *
 *                                                                             *
 * Format of record in input file (dietPlans.txt):                             *
 *                                                Bulking      (string name)   *
 *                                                3400         (int goal)      *
 *                                                03/04/2021   (string date)   *
 *                                                                             *
 * Format of output file (dietPlans.txt): Same as input.                       *
 ******************************************************************************/

#include "DietPlan.h"

/*************************************************************
 * Function: DietPlan ()                                     *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: constructor for DietPlan class               *
 * Input parameters: int goal, string name, string date      *
 * Returns: void                                             *
 * Preconditions: int goal >= 0                              *
 * Postconditions:                                           *
 *************************************************************/
DietPlan::DietPlan(int goal, string name, string date) {
	mGoal = goal;
	mName = name;
	mDate = date;
}

/*************************************************************
 * Function: ~DietPlan ()                                    *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: destructor for DietPlan class                *
 * Input parameters: void                                    *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
DietPlan::~DietPlan() {
	//cout << "Invoking DietPlan destructor" << endl;
}

/*************************************************************
 * Function: DietPlan ()                                     *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: copy constructor for DietPlan class          *
 * Input parameters: const DietPlan& plan                    *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
DietPlan::DietPlan(const DietPlan& plan) {
	mGoal = plan.mGoal;
	mName = plan.mName;
	mDate = plan.mDate;
}

/*************************************************************
 * Function: getGoal ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: getter for mGoal                             *
 * Input parameters: void                                    *
 * Returns: int                                              *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
int DietPlan::getGoal(void) const {
	return mGoal;
}

/*************************************************************
 * Function: setGoal ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: setter for mGoal                             *
 * Input parameters: int goal                                *
 * Returns: void                                             *
 * Preconditions: goal >= 0                                  *
 * Postconditions:                                           *
 *************************************************************/
void DietPlan::setGoal(int goal) {
	mGoal = goal;
}

/*************************************************************
 * Function: getName ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: getter for mName                             *
 * Input parameters: void                                    *
 * Returns: string                                           *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
string DietPlan::getName(void) const {
	return mName;
}

/*************************************************************
 * Function: setName ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: setter for mName                             *
 * Input parameters: string name                             *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void DietPlan::setName(string name) {
	mName = name;
}

/*************************************************************
 * Function: getDate ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: getter for mDate                             *
 * Input parameters: void                                    *
 * Returns: string                                           *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
string DietPlan::getDate(void) const {
	return mDate;
}

/*************************************************************
 * Function: setDate ()                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: setter for mDate                             *
 * Input parameters: string date                             *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void DietPlan::setDate(string date) {
	mDate = date;
}

/*************************************************************
 * Function: editGoal ()                                     *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: prompts user to edit mGoal                   *
 * Input parameters: void                                    *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void DietPlan::editGoal(void) {
	int newGoal;

	// print current goal and get new goal from user
	cout << "Current goal is " << this->getGoal() << endl;
	newGoal = promptIntInRange(0, std::numeric_limits<int>::max(), "Enter new goal: ");

	this->setGoal(newGoal);
}

/*************************************************************
 * Function: operator>>                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: overload for >> operator to read from file   *
 * Input parameters: fstream& lhs, DietPlan& rhs             *
 * Returns: fstream&                                         *
 * Preconditions: fstream& lhs is an open file               *
 * Postconditions:                                           *
 *************************************************************/
fstream& operator>> (fstream& lhs, DietPlan& rhs) {
	string line, name, date;

	std::getline(lhs, name);
	std::getline(lhs, line);
	std::getline(lhs, date);
	rhs = DietPlan(std::stoi(line), name, date);

	// discard blank line
	std::getline(lhs, line);

	return lhs;
}

/*************************************************************
 * Function: operator<<                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: overload for << operator to print to screen  *
 * Input parameters: ostream& lhs, const DietPlan& rhs       *
 * Returns: ostream&                                         *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
ostream& operator<< (ostream& lhs, const DietPlan& rhs) {
	lhs << "Name: " << rhs.getName() << endl;
	lhs << "Calorie goal: " << rhs.getGoal() << endl;
	lhs << "Date: " << rhs.getDate() << endl;

	return lhs;
}

/*************************************************************
 * Function: operator>>                                      *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: overload for << operator to write to file    *
 * Input parameters: fstream& lhs, DietPlan& rhs             *
 * Returns: fstream&                                         *
 * Preconditions: fstream& lhs is an open file               *
 * Postconditions:                                           *
 *************************************************************/
fstream& operator<< (fstream& lhs, const DietPlan& rhs) {
	lhs << rhs.getName() << endl;
	lhs << std::to_string(rhs.getGoal()) << endl;
	lhs << rhs.getDate() << endl << endl;

	return lhs;
}

/*************************************************************
 * Function: promptIntInRange ()                             *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: prompts user with given message for an int   *
 *		within the range provided                            *
 * Input parameters: int min, int max, string message        *
 * Returns: int                                              *
 * Preconditions: min <= max                                 *
 * Postconditions: min <= int <= max                         *
 *************************************************************/
int DietPlan::promptIntInRange(int min, int max, string message) {
	int prompt;

	do {
		// requires cin to load an int, clears input stream if it is not
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		// print message to user and get their option input
		cout << message;
		cin >> prompt;

		// check that input is an int and is between min and max
	} while (cin.fail() || (prompt < min || prompt > max));

	return prompt;
}