#include "Wrapper.h"

Wrapper::Wrapper(string classFile) {
	mClassFile = classFile;
	classStream.open(classFile);
}

Wrapper::~Wrapper() {
	classStream.close();
}

Wrapper::Wrapper(const Wrapper& app) {
	classStream.open(app.mClassFile);
}

void Wrapper::run() {
	int option;
	bool exit = false;

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

string Wrapper::getDate() {
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

void Wrapper::importCourseList() {
	string line;
	mMaster.clearList();
	Data newData;

	// discard title line
	getline(classStream, line);
	
	// iterate 2nd line through end
	while (getline(classStream, line)) {
		newData = parseLine(line);
		mMaster.insertAtFront(newData);
	}
}

Data Wrapper::parseLine(string line) {
	string item, name;
	std::stringstream lineStream;
	Data newData;

	// load line into string stream
	lineStream.str(line);

	getline(lineStream, item, ',');
	newData.setRecord(stoi(item));

	getline(lineStream, item, ',');
	newData.setID(stoi(item));

	name = "";
	getline(lineStream, item, ',');
	name.append(item);
	name.append(",");
	getline(lineStream, item, ',');
	name.append(item);
	newData.setName(name);

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

	return newData;
}

void Wrapper::loadMasterList() {

}

void Wrapper::storeMasterList() {

}

void Wrapper::markAbsences() {

}

void Wrapper::editAbsences() {

}

void Wrapper::generateReport() {

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