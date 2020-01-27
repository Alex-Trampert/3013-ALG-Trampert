///////////////////////////////////////////////////////////////////////////////
// Author:           Alex Trampert
// Email:            alextrampert2000@gmail.com
// Label:            02-CommentedCode
// Title:            Assignment 2 - C++ Comments
// Course:           CMPS 3013-201
// Semester:         Spr 2020
//
// Description:
//       This program is used to create linked list which hold integers
//       and can be displayed easily. With overloaded + an [] operators
//       the lists can be combined or treated as an array to make 
//       them user friendly. They also have a function that will print the 
//       entire list as a string.
//
// Usage:
//       Fill lists with integers and use the operators to do 
//       necessary functions.
//
// Files:            
//       (commented)main.cpp
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

int A[100];         //array of 100 ints

/**
 * Node
 * 
 * Description:
 *      Data node for usage within the linked lists.
 *      Holds an integer value to be stored in list.
 * 
 * Methods:
 *       Node()
 *       Node(int n)
 * 
 * Usage: 
 *       Node node1;      //Creates default node holding value -1
 *       Node node2(3)    //Creates node holding value 3
 */
struct Node {
    int x;                //int value for node
    Node *next;           //pointer for next node value
    /**
     * Public : Node()
     * 
     * Description:
     *      Creates node with value -1
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      Nothing
     */
    Node() {
        x = -1;
        next = NULL;
    }
    /**
     * Public : Node(int n)
     * 
     * Description:
     *      Creates node with value n
     * 
     * Params:
     *      int - node value
     * 
     * Returns:
     *      Nothing
     */
    Node(int n) {
        x = n;
        next = NULL;
    }
};

/**
 * List
 * 
 * Description:
 *      Allows the creation of a linked list with nodes 
 *      that hold integer values. Also allows for access
 *      to head and tail nodes, and checking size of list.
 * 
 * Public Methods:
 *                      List()
 *      void            Push(int)
 *      void            Insert(int)
 *      void            PrintTail()
 *      string          Print()
 *      int             Pop()
 *      List            operator+(const List)
 *      int             operator[](int)
 *      friend ostream  &operator<<(ostream, List)
 * 
 * Private Methods:
 *      None
 * 
 * Usage: 
 *      List L1;            //creates list
 *      L1.Push(1);         //inserts value at end of list
 *      L1.Insert(1);       //inserts value before head of list
 *      L1.PrintTail();     //prints value in tail node of list
 *      L1.Print();         //prints list
 *      L1.Pop();           //removes tail value    
 *      L3 = L1 + L2;       //adds L2 to tail of L1 and puts all into L3
 *      L1[3];              //gets 3rd value in L1 like array
 *      cout << L1;         //prints entire L1 list
 *      
 */

class List {
private:
    Node *Head;         //creates head node
    Node *Tail;         //creates tail node
    int Size;           //value for list size

public:
    /**
     * Public : 
     *      List()
     * 
     * Description:
     *      Constructor for the List class
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      Nothing
     */
    List() {
        Head = Tail = NULL;
        Size = 0;
    }

    /**
     * Public :
     *      void Push(int)
     * 
     * Description:
     *      Adds value to the end of the list
     * 
     * Params:
     *      int - value to be added to the list
     * 
     * Returns:
     *      Nothing
     */
    void Push(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail) {
            Head = Tail = Temp;
        } else {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

    /**
     * Public : 
     *      void Insert(int)
     * 
     * Description:
     *      Inserts value at head of list
     * 
     * Params:
     *      int - value to be inserted at front of list
     * 
     * Returns:
     *      Nothing
     */
    void Insert(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail) {
            Tail = Head;
        }
        Size++;
    }

    /**
     * Public : 
     *      void PrintTail()
     * 
     * Description:
     *      Prints last value in list
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      Nothing
     */
    void PrintTail() {
        cout << Tail->x << endl;
    }

    /**
     * Public : 
     *      string Print()
     * 
     * Description:
     *      Creates string containing entire list in order
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      string - string containing the list
     */
    string Print() {
        Node *Temp = Head;
        string list;

        while (Temp != NULL) {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    /**
     * Public :
     *      int Pop()
     * 
     * Description:
     *      Removes last value in list
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      int - 0 at the moment because no implementation
     */
    // not implemented
    int Pop() {
        Size--;
        return 0; //
    }

    /**
     * Public : 
     *      List operator+(const List)
     * 
     * Description:
     *      Overloaded operator to combine lists together and put
     *      them into a new list.
     * 
     * Params:
     *      List - list to be combined onto current list
     * 
     * Returns:
     *      List - new list containing both combined lists
     */
    List operator+(const List &Rhs) {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    /**
     * Public : 
     *      int operator[](int)
     * 
     * Description:
     *      Overloaded operator to allow using list like an array.
     * 
     * Params:
     *      int - the position in the list user wishes to access
     * 
     * Returns:
     *      int - value within the position
     */
    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index) {
        Node *Temp = Head;

        if (index >= Size) {
            cout << "Index out of bounds, exiting";
            exit(0);
        } else {

            for (int i = 0; i < index; i++) {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    /**
     * Public : 
     *      friend ostream &operator<<(ostream, List)
     * 
     * Description:
     *      Overloaded operator to allow usage with cout command
     *      to print list like any variable
     * 
     * Params:
     *      ostream - to allow printing to screen
     *      List    - list to be printed
     * 
     * Returns:
     *      os - ostream object back to program
     */
    friend ostream &operator<<(ostream &os, List L) {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv) {
    List L1;                //Creates List L1
    List L2;                //Creates List L2

    for (int i = 0; i < 25; i++) {
        L1.Push(i);         //Pushes values 0-24 into L1
    }

    for (int i = 50; i < 100; i++) {
        L2.Push(i);         //Pushes values 50-99 into L2
    }

    //cout << L1 << endl;
    L1.PrintTail();         //Prints last value in L1
    L2.PrintTail();         //Prints last value in L2

    List L3 = L1 + L2;      //Adds lists L1 and L2 and stores in L3
    cout << L3 << endl;     //Prints L3 to the output screen

    cout << L3[5] << endl;  //Prints out 5th element in L3
    return 0;
}