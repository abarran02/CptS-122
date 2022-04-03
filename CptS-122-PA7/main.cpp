#include "Wrapper.h"

int main(void) {
	string classfile = "classList.csv", masterfile = "master.txt";
	Wrapper app(classfile, masterfile);
	app.run();

	return 0;
}