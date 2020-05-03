/////////////////////////////////////////////////////////////////////////////////
// Author:           Alex Trampert
// Email:            alextrampert2000@gmail.com
// Label:            uVA 11597
// Title:            Spanning Subtrees
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
// 		Finds the maximum number of spanning trees that can be formed in 
//		such a way that no two of these spanning trees have a common edge
//      
// Files:            
//		main.cpp
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

int main() {
	int numVerts, totalEdges, subtrees, minEdges;
	int count = 1;								//counter for case number
	
	cin >> numVerts;							//read in first case

	while (numVerts != 0) {
		minEdges = numVerts - 1;				//min edges for a subtree (n - 1)
		totalEdges = (numVerts * minEdges) / 2;	//complete graph n(n - 1)/2
		subtrees = totalEdges / minEdges;		//number of subtrees (total/min)

		cout << "Case " << count << ": " << subtrees << '\n'; //output

		count++;								//progrees case number
		cin >> numVerts;						//read in new case
	}
	
	return 0;
}