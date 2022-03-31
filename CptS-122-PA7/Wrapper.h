#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

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