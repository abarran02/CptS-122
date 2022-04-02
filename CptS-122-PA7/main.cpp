#include "Wrapper.h"

int main(void) {
	string infile = "classList.csv";
	Wrapper app(infile);
	app.run();

	return 0;
}