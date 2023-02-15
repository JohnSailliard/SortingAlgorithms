//
// Created by john on 11/10/2021.
//

#ifndef PROJECT_4_QUICKSORT_H
#define PROJECT_4_QUICKSORT_H

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int numReadsQ;
int numWritesQ;

template<typename Comparable>
void printVecQ(const vector<Comparable> &v){
    for (int i = 0; i < v.size(); ++i){
        if (i != 0){
            cout << ", ";
        }
        cout << v[i];
    }
    cout << endl;
}

//Method to print out reads from the quick sort
void printReadQ(int n){
    cout << n << endl;
}

template<typename Comparable>
void quickSortUnstableRec(vector<Comparable> &vec, int startIndex, int endIndex){
    if (endIndex <= startIndex){
        //There is only one element left. Nothing to do.
        return;
    }
    Comparable partition = vec[startIndex];
    numReadsQ++;
    numWritesQ++;
    Comparable temp;
    int i;
    int largerElementIndex = startIndex + 1;
    for (i = startIndex; i <= endIndex; ++i){
        if (vec[i] < partition){
            //Swap the element with the one at largerElementIndex to keep smaller elements grouped
            temp = vec[i];
            numReadsQ++;
            numWritesQ++;
            vec[i] = vec[largerElementIndex];
            numReadsQ++;
            numWritesQ++;
            vec[largerElementIndex] = temp;
            numWritesQ++;
            //Update largerElementIndex
            ++largerElementIndex;
        }
        //Ensuring numReads for the if statement is counted no matter what
        numReadsQ++;
    }
    vec[startIndex] = vec[largerElementIndex - 1];
    numReadsQ++;
    numWritesQ++;
    vec[largerElementIndex - 1] = partition;
    numWritesQ++;

    //Recursive call for less-than-partition side
    quickSortUnstableRec(vec, startIndex, largerElementIndex - 2);
    //Recursive call for greater-than-or-equal-to-partition side
    quickSortUnstableRec(vec, largerElementIndex, endIndex);
}

template<typename Comparable>
void quickSortUnstable(vector<Comparable> vec){
    quickSortUnstableRec(vec, 0, vec.size() - 1);
    printReadQ(numReadsQ);
    printReadQ(numWritesQ);
}

#endif //PROJECT_4_QUICKSORT_H
