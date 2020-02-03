
///////////////////////////////////////////////////////////////////////////////
//
// Author:           Alex Trampert
// Email:            alextrampert2000@gmail.com
// Label:            L01
// Title:            Lecture 01 - Array Based Stack
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       Overview of a class implementing an array based stack
//       with resizing capability based on quantity within stack.
//       Will multiply size by 1.75 if max quantity is reached, 
//       and will shrink size by 0.5 if top drops below 0.5 of size
//       AND size > 10.
//       (will not shrink if size is smaller than original quantity)
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>

using namespace std;

/**
 * ArrayStack
 *
 * Description:
 *      Array based stack with resizing capability
 *
 * Public Methods:
 *      ArrayStack()
 *      ArrayStack(int s)
 *      bool Empty()
 *      bool Full()
 *      int Peek()
 *      int Pop()
 *      void Print()
 *      bool Push(int x)
 *      void ContainerGrow()
 *      void ContainerShrink()
 *      bool Half()
 *      int ShowSize()
 *      int ShowMaxSize()
 *      int ShowResize()
 *      
 * Usage:
 *      ArrayStack stack;
 *      stack.Push(r);
 *      stack.Pop();
 *      stack.Print();
 *      temp = ShowSize();
 *      temp = ShowMaxSize();
 *      temp = ShowResize();
 *
 */
class ArrayStack {
private:
    int* A;            // pointer to array of int's
    int size;          // current max stack size
    int top;           // top of stack 
    int maxSize;       // maximum size reached by stack
    int resizeNum = 0; // number of times resized

public:
    /**
     * ArrayStack
     *
     * Description:
     *      Constructor no params
     *
     * Params:
     *     - None
     *
     * Returns:
     *     - NULL
     */
    ArrayStack() {
        size = maxSize = 10;
        A = new int[size];
        top = -1;
    }

    /**
     * ArrayStack
     *
     * Description:
     *      Constructor size param
     *
     * Params:
     *     - int size
     *
     * Returns:
     *     - NULL
     */
    ArrayStack(int s) {
        size = maxSize = s;
        A = new int[s];
        top = -1;
    }

    /**
     * Public bool: Empty
     *
     * Description:
     *      Stack empty?
     *
     * Params:
     *      NULL
     *
     * Returns:
     *      [bool] true = empty
     */
    bool Empty() {
        return (top <= -1);
    }

    /**
     * Public bool: Full
     *
     * Description:
     *      Stack full?
     *
     * Params:
     *      NULL
     *
     * Returns:
     *      [bool] true = full
     */
    bool Full() {
        return (top >= size - 1);
    }

    /**
     * Public int: Peek
     *
     * Description:
     *      Returns top value without altering the stack
     *
     * Params:
     *      NULL
     *
     * Returns:
     *      [int] top value if any
     */
    int Peek() {
        if (!Empty()) {
            return A[top];
        }

        return -99; // some sentinel value
                    // not a good solution
    }

    /**
     * Public int: Pop
     *
     * Description:
     *      Returns top value and removes it from stack
     *
     * Params:
     *      NULL
     *
     * Returns:
     *      [int] top value if any
     */
    int Pop() {
        if (!Empty()) {
            int temp;
            temp = A[top--];

            if (!Half() && (size > 10))
                ContainerShrink();

            return temp;
        }

        return -99; // some sentinel value
                    // not a good solution
    }

    /**
     * Public void: Print
     *
     * Description:
     *      Prints stack to standard out
     *
     * Params:
     *      NULL
     *
     * Returns:
     *      NULL
     */
    void Print() {
        for (int i = 0; i <= top; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    /**
     * Public bool: Push
     *
     * Description:
     *      Adds an item to top of stack
     *
     * Params:
     *      [int] : item to be added
     *
     * Returns:
     *      [bool] ; success = true
     */
    bool Push(int x) {
        if (Full()) {
            ContainerGrow();
        }
        if (!Full()) {
            A[++top] = x;
            return true;
        }

        return false;

    }

    /**
     * Public void: ContainerGrow
     *
     * Description:
     *      Resizes the container for the stack by multiplying its
     *      capacity by 1.75
     *
     * Params:
     *      NULL
     *
     * Returns:
     *      NULL
     */
    void ContainerGrow() {
        int newSize = size * 1.75;          // multiply size of original
        int* B = new int[newSize];          // allocate new memory

        for (int i = 0; i < size; i++) {    // copy values to new array
            B[i] = A[i];
        }

        delete[] A;                         // delete old array

        size = maxSize = newSize;           // save new size

        A = B;                              // reset array pointer

        resizeNum++;                        //adds to resize counter
    }

    /**
     * Public void: ContainerShrink
     *
     * Description:
     *      Resizes the container for the stack by shrinking its
     *      capacity by 0.5
     *
     * Params:
     *      NULL
     *
     * Returns:
     *      NULL
     */
    void ContainerShrink() {
        int newSize = size * 0.5;           // multiply size of original
        int* B = new int[newSize];          // allocate new memory

        for (int i = 0; i < newSize; i++) { // copy values to new array
            B[i] = A[i];
        }

        delete[] A;                         // delete old array

        size = newSize;                     // save new size

        A = B;                              // reset array pointer

        resizeNum++;                        //adds to resize counter
    }

    /**
     * Public bool: Half
     *
     * Description:
     *      Stack half full?
     *
     * Params:
     *      NULL
     *
     * Returns:
     *      [bool] true = half
     */
    bool Half() {
        return (top >= (size - 1) / 2);
    }

    /**
    * Public int: ShowSize
    *
    * Description:
    *      Returns current stack size
    *
    * Params:
    *      NULL
    *
    * Returns:
    *      [int] size
    */
    int ShowSize() {
        return size;
    }

    /**
   * Public int: ShowMaxSize
   *
   * Description:
   *      Returns max size stack reached 
   *
   * Params:
   *      NULL
   *
   * Returns:
   *      [int] maxSize
   */
    int ShowMaxSize() {
        return maxSize;
    }

    /**
   * Public int: ShowResize
   *
   * Description:
   *      Returns times resized 
   *
   * Params:
   *      NULL
   *
   * Returns:
   *      [int] resizeNum
   */
    int ShowResize() {
        return resizeNum;
    }
};

// MAIN DRIVER
// Simple Array Based Stack Usage:
int main() {
    ArrayStack stack;               //create array
    int r = 0;                      //int to hold values from file             
    int temp = 0;                   //int to hold stack data

    ifstream(infile);               //open input file
    infile.open("nums.dat");
    ofstream(outfile);              //open output file
    outfile.open("output.dat");
    
    while (!infile.eof()) {
        infile >> r;                //read in value

        if ((r % 2) == 0) {         //dictate if even
            if (!stack.Push(r)) {   //if even -> push
                cout << "Push failed" << endl;
            }
        }
        else                
            stack.Pop();            //if odd -> pop
    }

    //stack.Print();                //not printing hundreds of values

    //Neat output for program 
    outfile << "###################################"
            << "###################################\n";
    outfile << "Assignment 4 - Resizing the Stack\n"
            << "CMPS 3013\n"
            << "Alex Trampert\n\n";
    temp = stack.ShowMaxSize();
    outfile << "Max Stack Size : " << temp << endl;
    temp = stack.ShowSize();
    outfile << "End Stack Size : " << temp << endl;
    temp = stack.ShowResize();
    outfile << "Stack Resized  : " << temp << " times\n";
    outfile << "###################################"
            << "###################################";

    infile.close();                 //close input file
    outfile.close();                //close output file
}