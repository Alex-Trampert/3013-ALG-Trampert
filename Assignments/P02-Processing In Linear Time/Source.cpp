///////////////////////////////////////////////////////////////////////////////               
// Author:           Alex Trampert
// Email:            alextrampert2000@gmail.com
// Label:            P02
// Title:            Processing In Linear Time
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
// 		Loads a Json dictionary into a linked list, and then uses
//		getch function in order to traverse and search the list 
//		with an auto complete function like google. Also times
//		each search and load of the library.   
//      
// Files:            
//		Source.cpp
//		MyList.h
//		json.hpp
//		JsonFacade.hpp
//		mygetch.hpp
//		Timer.hpp
//		dict_w_defs.json
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "JsonFacade.hpp"
#include "Timer.hpp"
#include <time.h>
#include <chrono>
#include "mygetch.hpp"
#include "MyList.h"

using namespace std;

int main() {
	Timer T;				//create instance of timer
	double time;			//value for holding time
			
	List L;					//create instance of list

	JsonFacade JFac("dict_w_defs.json");

	std::string key;
	std::vector<std::string> keys = JFac.getKeys();

	//loads the dictionary into the linked list
	T.Start();
	for (int i = 0; i < keys.size(); i++)
	{
		std::string DicWord = JFac.getKey(i);            //gets terms in alpha order 0-X
		std::string DicDef = JFac.getValue(DicWord);     //gets def of term
		L.insert(DicWord, DicDef);           			 //loads deg and term
	}
	T.End();
	time = T.MilliSeconds();
	std::cout << '\n' << time << " milliseconds to load dictionary!\n";
	//L.print();  <-comment as to not print a billion items
	
	char k = 0;              // holder for character being typed
	std::string word = "";   // var to concatenate letters to

	//prompt user
	std::cout << "Type keys to search the word bank. Hit 'enter/return'\n" 
			  << "to reset your word. Type '~' to quit.\n" << std::endl;

	// While capital ~ is not typed keep looping
	while ((k = getch()) != '~') {
		word += k;          // append char to word

		if ((int)k != 13) {   // if k is not enter print it
			//std::cout << "Key: " << k << " = " << (int)k << std::endl;
			std::cout << "Search: " << word << std::endl;
			T.Start();
			L.searchFor(word);
			T.End();
			time = T.MilliSeconds();
			std::cout << time << " milliseconds to load matches!\n\n";
		}

		// hitting enter sets word back to empty
		if ((int)k == 13) {
			std::cout << "Enter pressed ... Word is empty.\n" << std::endl;
			word = "";
		}
	}

	return 0;
}