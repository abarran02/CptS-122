#include "testQueue.h"

int main(void) {
	std::srand(std::time(NULL));
	//test.append("cereal");
	//test.append("banana");
	//test.append("tomato");

	testEnqueueEmpty();
	cout << endl;
	testEnqueueOne();
	cout << endl;
	testDequeueOne();
	cout << endl;
	testDequeueTwo();
	cout << endl;

	int n = promptIntInRange(0, std::numeric_limits<int>::max(), "How many minutes to run simulation? ");
	runSimulation(n);

	return 0;
}