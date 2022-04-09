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

#include "DataAnalysis.h"

/*************************************************************
 * Function: DataAnalysis ()                                 *
 * Description: default constructor for DataAnalysis class   *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions: data.csv exists                            *
 * Postconditions: data.csv loaded into mCsvStream           *
 *************************************************************/
DataAnalysis::DataAnalysis() {
	openCsv();
}

/*************************************************************
 * Function: ~DataAnalysis ()                                *
 * Description: destructor for BST class                     *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions: data.csv is closed                        *
 *************************************************************/
DataAnalysis::~DataAnalysis() {
	mCsvStream.close();
}

/*************************************************************
 * Function: runAnalysis ()                                  *
 * Description: run data analytics on data read from data.csv*
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void DataAnalysis::runAnalysis() {
	readLoop();

	// print both trees to screen
	cout << "Sold items:" << endl;
	mTreeSold.inOrderTraversal();
	cout << "Purchased items:" << endl;
	mTreePurchased.inOrderTraversal();
	cout << endl;

	displayAnalysis();
}

/*************************************************************
 * Function: openCsv ()                                      *
 * Description: opens data.csv into mCsvStream               *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void DataAnalysis::openCsv() {
	mCsvStream.open("data.csv", std::ifstream::in);
}

/*************************************************************
 * Function: readParseLine ()                                *
 * Description: read line from mCsvStream and place in Item  *
 * Input parameters:                                         *
 * Returns: Item                                             *
 * Preconditions:                                            *
 * Postconditions: Item.units = -1 if read error             *
 *************************************************************/
Item DataAnalysis::readParseLine() {
	Item current;
	std::stringstream parse;
	string line;
	// get next line in csv
	getline(mCsvStream, line);

	if (line == "") {
		current.units = -1;
	}
	else {
		// load line into string stream
		parse.str(line);

		// units
		getline(parse, line, ',');
		current.units = stoi(line);
		// product name
		getline(parse, line, ',');
		current.product = line;
		// transaction type
		getline(parse, line, ',');
		current.transaction = line;
	}

	return current;
}

/*************************************************************
 * Function: readLoop ()                                     *
 * Description: read loops over mCsvStream and insert into   *
 *		appropriate binary tree                              *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void DataAnalysis::readLoop() {
	string line;
	Item current;

	// discard title line
	getline(mCsvStream, line);

	current = readParseLine();

	while (current.units != -1) {
		insertIntoTrees(current);
		current = readParseLine();
	}
}

/*************************************************************
 * Function: insertIntoTrees ()                              *
 * Description: inserts Item into appropriate binary tree    *
 * Input parameters: Item data                               *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void DataAnalysis::insertIntoTrees(Item data) {
	if (data.transaction == "Sold") {
		mTreeSold.insert(data.product, data.units);
	}
	else {
		mTreePurchased.insert(data.product, data.units);
	}
}

/*************************************************************
 * Function: displayAnalysis ()                              *
 * Description: display most/least sold/purchased items to   *
 *		the screen                                           *
 * Input parameters:                                         *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void DataAnalysis::displayAnalysis() {
	cout << "Most sold product:" << endl << mTreeSold.findLargest() << endl;
	cout << "Least sold product:" << endl << mTreeSold.findSmallest() << endl;
	cout << "Most purchased product:" << endl << mTreePurchased.findLargest() << endl;
	cout << "Least purchased product:" << endl << mTreePurchased.findSmallest() << endl;
}