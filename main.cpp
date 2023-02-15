#include <iostream>
#include "RottenTomatoes.h"
#include "bubbleSort.h"
#include <ctime>
#include "heapSort.h"
#include "selectionSort.h"
#include "quickSort.h"
#include "quickSortStable.h"
#include <vector>

using namespace std;

int main() {
    //Creating base Vector
    vector<Movie> movie;
    getDataFromFile("../rotten_tomatoes_movies2.csv", movie);

    //Vector of 100 Objects
    vector<Movie> movie100;
    for (int i = 0; i < 100; i++) {
        movie100.push_back(movie[i]);
    }

    //Print out reads/writes for 100
    cout << "Bubble for 100" << endl;
    bubbleSort(movie100);
    cout << "Selection for 100" << endl;
    selectionSort(movie100);
    cout << "Quick for 100" << endl;
    quickSortUnstable(movie100);
    cout << "Heap for 100" << endl;
    heapSort(movie100);
    cout << "Quick stable for 100" << endl;
    quickSortStable(movie100);

    //Vector of 200 objects
    vector<Movie> movie200;
    for (int i = 0; i < 200; i++) {
        movie200.push_back(movie[i]);
    }
    //Print out reads/writes for 200
    cout << "Bubble for 200" << endl;
    bubbleSort(movie200);
    cout << "Selection for 200" << endl;
    selectionSort(movie200);
    cout << "Quick for 200" << endl;
    quickSortUnstable(movie200);
    cout << "Heap for 200" << endl;
    heapSort(movie200);
    cout << "Quick stable for 200" << endl;
    quickSortStable(movie200);

    //Vector of 300 objects
    vector<Movie> movie300;
    for (int i = 0; i < 300; i++) {
        movie300.push_back(movie[i]);
    }
    //Print out reads/writes for 300
    cout << "Bubble for 300" << endl;
    bubbleSort(movie300);
    cout << "Selection for 300" << endl;
    selectionSort(movie300);
    cout << "Quick for 300" << endl;
    quickSortUnstable(movie300);
    cout << "Heap for 300" << endl;
    heapSort(movie300);
    cout << "Quick stable for 300" << endl;
    quickSortStable(movie300);

    //Vector of 400 objects
    vector<Movie> movie400;
    for (int i = 0; i < 400; i++) {
        movie400.push_back(movie[i]);
    }
    //Print out reads/writes for 400
    cout << "Bubble for 400" << endl;
    bubbleSort(movie400);
    cout << "Selection for 400" << endl;
    selectionSort(movie400);
    cout << "Quick for 400" << endl;
    quickSortUnstable(movie400);
    cout << "Heap for 400" << endl;
    heapSort(movie400);
    cout << "Quick stable for 400" << endl;
    quickSortStable(movie400);

    //Vector of 500 objects
    vector<Movie> movie500;
    for (int i = 0; i < 500; i++) {
        movie500.push_back(movie[i]);
    }
    //Print out reads/writes for 500
    cout << "Bubble for 500" << endl;
    bubbleSort(movie500);
    cout << "Selection for 500" << endl;
    selectionSort(movie500);
    cout << "Quick for 500" << endl;
    quickSortUnstable(movie500);
    cout << "Heap for 500" << endl;
    heapSort(movie500);
    cout << "Quick stable for 500" << endl;
    quickSortStable(movie500);

    //Vector of 600 objects
    vector<Movie> movie600;
    for (int i = 0; i < 600; i++) {
        movie600.push_back(movie[i]);
    }
    //Print out reads/writes for 600
    cout << "Bubble for 600" << endl;
    bubbleSort(movie600);
    cout << "Selection for 600" << endl;
    selectionSort(movie600);
    cout << "Quick for 600" << endl;
    quickSortUnstable(movie600);
    cout << "Heap for 600" << endl;
    heapSort(movie600);
    cout << "Quick stable for 600" << endl;
    quickSortStable(movie600);

    //Vector of 700 objects
    vector<Movie> movie700;
    for (int i = 0; i < 700; i++) {
        movie700.push_back(movie[i]);
    }
    //Print out reads/writes for 700
    cout << "Bubble for 700" << endl;
    bubbleSort(movie700);
    cout << "Selection for 700" << endl;
    selectionSort(movie700);
    cout << "Quick for 700" << endl;
    quickSortUnstable(movie700);
    cout << "Heap for 700" << endl;
    heapSort(movie700);
    cout << "Quick stable for 700" << endl;
    quickSortStable(movie700);

    //Vector of 800 objects
    vector<Movie> movie800;
    for (int i = 0; i < 800; i++) {
        movie800.push_back(movie[i]);
    }
    //Print out reads/writes for 800
    cout << "Bubble for 800" << endl;
    bubbleSort(movie800);
    cout << "Selection for 800" << endl;
    selectionSort(movie800);
    cout << "Quick for 800" << endl;
    quickSortUnstable(movie800);
    cout << "Heap for 800" << endl;
    heapSort(movie800);
    cout << "Quick stable for 800" << endl;
    quickSortStable(movie800);

    //Vector of 900 objects
    vector<Movie> movie900;
    for (int i = 0; i < 900; i++) {
        movie900.push_back(movie[i]);
    }
    //Print out reads/writes for 900
    cout << "Bubble for 900" << endl;
    bubbleSort(movie900);
    cout << "Selection for 900" << endl;
    selectionSort(movie900);
    cout << "Quick for 900" << endl;
    quickSortUnstable(movie900);
    cout << "Heap for 900" << endl;
    heapSort(movie900);
    cout << "Quick stable for 900" << endl;
    quickSortStable(movie900);

    //Vector of 1000 objects
    vector<Movie> movie1000;
    for (int i = 0; i < 1000; i++) {
        movie1000.push_back(movie[i]);
    }
    //Print out reads/writes for 1000
    cout << "Bubble for 1000" << endl;
    bubbleSort(movie1000);
    cout << "Selection for 1000" << endl;
    selectionSort(movie1000);
    cout << "Quick for 1000" << endl;
    quickSortUnstable(movie1000);
    cout << "Heap for 1000" << endl;
    heapSort(movie1000);
    cout << "Quick stable for 1000" << endl;
    quickSortStable(movie1000);

    return 0;
}