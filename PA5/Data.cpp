#include "Data.h"

Data::Data(int customerNumber, int serviceTime, int totalTime) {
	mCustomerNumber = customerNumber;
	mServiceTime = serviceTime;
	mTotalTime = totalTime;
}

int Data::getCustomerNumber(void) const {
	return mCustomerNumber;
}

void Data::setCustomerNumber(int number) {
	mCustomerNumber = number;
}

int Data::getServiceTime(void) const {
	return mServiceTime;
}

void Data::setServiceTime(int time) {
	mServiceTime = time;
}

void Data::decrementServiceTime(void) {
	mServiceTime--;
}

int Data::getTotalTime(void) const {
	return mTotalTime;
}

void Data::setTotalTime(int time) {
	mTotalTime = time;
}

ostream& operator<< (ostream& lhs, const Data& rhs) {
	lhs << "Customer number: " << rhs.getCustomerNumber() << endl;
	lhs << "Service time: " << rhs.getServiceTime() << endl;
	lhs << "Total time: " << rhs.getTotalTime() << endl;

	return lhs;
}