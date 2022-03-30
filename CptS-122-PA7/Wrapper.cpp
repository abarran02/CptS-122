#include "Wrapper.h"

void Wrapper::printMenu() {
	string options[7] = { "Import course list", "Load master list", "Store master list",
	"Mark absences", "Edit absences", "Generate report", "Exit" };

	for (int i = 0; i < 7; i++) {
		cout << "[" << i << "]" << options[i] << endl;
	}

	cout << getDate();
}

string Wrapper::getDate() {
	string date;
	time_t t = time(0);   // get time now
	struct tm* now = localtime(&t);
	date.append(itoa(now->tm_year + 1900));
	date.append("-");
	date.append(itoa(now->tm_mon + 1));
	date.append("-");
	date.append(itoa(now->tm_mday));

	return date;
}