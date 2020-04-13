/////////////////////////////////////////////////////////////////////////////////
// Author:           Alex Trampert
// Email:            alextrampert2000@gmail.com
// Label:            uVA 484
// Title:            Department of Redundancy Department
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
// 		Counts the number of times specific ints appear in a list
//      
// Files:            
//		main.cpp
/////////////////////////////////////////////////////////////////////////////////
#include <vector>
#include <iostream>

using namespace std;

int main() {
	vector <int> counts;				//new ints
	vector < vector <int> > inputs;		//number times of int
	int input;
	bool found = false;

	//logic for reading in the data
	while (!cin.eof()) {
		cin >> input;
		if (!cin)
			break;

		//if the int already exists, add 1 to the vector
		for (int i = 0; i < inputs.size(); i++)
			if (inputs[i][0] == input) {
				found = true;					//marks found to break outer loop
				inputs[i].push_back(input);		//adds the int to the counter	
				i = inputs.size();				//breaks inner loop
			}

		//if the int doesnt exist yet, add a new vector for it
		if (found == false) {
			counts.clear();				//clears temp holder
			counts.push_back(input);	//adds the new word
			inputs.push_back(counts);	//+1 to new word
		}	
				
		found = false;
	}
	//reads the different ints and how many of them
	for (int i = 0; i < inputs.size(); i++) 
		cout << inputs[i][0] << " " << inputs[i].size() << '\n';

	return 0;
}