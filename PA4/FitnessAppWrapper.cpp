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

#include "FitnessAppWrapper.h"

/*************************************************************
 * Function: FitnessAppWrapper()                             *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: Constructor for the FitnessAppWrapper class  *
 * Input parameters: string dietFile, string exerciseFile    *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
FitnessAppWrapper::FitnessAppWrapper(string dietFile, string exerciseFile) {
	// open dietFile into dietStream
	mDietFile = dietFile;
	dietStream.open(dietFile);

	// open exerciseFile into exerciseStream
	mExerciseFile = mExerciseFile;
	exerciseStream.open(exerciseFile);
}

/*************************************************************
 * Function: ~FitnessAppWrapper()                            *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: Destructor for the FitnessAppWrapper class   *
 * Input parameters:                                         *
 * Returns: void                                            *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
FitnessAppWrapper::~FitnessAppWrapper() {
	dietStream.close();
	exerciseStream.close();
}

/*************************************************************
 * Function: FitnessAppWrapper()                             *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: Copy constructor for the                     *
 *		FitnessAppWrapper class                              *
 * Input parameters: string dietFile, string exerciseFile    *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
FitnessAppWrapper::FitnessAppWrapper(const FitnessAppWrapper& app) {
	// use stored dietFile and exerciseFile from other object
	// to open new streams
	dietStream.open(app.mDietFile);
	exerciseStream.open(app.mExerciseFile);
}

/*************************************************************
 * Function: runApp ()                                       *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: main function for FitnessAppWrapper class    *
 * Input parameters: void                                    *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void FitnessAppWrapper::runApp(void) {
	List<ExercisePlan> exerciseList;
	List<DietPlan> dietList;
	int option, exit = 0;

	while (!exit) {
		// display menu and prompt user for a menu option to execute
		displayMenu();
		option = promptIntInRange(0, 8, "Enter an option: ");
		// clear the screen
		system("CLS");

		switch (option) {
		case 0:
			// "Load weekly diet plan from file"
			loadWeeklyPlan(dietStream, &dietList);
			break;
		case 1:
			//"Load weekly exercise plan from file"
			loadWeeklyPlan(exerciseStream, &exerciseList);
			break;
		case 2:
			//"Store weekly diet plan to file"
			storeWeeklyPlan(dietStream, &dietList);
			break;
		case 3:
			//"Store weekly exercise plan to file"
			storeWeeklyPlan(exerciseStream, &exerciseList);
			break;
		case 4:
			//"Display weekly diet plan to screen"
			displayWeeklyPlan(&dietList, false);
			break;
		case 5:
			//"Display weekly exercise plan to screen"
			displayWeeklyPlan(&exerciseList, false);
			break;
		case 6:
			//"Edit daily diet plan"
			// ensure list isn't empty
			if (dietList.getHead() != NULL) {
				editDailyPlan(&dietList);
			}
			else {
				cout << "Cannot edit empty plan." << endl;
			}
			break;
		case 7:
			//"Edit daily exercise plan"
			if (exerciseList.getHead() != NULL) {
				editDailyPlan(&exerciseList);
			}
			else {
				cout << "Cannot edit empty plan." << endl;
			}
			break;
		case 8:
			//"Exit"
			exit = 1;

			// store diet plan
			// check not empty, will overwrite file otherwise
			if (dietList.getHead() != NULL) {
				storeWeeklyPlan(dietStream, &dietList);
			}

			// store exercise plan
			// check not empty, will overwrite file otherwise
			if (exerciseList.getHead() != NULL) {
				storeWeeklyPlan(exerciseStream, &exerciseList);
			}
			
			break;
		}
	}
}

/*************************************************************
 * Function: loadDailyPlan ()                                *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: loads a single plan from file into dietList  *
 * Input parameters: fstream& fileStream,                    *
 *		List<DietPlan>* dietList                             *
 * Returns: void                                             *
 * Preconditions: fileStream is an open stream               *
 * Postconditions:                                           *
 *************************************************************/
void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, List<DietPlan>* dietList) {
	DietPlan day;
	// use overloaded operator to read from file
	fileStream >> day;

	// add to end of list
	dietList->append(day);
}

/*************************************************************
 * Function: loadDailyPlan ()                                *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: loads a single plan from file into           *
 *		exerciseList                                         *
 * Input parameters: fstream& fileStream,                    *
 *		List<ExercisePlan>* exerciseList                     *
 * Returns: void                                             *
 * Preconditions: fileStream is an open stream               *
 * Postconditions:                                           *
 *************************************************************/
