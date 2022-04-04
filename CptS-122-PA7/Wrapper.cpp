#include "Wrapper.h"

Wrapper::Wrapper(string classFile, string masterFile) {
	mClassFile = classFile;
	classStream.open(classFile);

	mMasterFile = masterFile;
	masterRead.open(mMasterFile);
}

Wrapper::~Wrapper() {
	classStream.close();
	masterRead.close();
}

Wrapper::Wrapper(const Wrapper& app) {
	classStream.open(app.mClassFile);
	masterRead.open(app.mMasterFile);
}

bool Wrapper::checkOpenFiles() {
	// check that both class and master files opened successfully
	if (!classStream.is_open()) {
		cout << "Unable to open " << mClassFile;
		return false;
	}
	else if (!masterRead.is_open()) {
		cout << "Unable to open " << mMasterFile;
		return false;
	}

	return true;
}

void Wrapper::run() {
	int option;
	bool exit = !checkOpenFiles();

	while (!exit) {
		// display menu and prompt user for a menu option to execute
		printMenu();
		option = promptIntInRange(0, 6, "Enter an option : ");
		// clear the screen
		system("CLS");

		switch (option) {
		case 0:
			importCourseList();
			break;
		case 1:
			loadMasterList();
			break;
		case 2:
			storeMasterList();
			break;
		case 3:
			markAbsences();
			break;
		case 4:
			editAbsences();
			break;
		case 5:
			generateReport();
			break;
		case 6:
			exit = true;
			break;
		}
	}
}

void Wrapper::printMenu() {
	string options[7] = { "Import course list", "Load master list", "Store master list",
	"Mark absences", "Edit absences", "Generate report", "Exit" };

	for (int i = 0; i < 7; i++) {
		cout << "[" << i << "] " << options[i] << endl;
	}
}

void Wrapper::importCourseList() {
	string line;
	mMaster.clearList();
	Data newData;

	// with help from https://stackoverflow.com/questions/5343173/
	classStream.clear();
	classStream.seekg(0);

	// discard title line
	getline(classStream, line);
	
	// iterate 2nd line through end
	while (getline(classStream, line)) {
		newData = parseLine(line, false);
		mMaster.insertAtFront(newData);
	}
}

Data Wrapper::parseLine(string line, bool master) {
	string item, date;
	stringstream lineStream, nameStream;
	Data newData;

	// load line into string stream
	lineStream.str(line);
	nameStream.str(string());

	getline(lineStream, item, ',');
	newData.setRecord(stoi(item));

	getline(lineStream, item, ',');
	newData.setID(stoi(item));

	getline(lineStream, item, ',');
	nameStream << item << ",";
	getline(lineStream, item, ',');
	nameStream << item;
	newData.setName(nameStream.str());

	getline(lineStream, item, ',');
	newData.setEmail(item);

	getline(lineStream, item, ',');
	if (item == "AU") {
		newData.setUnits(-1);
	}
	else {
		newData.setUnits(stoi(item));
	}

	getline(lineStream, item, ',');
	newData.setProgram(item);

	getline(lineStream, item, ',');
	newData.setLevel(item);

	// if importing from master list file
	if (master) {
		getline(lineStream, item, ',');
		// check if there are absences to import
		if (stoi(item) != 0) {
			// split dates and push to stack if available
			getline(lineStream, item, ',');
			if (item != "") {
				// remove leading and trailing quotation marks
				item = item.substr(1, item.length() - 2);
				nameStream.str(item);
				
				// split final string by comma delimiter
				while (getline(nameStream, date, ',')) {
					newData.addAbsence(date);
				}
			}
		}
	}

	return newData;
}

void Wrapper::loadMasterList() {
	string line;
	mMaster.clearList();
	Data newData;

	masterRead.clear();
	masterRead.seekg(0);

	// iterate file through end
	while (getline(masterRead, line)) {
		newData = parseLine(line, true);
		mMaster.insertAtFront(newData);
	}
}

void Wrapper::storeMasterList() {
	string date;
	stringstream line;
	Node<Data>* pCurrent = mMaster.getHead();
	Data* cData;
	Stack<string> absenceStack;

	masterWrite.open(mMasterFile);

	// iterate over master list and store data to file
	while (pCurrent != NULL) {
		line.str(string());
		// get current data to operate on
		cData = pCurrent->getData();

		// construct string for absence dates
		if (cData->getAbsenceCount() > 0) {
			line << "\"";
			// get a copy of cData absence stack
			absenceStack = cData->getAbsenceStack();
			// pop each item from stack
			while (absenceStack.pop(date)) {
				// add a comma as long as item isn't last in the list
				if (absenceStack.isEmpty()) {
					line << date;
				}
				else {
					line << date << ",";
				}
			}
			line << "\"";
		}

		// this solution is more memory intensive than a string of << calls
		// but this is more readable to me
		fprintCommaSeparated(cData->getRecord(), cData->getID(), cData->getName(), cData->getEmail(),
			cData->getUnits(), cData->getProgram(), cData->getLevel(), cData->getAbsenceCount(), line.str());

		// increment pCurrent
		pCurrent = pCurrent->getNext();
	}

	masterWrite.close();
}

