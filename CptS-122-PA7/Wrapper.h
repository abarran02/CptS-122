#pragma once

#include "Data.h"
#include "List.h"
#include "Stack.h"

using std::cout;
using std::endl;

class Wrapper {
public:
	void printMenu();
private:
	List<Data> mMaster;

	string getDate();
};