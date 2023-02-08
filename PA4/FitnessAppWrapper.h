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

#include "DietPlan.h"
#include "ExercisePlan.h"
#include "List.h"
#include <fstream>

using std::fstream;
using std::cin;

class FitnessAppWrapper {
private:
	string mDietFile;
	fstream dietStream;
	string mExerciseFile;
	fstream exerciseStream;

public:
	// constructor
	FitnessAppWrapper(string dietFile, string exerciseFile);

	// destructor
	~FitnessAppWrapper();

	// copy constructor
	FitnessAppWrapper(const FitnessAppWrapper& app);

	void runApp(void);

	void loadDailyPlan(fstream& fileStream, List<DietPlan>* dietList);
	void loadDailyPlan(fstream& fileStream, List<ExercisePlan>* exerciseList);

	void loadWeeklyPlan(fstream& fileStream, List<DietPlan>* dietList);
	void loadWeeklyPlan(fstream& fileStream, List<ExercisePlan>* exerciseList);

	void displayDailyPlan(DietPlan plan);
	void displayDailyPlan(ExercisePlan plan);

	void displayWeeklyPlan(List<DietPlan>* dietList, bool numbered);
	void displayWeeklyPlan(List<ExercisePlan>* dietList, bool numbered);

	void storeDailyPlan(fstream& fileStream, DietPlan plan);
	void storeDailyPlan(fstream& fileStream, ExercisePlan plan);

	void storeWeeklyPlan(fstream& fileStream, List<DietPlan>* dietList);
	void storeWeeklyPlan(fstream& fileStream, List<ExercisePlan>* exerciseList);

	void editDailyPlan(List<DietPlan>* plan);
	void editDailyPlan(List<ExercisePlan>* plan);
	
	void displayMenu(void);
};

int promptIntInRange(int min, int max, string message);