/////////////////////////////////////////////////////////////////////////////////
// Author:           Alex Trampert
// Email:            alextrampert2000@gmail.com
// Label:            uVA 1112
// Title:            Mice and Maze
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
// 		Counts the number of tiles that can reach the exit tile
//		within a set time limit. Calculates shortest path from each 
//		location within the maze
//      
// Files:            
//		main.cpp
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

//finds all connections to the exit that are within time limit
int mazeFinder(int cells, int exit, int time, vector <pair<int, int>> graph[]) {
	priority_queue <pair<int, int>> prioq;

	int dist[101];
	//creates a spot for each cell
	for (int i = 1; i <= cells; i++) {
		dist[i] = INT_MAX;
	}
	//hardwires exit to maze
	prioq.push(pair<int, int>(exit, 0));
	dist[exit] = 0;
	int pos, des, dur, temp;

	//updates the shortest path to the exit with each connection
	while (!prioq.empty()) {
		pos = prioq.top().first;
		dur = prioq.top().second;
		prioq.pop();
		for (int i = 0; i < graph[pos].size(); i++) {
			des = graph[pos][i].first;
			temp = graph[pos][i].second;
			if (dist[pos] + temp < dist[des]) {
				dist[des] = dist[pos] + temp;
				prioq.push(pair<int, int>(des, dist[des]));
			}
		}
	}
	int count = 0;
	//counts number of cells under the time limit
	for (int i = 1; i <= cells; i++) {
		if (dist[i] <= time) {
			count++;
		}
	}
	return count;
}

int main() {
	//num of mazes, num of cells, exit cell, num of connections
	//allotted time, {position, destination, duration (connections: 1 2 1)}
	int num, cells, exit, connects, time, pos, des, dur;
	//num of mazes
	cin >> num;

	//loops for all mazes
	for (int i = 0; i < num; i++) {
		cin >> cells >> exit >> time >> connects;
		//loops for all connections in maze
		vector <pair<int, int>> graph[101];
		for (int i = 0; i < connects; i++) {
			cin >> pos >> des >> dur;
			graph[des].push_back(pair<int, int>(pos, dur));
		}
		//calculates how many cells succeed
		cout << mazeFinder(cells, exit, time, graph);
		//adding a line or not based on last case
		if (i == num - 1) {
			cout << "\n";
		}
		else {
			cout << "\n\n";
		}
		//clearing vector
		for (int i = 0; i <= cells; i++) {
			graph[i].clear();
		}
	}
	return 0;
}