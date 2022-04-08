#pragma once

#include <fstream>
#include "BST.h"

using std::getline;

typedef struct item {
	int units;
	string product;
	string transaction;
} Item;

class DataAnalysis {
public:
	DataAnalysis();
	~DataAnalysis();

	void runAnalysis();

private:
	BST mTreeSold;
	BST mTreePurchased;
	std::ifstream mCsvStream;

	void openCsv();
	Item readParseLine();
	void readLoop();
	void insertIntoTrees(Item data);

	void displayAnalysis();
};