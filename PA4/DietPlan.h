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

#pragma once

#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::fstream;
using std::cin;

class DietPlan {
private:
	int mGoal;
	string mName;
	string mDate;

	int promptIntInRange(int min, int max, string message);
public:
	// constructor with default parameters
	DietPlan(int goal = 0, string name = "", string date = "01/01/1970");
	
	// destructor
	~DietPlan();

	// copy constructor
	DietPlan(const DietPlan& plan);

	// getters and setters
	int getGoal(void) const;
	void setGoal(int goal);

	string getName(void) const;
	void setName(string name);

	string getDate(void) const;
	void setDate(string date);

	// user prompt for edit
	void editGoal(void);
};

// overloaded operators
fstream& operator>> (fstream& lhs, DietPlan& rhs);
ostream& operator<< (ostream& lhs, const DietPlan& rhs);
fstream& operator<< (fstream& lhs, const DietPlan& rhs);