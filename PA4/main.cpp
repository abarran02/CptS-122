/*******************************************************************************
 * Programmer: Alec Barran                                                     *
 * Class: CptS 122; Lab Section 06                                             *
 * Programming Assignment: PA4                                                 *
 * Date: 03/02/2022                                                            *
 *                                                                             *
 * Description: Read and write diet and exercise plans to text files, and edit *
 *		their and display their contents in C++ using classes                  *
 * 		and class templates.                                                   *
 *                                                                             *
 * Format of record in input file (dietPlans.txt):                             *
 *                                                Bulking      (string name)   *
 *                                                3400         (int goal)      *
 *                                                03/04/2021   (string date)   *
 *                                                                             *
 * Format of output file (dietPlans.txt): Same as input.                       *
 ******************************************************************************/

#include "FitnessAppWrapper.h"

int main(void) {
	// create FitnessAppWrapper object with input file names
	FitnessAppWrapper app = FitnessAppWrapper("dietPlans.txt", "exercisePlans.txt");

	// run the FitnessApp
	app.runApp();
	
	return 0;
}