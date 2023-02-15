//
// Created by john on 11/10/2021.
//

#ifndef PROJECT_4_BUBBLESORT_H
#define PROJECT_4_BUBBLESORT_H

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

template<typename Comparable>
//Print vector method for bubble sort
void printVecB(const vector<Comparable> &v){
    for (int i = 0; i < v.size(); ++i){
        if (i != 0){
            cout << ", ";
        }
        cout << v[i];
    }
    cout << endl;
}

//Method to print out reads from the bubble sort
void printReadB(int n){
    cout << n << endl;
}

template<typename Comparable>
void bubbleSort(vector<Comparable> vec){
    //Needed boolean and int size of vec
    bool haveSwapped = true;
    int maxIndex = vec.size();
    int numReads = 0;
    int numWrites = 0;
    //Loop while still swapping
    while (haveSwapped){
        haveSwapped = false;
        for (int i = 0; i + 1 < maxIndex; ++i){
            //Compare items at indices i and i+1 and swap if necessary
            if (vec[i] > vec[i + 1]){
                Comparable temp = vec[i];
                numReads ++;
                numWrites ++;
                vec[i] = vec[i + 1];
                numReads ++;
                numWrites ++;
                vec[i + 1] = temp;
                numWrites ++;
                //Update haveSwapped
                haveSwapped = true;
            }
            //Ensuring the if statement reads are counted even if not evaluated to true
            numReads += 2;
        }
        //Update maxIndex
        --maxIndex;
    }
    //Print out the amount of reads
    cout << "Reads - ";
    printReadB(numReads);
    cout << "Writes - ";
    printReadB(numWrites);
}

#endif //PROJECT_4_BUBBLESORT_H
