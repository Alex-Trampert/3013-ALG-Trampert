/////////////////////////////////////////////////////////////////////////////////
// Author:           Alex Trampert
// Email:            alextrampert2000@gmail.com
// Label:            uVA 10261
// Title:            Ferry Loading 1
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
// 		Tries to load a ferry the most efficiently it can until
//		the ferry is full, or has no more cars to board. Given
//		ferry length and car length.
//      
// Files:            
//		main.cpp
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int numInputs, num = 0;

	cin >> numInputs;
	//runs while there is input
	while (num < numInputs) {
		int ferry, numCars = 0;
		double car, portCur = 0, starbCur = 0;
		vector <string> order;
		bool full = false;
		//gets ferry length
		cin >> ferry;
		//tries to add cars while ferry is not yet full
		while (!full)
		{	//gets cars length and converts it
			cin >> car;
			car = car / 100;
			//runs if car has value
			if (car != 0)
			{	//if port has more cars
				if (portCur > starbCur)
				{	//tries to add to port
					if (portCur + car <= ferry)
					{	portCur = portCur + car;
						order.push_back("port");
					}
					//tries to add to starboard
					else if (starbCur + car <= ferry)
					{	starbCur = starbCur + car;
						order.push_back("starboard");
					}
					//is full
					else
						full = true;
				}
				//if starboard has more cars
				else if (starbCur > portCur)
				{	//tries to add to starboard
					if (starbCur + car <= ferry)
					{	starbCur = starbCur + car;
						order.push_back("starboard");
					}
					//tries to add to port
					else if (portCur + car <= ferry)
					{	portCur = portCur + car;
						order.push_back("port");
					}
					//is full
					else
						full = true;
				}
				//if sides are even
				else
					//tries to add to port
					if (portCur + car <= ferry)
					{	portCur = portCur + car;
						order.push_back("port");
					}
					//tries to add to starboard
					else if (starbCur + car <= ferry)
					{	starbCur = starbCur + car;
						order.push_back("starboard");
					}
					//is full
					else
						full = true;
				//updates number of cars
				if (car > 0 && full != true)
					numCars++;
			}
			else
				full = true;
		}
		//makes sure data is over
		while (car != 0)
		{	cin >> car;
		}

		//outputs number of cars and position on ferry
		cout << numCars << '\n';
		for (int i = 0; i < order.size(); i++)
		{	cout << order[i];
			if ((i + 1) <= order.size())
				cout << '\n';
		}
		//updates input num
		num++;
		if ((num + 1) <= numInputs)
			cout << "\n";
	}

	return 0;
}