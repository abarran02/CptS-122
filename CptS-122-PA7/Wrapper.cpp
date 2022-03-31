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