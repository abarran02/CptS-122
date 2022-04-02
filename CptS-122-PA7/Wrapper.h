#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <sstream>

#include "Data.h"
#include "List.h"
#include "Stack.h"

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::getline;

class Wrapper {
public:
	Wrapper(string classFile);
	~Wrapper();
	Wrapper(const Wrapper& app);

	void run();
	
private:
	List<Data> mMaster;
	string mClassFile;
	fstream classStream;

	void printMenu();
	void importCourseList();
	void loadMasterList();
	void storeMasterList();
	void markAbsences();
	void editAbsences();
	void generateReport();

	string getDate();
	Data parseLine(string line);
};

int promptIntInRange(int min, int max, string message);