void Wrapper::markAbsences() {
	Node<Data>* pCurrent = mMaster.getHead();
	Data* cData;
	int option;

	// iterate over master list
	while (pCurrent != NULL) {
		// print student name and absence options
		cData = pCurrent->getData();
		cout << "Was " << cData->getName() << " absent today?" << endl;
		cout << "[0] Yes" << endl << "[1] No" << endl;
		
		option = promptIntInRange(0, 1, "Enter an option: ");

		// add absence to list
		if (option == 0) {
			cData->addAbsence( getDate() );
		}

		// increment pCurrent
		pCurrent = pCurrent->getNext();
		system("CLS");
	}
	
}

Node<Data>* Wrapper::getStudentNode(int id) {
	Node<Data>* pCurrent = mMaster.getHead();

	// iterate over list to find matching student ID
	while (pCurrent != NULL) {
		// return matching Node if found
		if (pCurrent->getData()->getID() == id) {
			return pCurrent;
		}

		// increment pCurrent
		pCurrent = pCurrent->getNext();
	}

	return NULL;
}

Node<Data>* Wrapper::getStudentNode(string name) {
	Node<Data>* pCurrent = mMaster.getHead();

	// iterate over list to find matching student ID
	while (pCurrent != NULL) {
		// return matching Node if found
		if (pCurrent->getData()->getName() == name) {
			return pCurrent;
		}

		// increment pCurrent
		pCurrent = pCurrent->getNext();
	}

	return NULL;
}

void Wrapper::editAbsences() {
	Node<Data>* student;
	Stack<string> absences;
	string name, pop;
	int option;
	bool found = false;
	cout << "Enter student name or ID: ";
	cin >> name;

	// check if user entered an ID or student name
	if (isdigit(name[0])) {
		student = getStudentNode(stoi(name));
	}
	else {
		student = getStudentNode(name);
	}

	// continue as long as a matching student was found
	if (student != NULL) {
		// get old absence list and clear data in student pointer
		absences = student->getData()->getAbsenceStack();
		student->getData()->clearAbsences();
		// get user input for date to edit
		cout << "Enter date to edit: ";
		cin >> name;
		// get whether student was present on this date
		cout << "[0] Student was present" << endl << "[1] Student was absent" << endl;
		option = promptIntInRange(0, 1, "Enter an option: ");

		// iterate over original absence stack
		while (absences.pop(pop)) {
			// as long as entered date hasn't yet been modified in stack
			if (!found && (pop == name || pop > name)) {
				// date found in original stack or entered date is before current date in stack
				if (option) {
					// ensure student was actually absent and add back to stack
					if (pop > name) {
						student->getData()->addAbsence(pop);
					}

					student->getData()->addAbsence(name);
				}
				
				found = true;
			}
			else {
				// add the rest of the old stack to the new stack
				student->getData()->addAbsence(pop);
			}
		}

		// need to reverse absence stack
		absences = student->getData()->getAbsenceStack();
		student->getData()->clearAbsences();
		while (absences.pop(pop)) {
			student->getData()->addAbsence(pop);
		}

		// entereed date either not in or after dates in stack
		if (!found) {
			student->getData()->addAbsence(name);
		}
	}
	else {
		cout << "Unable to find student " << name << endl;
	}
}

void Wrapper::generateReport() {
	Node<Data>* pCurrent = mMaster.getHead();
	Data* cData;
	// print options and get option from user
	cout << "[0] Generate report for all students" << endl << "[1+] Show only student with defined absences or more" << endl;
	int option = promptIntInRange(0, std::numeric_limits<int>::max(), "Enter an option: ");

	if (option == 0) {
		// print all student info
		while (pCurrent != NULL) {
			cout << *(pCurrent->getData()) << endl;

			pCurrent = pCurrent->getNext();
		}
	}
	else {
		// print only students with option or more absences
		while (pCurrent != NULL) {
			cData = pCurrent->getData();
			if (cData->getAbsenceCount() >= option) {
				cout << *(pCurrent->getData()) << endl;
			}

			pCurrent = pCurrent->getNext();
		}
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