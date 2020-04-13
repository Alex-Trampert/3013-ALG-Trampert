/////////////////////////////////////////////////////////////////////////////////
// Author:           Alex Trampert
// Email:            alextrampert2000@gmail.com
// Label:            uVA 459
// Title:            Graph Connectivity
// Course:           CMPS 3013
// Semester:         Spring 2020
//
// Description:
// 		Finds all connected subgraph components within a given graph
//      
// Files:            
//		main.cpp
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Node
 *
 * Description:
 *     Node to hold the vertice and its edges
 *
 * Public Methods:
 *      char			vertice
 *		vector 			edges
 *		bool			connected
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
	char vertice = 1;
	vector <Node*> edges;
	bool connected = false;
	Node* next = NULL;
};

/**
 * List
 *
 * Description:
 *     Linked list to hold a graph
 *
 * Public Methods:
 *      List()  		(constructor)
 *		void 			insert(char)
 *		void 			connectNodes(char, char)
 *		int 			findConComps()
 *
 * Private Methods:
 *      Node*			head
 * 		Node*			tail
 * 		int 			size
 * 		int				comps
 *      void			findConnections(Node*)
 *
 * Usage:
 * 		List L;							//Creates temp node for function use
 *      L.insert('A')					//adds vertice 'A' to graph
 * 		L.connectNodes('A', 'B')		//connects nodes A and B
 *		L.findConComps()				//searches the graph for con. components
 * 	
 */
class List {
private:
	Node* head;					
	Node* tail;					
	int size;					
	int comps;
 /**
 * Public :
 * 		findConnections(Node*)
 *
 * Description:
 *      recursively traverses graph to find all subgraphs
 *
 * Params:
 *		Node*           //next node to check
 *
 * Returns:
 *     	None
 */
	void findConnections(Node* temp) {
		temp->connected = true;

		if (temp->edges.size() != 0) {
			for (int j = 0; j < temp->edges.size(); j++)
				if (temp->edges[j]->connected != true)
					findConnections(temp->edges[j]);
		}

	}
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
		comps = 0;
	}
 /**
 * Public :
 * 		insert(char)
 *
 * Description:
 *      inserts a new node into the list
 * 		containing the given vertice
 *
 * Params:
 *		char				//vertic♂ for node
 *
 * Returns:
 *     	None
 */
	void insert(char v) {
		Node* temp = new Node;
		temp->vertice = v;
		temp->next = nullptr;

		if (head == nullptr) {
			head = temp;
			size++;
		}

		else if (head->next == nullptr) {
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
 * 		connectNodes(char, char)
 *
 * Description:
 *      connects 2 nodes within the list
 *
 * Params:
 *     	char vert			//char for vertice
 * 		char edge			//char for edge
 *
 * Returns:
 *     	None
 */
	void connectNodes(char vert, char edge) {
		Node* temp = new Node;
		Node* temp2 = new Node;
		temp = temp2 = head;
		while (temp != nullptr) {
			if (temp->vertice == vert) {
				while (temp2 != nullptr) {
					if (temp2->vertice == edge) {
						temp->edges.push_back(temp2);
						temp2->edges.push_back(temp);
						temp2 = tail;
					}
					temp2 = temp2->next;
				}
				temp = tail;
			}
			temp = temp->next;
		}
	}

/**
 * Public :
 * 		findConComps()
 *
 * Description:
 *      finds all connected subgraphs within the list
 *
 * Params:
 *     	None
 *
 * Returns:
 *     	None
 */
	int findConComps() {
		Node* temp = new Node;
		temp = head;
		for (int i = 0; i < size; i++) {
			if (temp->connected != true) {
				findConnections(temp);
				comps++;
			}
			temp = temp->next;
		}
		return comps;
	}

};

int main() {
	int sets;
	int i = 0;
	cin >> sets;

	//logic for graphs
	while (i < sets) {
		char highVal;
		int j, comps;
		string edge, newedge;
		List graph;
		cin >> highVal;
		j = int(highVal) - 64;

		//inserting the used characters
		for (int i = 0; i < j; i++)
			graph.insert('A' + i);

		//connecting characters with edges, both ways bc undirected
		while (edge == "")
			getline(cin, edge);
		while (edge != "") {
			graph.connectNodes(edge[0], edge[1]);
			getline(cin, newedge);
			if (newedge == edge)
				edge = "";
			else
				edge = newedge;
		}

		//finds the connected components in the graphs
		comps = graph.findConComps();
		cout << comps << '\n';
		//whether its last sequence to place a new line
		i++;
		if (i < sets)
			cout << '\n';
	}

	return 0;
}