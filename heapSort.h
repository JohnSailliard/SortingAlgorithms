//
// Created by john on 11/10/2021.
//

#ifndef PROJECT_4_HEAPSORT_H
#define PROJECT_4_HEAPSORT_H

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int numReadsHeap;
int numWritesHeap;

template<typename Comparable>
//Print vec method for heap sort
void printVecH(const vector<Comparable> &v){
    for (int i = 0; i < v.size(); ++i){
        if (i != 0){
            cout << ", ";
        }
        cout << v[i];
    }
    cout << endl;
}

//Helper function for heap sort
inline int leftChild(int i){
    return 2 * i + 1;
}

//Method to print out reads from the heap sort
void printReadH(int n){
    cout << n << endl;
}

//Helper function for heap sort
template <typename Comparable>
//i is the index of the value being percolated down
//n is the number of items in the heap
void percolateDown(vector<Comparable> &items, int i, int n, int child, Comparable tmp){
    for(tmp = items[i]; leftChild(i) < n; i = child){
        numReadsHeap++;
        numWritesHeap++;
        child = leftChild(i);
        //Choose the child with the larger value
        if (child != n - 1 && items[child] < items[child + 1]){
            ++child;
        }
        numReadsHeap += 2;
        //If the parent is less than the child, swap them
        if (tmp < items[child]){
            items[i] = items[child];
            numReadsHeap++;
            numWritesHeap++;
        } else {
            //Parent is >= both children. nothing more to do.
            break;
        }
        numReadsHeap++;
    }
    items[i] = tmp;
    numWritesHeap++;
}

template <typename Comparable>
vector<Comparable> heapSort(vector<Comparable> items){
    int i, j, child;
    numReadsHeap = 0;
    numWritesHeap = 0;
    Comparable temp, tmp;
    //Build the heap (with max value at root)
    for (i = items.size() / 2 - 1; i >= 0; --i){
        percolateDown(items, i, items.size(), child, tmp);
    }
    //Keep deleting the max
    for (j = items.size() - 1; j > 0; --j){
        //Swap the maximum out
        temp = items[0];
        numReadsHeap++;
        numWritesHeap++;
        items[0] = items[j];
        numReadsHeap++;
        numWritesHeap++;
        items[j] = temp;
        numWritesHeap++;

        //Make it into a heap again
        percolateDown(items, 0, j, child, tmp);
    }
    printReadH(numReadsHeap);
    printReadH(numWritesHeap);
    return items;
}

#endif //PROJECT_4_HEAPSORT_H