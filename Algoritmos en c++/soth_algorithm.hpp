#ifndef SORT_ALGORITHM
#define SORT_ALGORITHM

#include <bits/stdc++.h>

void swap(int *a, int *b);

//1 Bubble sort 
void bubbleSort(int* arr, int n,unsigned long long& num);
void bubbleSort(int* arr, int n);
void bubbleSortCost(int* arr, int n, unsigned long long& sum);

//2 Heap Sort
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

//3 Insertion Sort 
void insertionSort(int arr[], int n,unsigned long long& num);
void insertionSort(int arr[], int n);
void insertionSortCost(int arr[], int n, unsigned long long& sum);

//4 Selection Sort 
void selectionSort(int arr[], int n);

//5 Shell Sort 
void shellSort(int arr[], int n);

//6 Merge Sort
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[],int l,int r);
void mergeSort(int arr[], int size);

//7 Quick Sort 
int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void quickSort(int arr[], int size);

#include "sort_algorithm.cpp"
#endif //SORT_ALGORITHM