void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, List<ExercisePlan>* exerciseList) {
	ExercisePlan day;
	// use overloaded operator to read from file
	fileStream >> day;

	// add to end of list
	exerciseList->append(day);
}

/*************************************************************
 * Function: loadWeeklyPlan ()                               *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: loads a while week's plan from input file    *
 *		into dietList                                        *
 * Input parameters: fstream& fileStream,                    *
 *		List<DietPlan>* dietList                             *
 * Returns: void                                             *
 * Preconditions: fileStream is an open stream               *
 * Postconditions:                                           *
 *************************************************************/
void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, List<DietPlan>* dietList) {
	// loop over input file for 7 days of the weekly plan
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(fileStream, dietList);
	}
}

/*************************************************************
 * Function: loadWeeklyPlan ()                               *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: loads a while week's plan from input file    *
 *		into exerciseList                                    *
 * Input parameters: fstream& fileStream,                    *
 *		List<ExercisePlan>* exerciseList                     *
 * Returns: void                                             *
 * Preconditions: fileStream is an open stream               *
 * Postconditions:                                           *
 *************************************************************/
void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, List<ExercisePlan>* exerciseList) {
	// loop over input file for 7 days of the weekly plan
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(fileStream, exerciseList);
	}
}

/*************************************************************
 * Function: displayDailyPlan ()                             *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: displays the day's plan for the given        *
 *		DietPlan object                                      *
 * Input parameters: DietPlan plan                           *
 * Returns: void                                             *
 * Preconditions: plan is an instantiated DietPlan object    *
 * Postconditions:                                           *
 *************************************************************/
void FitnessAppWrapper::displayDailyPlan(DietPlan plan) {
	// use overloaded operator
	cout << plan;
}

/*************************************************************
 * Function: displayDailyPlan ()                             *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: displays the day's plan for the given        *
 *		ExercisePlan object                                  *
 * Input parameters: ExercisePlan plan                       *
 * Returns: void                                             *
 * Preconditions: plan is an instantiated ExercisePlan object*
 * Postconditions:                                           *
 *************************************************************/
void FitnessAppWrapper::displayDailyPlan(ExercisePlan plan) {
	// use overloaded operator
	cout << plan;
}

/*************************************************************
 * Function: displayWeeklyPlan ()                            *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: display data for all days of week's plan     *
 * Input parameters: List<DietPlan>* dietList, bool numbered *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void FitnessAppWrapper::displayWeeklyPlan(List<DietPlan>* dietList, bool numbered) {
	// get and store the Head pointer of the list
	ListNode<DietPlan>* pCurrent = dietList->getHead();
	int ct = 0;

	// loop over list until end
	while (pCurrent != NULL) {
		// if specified also print numbers for the days
		if (numbered) {
			cout << "[" << ct << "]" << endl;
			ct++;
		}

		// display data for pCurrent and add newline
		displayDailyPlan(pCurrent->getData());
		cout << endl;

		// increment list
		pCurrent = pCurrent->getNext();
	}
}

/*************************************************************
 * Function: displayWeeklyPlan ()                            *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: display data for all days of week's plan     *
 * Input parameters: List<ExercisePlan>* exerciseList,       *
 *		bool numbered                                        *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void FitnessAppWrapper::displayWeeklyPlan(List<ExercisePlan>* exerciseList, bool numbered) {
	ListNode<ExercisePlan>* pCurrent = exerciseList->getHead();
	int ct = 0;

	// loop over list until end
	while (pCurrent != NULL) {
		// if specified also print numbers for the days
		if (numbered) {
			cout << "[" << ct << "]" << endl;
			ct++;
		}

		// display data for pCurrent and add newline
		displayDailyPlan(pCurrent->getData());
		cout << endl;

		// increment list
		pCurrent = pCurrent->getNext();
	}
}

/*************************************************************
 * Function: storeDailyPlan ()                               *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: stores day plan to file                      *
 * Input parameters: fstream& fileStream, DietPlan plan      *
 * Returns: void                                             *
 * Preconditions: plan is an instantiated DietPlan object    *
 *		and fileStream is an open file                       *
 * Postconditions:                                           *
 *************************************************************/
void FitnessAppWrapper::storeDailyPlan(fstream& fileStream, DietPlan plan) {
	// use overloaded operator
	fileStream << plan;
}

