///////////////////////////////////////////////////////////////////////////////
//
// Author:           Alex Trampert
// Email:            alextrampert2000@gmail.com
// Label:            H02
// Title:            Homework 02 - Heapify
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//      Heap class that sorts on insert and and can properly
//		remove values and sort and array passed into it. Basically
//		has all practical use and functions of a heap.
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

/**
 * Class Heap
 * 
 * @methods:
 *      constructors:
 *          Heap        : default constructor
 *          Heap(int)   : overload constructor with heap size
 *      private:
 *          BubbleUp    : puts a value into its correct spot going up
 *          Left        : calculates left child index
 *          OnHeap      : checks if index is ont he heap
 *          Parent      : calculates parent index
 *          Right       : calculates right child index
 *          Swap        : swaps 2 values in the heap
 *          Heapify     : sorts an array passed in to heap order
 *          SinkDown    : puts a value into its correct spot going down
 *          PickChild   : picks which child will be swapped for SinkDown
 *      public:
 *          Insert      : adds a value to the heap and places in proper spot
 *          Print       : prints the heap out
 *          Remove      : removes the first value in the heap and reshuffles
 */
class Heap {
private:
    int size; // size of the array
    int *H;   // array pointer
    int end;  // 1 past last item in array

    /**
   * BubbleUp
   * 
   * @description: 
   *    This puts one value into its proper
   *    place in the heap.
   * 
   * @param  {int} index : index to start bubbling at
   * @return             : void
   */
    void BubbleUp(int index) {
        // check parent is not of beginning of array
        if (Parent(index) >= 1) {
            // index is on array and value is less than parent
            while (index > 1 && H[index] < H[Parent(index)]) {
                // do a swap
                Swap(index, Parent(index));

                // update index to values new position
                index = Parent(index);
            }
        }
    }

    /**
     * Left
     * @description:
     *      Calculates index of left child.
     * 
     * @param  {int} index : index of parent
     * @return {int}       : index of left child
     */
    int Left(int index) {
        return 2 * index;
    }

    /**
     * OnHeap
     * @description:
     *      Checks if an index is on the array (past the end).
     * 
     * @param  {int} index : index to check
     * @return {bool}      : 0 = off heap / 1 = on heap
     */
    bool OnHeap(int index) {
        return index < end;
    }

    /**
     * Parent
     * @description:
     *      Calculates parent of a given index.
     * 
     * @param  {int} index : index to check
     * @return {int}       : parent index
     */
    int Parent(int index) {
        return index / 2;
    }

    /**
     * Right
     * @description:
     *      Calculates index of right child.
     * 
     * @param  {int} index : index of parent
     * @return {int}       : index of right child
     */
    int Right(int index) {
        return 2 * index + 1;
    }

    /**
     * Swap
     * 
     * @description: 
     *      Swaps to values in the heap
     * 
     * @param  {int} i  : index in array
     * @param  {int} j  : index in array
     * @return          : void
     */
    void Swap(int i, int j) {
        int temp = H[i];
        H[i] = H[j];
        H[j] = temp;
    }

    /**
      * Heapify
      * @description:
      *      Sorts an array passed in to heap order
      *
     * @param  {int*} A :  array pointer with unsorted values to make into a heap
     * @param  {int} size :  size of new heap
     */
    //Hard to test being in private
    void Heapify(int * A, int size) {
        Heap H(size);
        
        //This assumes that array A follows general heap rules
        for (int i = 1; i < size - 1; i++)
            //Insert function automatically sorts
            H.Insert(A[i]);

        for (int i = 1; i < size - 1; i++)
            A[i] = H.GetVal(i);
    }

    /**
     * SinkDown
     * @description:
     *      Places one heap item into its proper place in the heap
     *      by bubbling it down to it proper location.
     * 
     * @param  {int} index  : index to start from in the array
     * @return              : void 
     */
    void SinkDown(int index) {
        int swapChild;
       
         // index is on array and has at least 1 child
         while (Left(index) < end && Right(index) < end) {
             // check children are in the array
             swapChild = PickChild(index);
             if (H[index] > H[swapChild]) {
                 // do a swap
                 Swap(index, swapChild);
                 // update index to values new position
                 index = swapChild;

             }
             else
                 return;
         }
    }

    /**
     * PickChild
     * @description:
     *      If one child exists, return it.
     *      Otherwise, return the smaller of the two.
     * 
     * @param  {int} index  : index of parent in the array
     * @return              : index to child 
     */
    int PickChild(int index) {
        if (OnHeap(Right(index)))
            if (H[Right(index)] > H[Left(index)])
                return Left(index);
            else
                return Right(index);
        else
            return Left(index);
    }

public:
    /**
   * Heap constructor
   */
    Heap() {
        size = 100;
        H = new int[size];
        end = 1;
    }

    /**
   * Heap constructor
   * 
   * @param  {int} s : heap size 
   */
    Heap(int s) {
        size = s;
        H = new int[s];
        end = 1;
    }

    /**
   * Insert
   * 
   * @description:
   *        Add a value to the heap.
   * 
   * @param  {int} x : value to Insert
   * @return         : void
   */
    void Insert(int x) {
        H[end] = x;
        BubbleUp(end);
        end++;
    }

    /**
     * For test our heap !!!  
     */
    void Print() {
        for (int i = 1; i <= end - 1; i++) {
            cout << H[i];
            if (i < end - 1) {
                cout << "->";
            }
        }
    }

    /**
     * Remove
     * @description:
     *      Removes item from top of heap
     * 
     * @return {int}  : top of heap
     */
    int Remove() {
        int index = 1;
        int temp = H[1];
        H[1] = H[end - 1];
        --end;

        for(int i = 1; i < end; i++)
            SinkDown(i);

        return temp;
    }

    /**
     * GetVal
     * @description:
     *      Gets value of position in heap
     *
     * @return {int}  : value in position of heap
     */
    int GetVal(int index) {
        return H[index];
    }
};

int main() {
    //Create heap
    Heap H;
    int temp;

    //Insert 2 test values
    H.Insert(17);
    H.Insert(11);

    //Insert multiple test values
    for (int i = 1; i <= 10; i++) {
        H.Insert(i);
    }

    //Test order
    H.Print();
    cout << '\n';

    //Test remove
    temp = H.Remove();
    //Test order
    H.Print();    
}