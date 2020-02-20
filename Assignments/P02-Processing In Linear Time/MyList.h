///////////////////////////////////////////////////////////////////////////////               
// Author:           Alex Trampert
// Email:            alextrampert2000@gmail.com
// Label:            P02
// Title:            Processing In Linear Time
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
// 		Linked list program that will take and insert with 
//		a word and a definition both stored as strings. Has
//		a search function to check every item in the list to
//		find if a substring persists in it, and will then
//		count the number of words it is in, and store 
//		first 10 words, while printing both to the screen.   
//      
/////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

/**
 * Node
 * 
 * Description:
 *     Node to hold a word and its definition
 * 
 * Public Methods:
 *      string 			word
 *		string 			definition
 *		Node* 			next	
 * 
 * Private Methods:
 *      None
 * 
 * Usage: 
 * 		Node* Temp = new Node;		//Creates temp node for function use
 *      
 */
struct Node {
	std::string word;				//holds word
	std::string definition;			//holds definition
	Node* next;						//pointer to next node
};

/**
 * List
 * 
 * Description:
 *     Linked list to hold a word and its definition
 * 
 * Public Methods:
 *      List()  		(constructor)
 *		void 			insert(string, string)
 *		void 			print()	
 *		void 			searchFor(string)
 * 
 * Private Methods:
 *      Node*			head
 * 		Node*			tail
 * 		int 			size
 * 		string			top10[10]
 * 		int				words
 * 
 * Usage: 
 * 		List L;							//Creates temp node for function use
 *      L.insert("apple", "red fruit")  //adds word with definition
 * 		L.print()						//prints entire list
 * 		L.searchFor("ball")				//searches list for all words with ball
 */
class List {
private:
	Node* head;					//pointer to head of list
	Node* tail;					//pointer to tail of list
	int size;					//int for the size of list
	std::string top10[10];		//first 10 words of given substring
	int words = 0;				//number of words with given substring

public:
/**
 * Public : 
 * 		List()
 * 
 * Description:
 *      default constructor
 * 
 * Params:
 *     	None
 * 
 * Returns:
 *     	None
 */
	List() {
		head = nullptr;
		tail = nullptr;
		size = 0;

		for (int i = 0; i < 10; i++)
			top10[i] = "";
	}

/**
 * Public : 
 * 		insert(string, string)
 * 
 * Description:
 *      inserts a new node into the list
 * 		containing the given word and definition
 * 
 * Params:
 *     	string w			//string for word
 * 		string d			//string for definition
 * 
 * Returns:
 *     	None
 */
	void insert(std::string w, std::string d) {
		Node* temp = new Node;
		temp->word = w;
		temp->definition = d;
		temp->next = nullptr;

		if (head == nullptr) {
			head = temp;
			size++;
		}

		else if(head->next == nullptr) {
			tail = temp;
			head->next = tail;
			size++;
		}

		else {
			tail->next = temp;
			tail = temp;
			size++;
		}

		temp = nullptr;
	}

/**
 * Public : 
 * 		print()
 * 
 * Description:
 *      prints all words and definitions from all
 * 		nodes contained in the list
 * 
 * Params:
 *     	None
 * 
 * Returns:
 *     	None
 */
	void print() {
		Node* temp = new Node;
		temp = head;
		while (temp != nullptr) {
			std::cout << temp->word << " - " << temp->definition << "\n";
			temp = temp->next;
		}

		temp = nullptr;
	}

/**
 * Public : 
 * 		searchFor(string)
 * 
 * Description:
 *      searches the entire list for all words
 * 		containing the given substring and counts the
 * 		words as well as storing and displaying
 * 		the first 10
 * 
 * Params:
 *     	string input		//substring to search for	
 * 
 * Returns:
 *     	None
 */
	void searchFor(std::string input) {
		Node* temp = new Node;
		temp = head;
		int i = 0;

		while (temp != nullptr) {
			std::string check = temp->word;
			size_t found = check.find(input);

			if (found != std::string::npos) {
				if (i < 10) {
					top10[i] = temp->word;
					i++;
				}
				words++;
			}

			temp = temp->next;
		}

		std::cout << words << " words found!\n";

		if (top10[0] == "")
			std::cout << "No matches found!";

		int j = 0;
		while (j < 10 && top10[j] != "") {
			std::cout << top10[j] << " -> ";
			j++;
		}

		std::cout << '\n';

		for (int i = 0; i < 10; i++)
			top10[i] = "";

		words = 0;
	}
};