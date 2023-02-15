//
// Created by john on 11/10/2021.
//

#ifndef PROJECT_4_SELECTIONSORT_H
#define PROJECT_4_SELECTIONSORT_H

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

template<typename Comparable>
//Print vector method for selection sort
void printVecS(const vector<Comparable> &v){
    for (int i = 0; i < v.size(); ++i){
        if (i != 0){
            cout << ", ";
        }
        cout << v[i];
    }
    cout << endl;
}

//Method to print out reads from the selection sort
void printReadS(int n){
    cout << n << endl;
}

template<typename Comparable>
void selectionSort(vector<Comparable> vec){
    //Establishing needed ints and comparable variables
    int swapIndex, i, minIndex;
    int numReads = 0;
    int numWrites = 0;
    Comparable temp;
    for (swapIndex = 0; swapIndex < vec.size(); ++swapIndex){
        //Loop through vector starting at swapIndex and keep track of min
        minIndex = swapIndex;
        for (i = swapIndex + 1; i < vec.size(); ++i){
            if (vec[i] < vec[minIndex]){
                minIndex = i;
            }
            //Ensuring the if statement reads are counted no matter what
            numReads += 2;
        }
        //Swap min value into swapIndex spot in vector
        temp = vec[swapIndex];
        numReads++;
        numWrites++;
        vec[swapIndex] = vec[minIndex];
        numReads++;
        numWrites++;
        vec[minIndex] = temp;
        numWrites++;
    }
    printReadS(numReads);
    printReadS(numWrites);
}

#endif //PROJECT_4_SELECTIONSORT_H