/*************************************************************
 * Function: storeDailyPlan ()                               *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: stores day plan to file                      *
 * Input parameters: fstream& fileStream, ExercisePlan plan  *
 * Returns: void                                             *
 * Preconditions: plan is an instantiated ExercisePlan object*
 *		and fileStream is an open file                       *
 * Postconditions:                                           *
 *************************************************************/
void FitnessAppWrapper::storeDailyPlan(fstream& fileStream, ExercisePlan plan) {
	// use overloaded operator
	fileStream << plan;
}

/*************************************************************
 * Function: storeWeeklyPlan ()                              *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: stores week of plans to given file           *
 * Input parameters: fstream& fileStream,                    *
 *		List<DietPlan>* dietList                             *
 * Returns: void                                             *
 * Preconditions: fileStream is an open file                 *
 * Postconditions:                                           *
 *************************************************************/
void FitnessAppWrapper::storeWeeklyPlan(fstream& fileStream, List<DietPlan>* dietList) {
	// get and store head pointer of list
	ListNode<DietPlan>* pCurrent = dietList->getHead();

	// loop over list
	while (pCurrent != NULL) {
		storeDailyPlan(fileStream, pCurrent->getData());

		// increment list
		pCurrent = pCurrent->getNext();
	}
}

/*************************************************************
 * Function: storeWeeklyPlan ()                              *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: stores week of plans to given file           *
 * Input parameters: fstream& fileStream,                    *
 *		List<ExercisePlan>* exerciseList                     *
 * Returns: void                                             *
 * Preconditions: fileStream is an open file                 *
 * Postconditions:                                           *
 *************************************************************/
void FitnessAppWrapper::storeWeeklyPlan(fstream& fileStream, List<ExercisePlan>* exerciseList) {
	// get and store head pointer of list
	ListNode<ExercisePlan>* pCurrent = exerciseList->getHead();

	// loop over list
	while (pCurrent != NULL) {
		storeDailyPlan(fileStream, pCurrent->getData());

		// increment list
		pCurrent = pCurrent->getNext();
	}
}

/*************************************************************
 * Function: editDailyPlan ()                                *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: allows editing goal of daily plan after      *
 *		prompting user for which day to edit                 *
 * Input parameters: List<DietPlan>* plan                    *
 * Returns: void                                             *
 * Preconditions: plan is instantiated with 7 entries        *
 * Postconditions:                                           *
 *************************************************************/
void FitnessAppWrapper::editDailyPlan(List<DietPlan>* plan) {
	int option;
	ListNode<DietPlan>* toEdit;

	// prompt user for which day to edit
	displayWeeklyPlan(plan, true);
	option = promptIntInRange(0, 6, "Enter a day to edit: ");
	
	// get a pointer to the day to edit and call prompt to edit
	toEdit = plan->getNthItem(option);
	toEdit->getDataPtr()->editGoal();

	// clear screen and display new week's plan
	system("CLS");
	displayWeeklyPlan(plan, false);
}

/*************************************************************
 * Function: editDailyPlan ()                                *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: allows editing goal of daily plan after      *
 *		prompting user for which day to edit                 *
 * Input parameters: List<ExercisePlan>* plan                *
 * Returns: void                                             *
 * Preconditions: plan is instantiated with 7 entries        *
 * Postconditions:                                           *
 *************************************************************/
void FitnessAppWrapper::editDailyPlan(List<ExercisePlan>* plan) {
	int option;
	ListNode<ExercisePlan>* toEdit;

	// prompt user for which day to edit
	displayWeeklyPlan(plan, true);
	option = promptIntInRange(0, 6, "Enter a day to edit: ");

	// get a pointer to the day to edit and call prompt to edit
	toEdit = plan->getNthItem(option);
	toEdit->getDataPtr()->editGoal();

	// clear screen and display new week's plan
	system("CLS");
	displayWeeklyPlan(plan, false);
}

/*************************************************************
 * Function: displayMenu ()                                  *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description: prints the 9 menu options to screen          *
 * Input parameters: void                                    *
 * Returns: void                                             *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void FitnessAppWrapper::displayMenu(void) {
	string options[9] = { "Load weekly diet plan from file",
	"Load weekly exercise plan from file",
	"Store weekly diet plan to file",
	"Store weekly exercise plan to file",
	"Display weekly diet plan to screen",
	"Display weekly exercise plan to screen",
	"Edit daily diet plan",
	"Edit daily exercise plan",
	"Exit"
	};

	for (int i = 0; i < 9; i++) {
		cout << "[" << i << "] " << options[i] << endl;
	}
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
int promptIntInRange(int min, int max, string message) {
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
