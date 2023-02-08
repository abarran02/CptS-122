/*******************************************************************************
 * Programmer: Alec Barran                                                     *
 * Class: CptS 122; Lab Section 06                                             *
 * Programming Assignment: PA8                                                 *
 * Date:                                                                       *
 *                                                                             *
 * Description: Reads product buying and selling data from file, place data in *
 *			binary search trees. Then run data analysis on the input.          *
 *                                                                             *
 * Relevant Formulas: Refer to each function definition.                       *
 *                                                                             *
 * Format of record in input file (data.csv): Units,Type,Transaction           *
 ******************************************************************************/

#pragma once

#include <fstream>
#include <sstream>
#include "BST.h"

using std::getline;
using std::stoi;

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