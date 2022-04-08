#include "DataAnalysis.h"

DataAnalysis::DataAnalysis() {
	openCsv();
}

DataAnalysis::~DataAnalysis() {
	mCsvStream.close();
}

void DataAnalysis::runAnalysis() {
	readLoop();
}

void DataAnalysis::openCsv() {
	mCsvStream.open("data.csv", 'r');
}

Item DataAnalysis::readParseLine() {
	Item current;
	std::stringstream parse;
	string line;
	// get next line in csv
	getline(mCsvStream, line);

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

	return current;
}

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

	mTreeSold.inOrderTraversal();
	mTreePurchased.inOrderTraversal();
}

void DataAnalysis::insertIntoTrees(Item data) {
	if (data.transaction == "Sold") {
		mTreeSold.insert(data.product, data.units);
	}
	else {
		mTreePurchased.insert(data.product, data.units);
	}
}

void DataAnalysis::displayAnalysis() {
	cout << "Smallest sold:" << mTreeSold.findSmallest() << endl;
	cout << "Largest sold:" << mTreeSold.findLargest() << endl;
	cout << "Smallest purchsed:" << mTreePurchased.findSmallest() << endl;
	cout << "Largest purchsed:" << mTreePurchased.findLargest() << endl;
}