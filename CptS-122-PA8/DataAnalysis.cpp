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
	string line;
	getline(mCsvStream, line);
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