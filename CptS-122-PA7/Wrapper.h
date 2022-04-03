#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include "Data.h"
#include "List.h"
#include "Stack.h"

using std::cout;
using std::cin;
using std::fstream;
using std::getline;
using std::stringstream;

class Wrapper {
public:
	Wrapper(string classFile, string masterFile);
	~Wrapper();
	Wrapper(const Wrapper& app);

	void run();
	
private:
	List<Data> mMaster;
	string mClassFile;
	fstream classStream;
	string mMasterFile;
	fstream masterStream;

	bool checkOpenFiles();

	void printMenu();
	void importCourseList();
	void loadMasterList();
	void storeMasterList();
	void markAbsences();
	void editAbsences();
	void generateReport();

	Data parseLine(string line, bool master);

	void fprintCommaSeparated() {
		masterStream << endl;
	}

	template<typename First, typename ... Strings>
	void fprintCommaSeparated(First arg, const Strings&... rest) {
		// with help from https://stackoverflow.com/questions/9040617/
		// and https://stackoverflow.com/questions/12024304/
		if (sizeof...(rest) == 0) {
			masterStream << arg;
		}
		else {
			masterStream << arg << ",";
		}
		
		fprintCommaSeparated(rest...);
	}
};

int promptIntInRange(int min, int max, string message);