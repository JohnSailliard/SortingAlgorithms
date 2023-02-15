//
// Created by john on 11/10/2021.
//

#ifndef PROJECT_4_QUICKSORTSTABLE_H
#define PROJECT_4_QUICKSORTSTABLE_H

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int numReadsQStable;
int numWritesQStable;

//Method to print out reads from the quick sort
void printReadSortedQ(int n){
    cout << n << endl;
}

template<typename Comparable>
void printVecQStable(const vector<Comparable> &v) {
    for (int i = 0; i < v.size(); ++i) {
        if (i != 0) {
            cout << ", ";
        }
        cout << v[i];
    }
    cout << endl;
}

template<typename Comparable>
void quickSortStableRec(vector<Comparable> &vec) {
    // Recursive base case
    if (vec.size() <= 1) {
        return;
    }
    // Choose a partition element
    Comparable partition = vec[0];
    numReadsQStable++;
    numWritesQStable++;
    vector<Comparable> smaller, equal, larger;
    // Loop through vec and populate smaller, equal, larger
    int i;
    for (i = 0; i < vec.size(); ++i) {
        if (vec[i] < partition) {
            smaller.push_back(vec[i]);
            numWritesQStable++;
        } else if (vec[i] == partition) {
            equal.push_back(vec[i]);
            numWritesQStable++;
            numReadsQStable++;
            numReadsQStable++;
        } else {
            larger.push_back(vec[i]);
            numWritesQStable++;
            numReadsQStable++;
            numReadsQStable++;
        }
        numReadsQStable++;
    }
    // Recursive calls
    quickSortStableRec(smaller);
    quickSortStableRec(larger);
    // Copy everything back into vec
    for (i = 0; i < vec.size(); ++i) {
        if (i < smaller.size()) {
            vec[i] = smaller[i];
            numWritesQStable++;
            numReadsQStable++;
        } else if (i < smaller.size() + equal.size()) {
            vec[i] = equal[i - smaller.size()];
            numWritesQStable++;
            numReadsQStable++;
        } else {
            vec[i] = larger[i - smaller.size() - equal.size()];
            numWritesQStable++;
            numReadsQStable++;
        }
    }
}

template<typename Comparable>
void quickSortStable(vector<Comparable> vec) {
    quickSortStableRec(vec);
    printReadSortedQ(numReadsQStable);
    printReadSortedQ(numWritesQStable);
}


#endif //PROJECT_4_QUICKSORTSTABLE_H
