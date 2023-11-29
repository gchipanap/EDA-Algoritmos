#ifndef _GENERATE
#define _GENERATE

#include <vector> 
#include <ctime>
#include <fstream>
#include <math.h>
#include <iostream>
#include "soth_algorithm.hpp"

void generateRandomNumbers(int* array, int  n);

void deleteArray(int* n, int size);
void copyArray(int* array1,int* array2,int* array3,int* array4,int* array5,int* array6,int* array7, int size);

double averageVector(std::vector<double> a);

double bubbleSortTime(int* array, int size);
double heapSortTime(int* array, int size);
double insertionSortTime(int* array, int size);
double selectionSortTime(int* array, int size);
double shellSortTime(int* array, int size);
double mergeSortTime(int* array, int size);
double quickSortTime(int* array, int size);

void intercalaVSmerge(int size, int n, std::vector<double>& timeBubble, std::vector<double>& timeHeap, std::vector<double>& timeInsertion, std::vector<double>& timeSelection, std::vector<double>& timeShell, std::vector<double>& timeMerge, std::vector<double>& timeQuick);

void sort_algorithms(std::ofstream& ofs);


#include "generate.cpp"
#endif  //_generate
