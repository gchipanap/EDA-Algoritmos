#include "generate.hpp"

void generateRandomNumbers(int* array, int  n)
{
	srand(time(NULL));
	for(int i = 0; i < n ; i++)
	{
		*(array+i) = -n+rand()%(n+n);
	}
}

void deleteArray(int* n, int size)   
{
	delete [] n;
}

double averageVector(std::vector<double> a)  
{
	double sum;
	for(const auto &i : a)
		sum = sum + i;
	sum = sum / a.size();
	return sum;
}

void copyArray(int* array1,int* array2,int* array3,int* array4,int* array5,int* array6,int* array7, int size)
{
	for(int i = 0; i < size; i++)
	{
		array2[i] = array1[i];
    array3[i] = array1[i];
    array4[i] = array1[i];
    array5[i] = array1[i];
    array6[i] = array1[i];
    array7[i] = array1[i];
	}
}

double bubbleSortTime(int* array, int size)
{
	unsigned t0, t1;
	t0=clock();
	bubbleSort(array, size);
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	return time;
}
double heapSortTime(int* array, int size)
{
	unsigned t0, t1;
	t0=clock();
	heapSort(array, size);
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	return time;
}
double insertionSortTime(int* array, int size)
{
	unsigned t0, t1;
	t0=clock();
	insertionSort(array, size);
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	return time;
}
double selectionSortTime(int* array, int size)
{
	unsigned t0, t1;
	t0=clock();
	selectionSort(array, size);
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	return time;
}
double shellSortTime(int* array, int size)
{
	unsigned t0, t1;
	t0=clock();
	shellSort(array, size);
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	return time;
}
double mergeSortTime(int* array, int size)
{
	unsigned t0, t1;
	t0=clock();
	mergeSort(array, size);
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	return time;
}
double quickSortTime(int* array, int size)
{
	unsigned t0, t1;
	t0=clock();
	quickSort(array, size);
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	return time;
}

void sorts_algorithm(int size, int n, std::vector<double>& timeBubble, std::vector<double>& timeHeap, std::vector<double>& timeInsertion, std::vector<double>& timeSelection, std::vector<double>& timeShell, std::vector<double>& timeMerge, std::vector<double>& timeQuick)
{
	double time1, time2, time3, time4, time5, time6, time7;
	
	for(int i = 0; i < n ; i++)
	{
		int* array1 = new int[size];
		int* array2 = new int[size];
    int* array3 = new int[size];
    int* array4 = new int[size];
    int* array5 = new int[size];
    int* array6 = new int[size];
    int* array7 = new int[size];

		generateRandomNumbers(array1, size); 
		copyArray(array1, array2, array3, array4, array5, array6, array7, size);

		time1 = bubbleSortTime(array1, size);
		time2 = heapSortTime(array2, size);
    time3 = insertionSortTime(array3, size);
    time4 = selectionSortTime(array4, size);
    time5 = shellSortTime(array5, size);
    time6 = mergeSortTime(array6, size);
    time7 = quickSortTime(array7, size);

		timeBubble.push_back(time1);
    timeHeap.push_back(time2);
    timeInsertion.push_back(time3);
    timeSelection.push_back(time4);
    timeShell.push_back(time5);
    timeMerge.push_back(time6);
		timeQuick.push_back(time7);

		delete [] array1;
		delete [] array2;
    delete [] array3;
    delete [] array4;
    delete [] array5;
    delete [] array6;
    delete [] array7;
	}
}

void sort_algorithms(std::ofstream& ofs)
{
	std::vector<double> intercala;  //Guarda los tiempos que demora en ordenar n vectores con intercala
	std::vector<double> merge;  //merge

  std::vector<double> timesBubble;
  std::vector<double> timesHeap;
  std::vector<double> timesInsertion;
  std::vector<double> timesSelection;
  std::vector<double> timesShell;
  std::vector<double> timesMerge;
  std::vector<double> timesQuick;

  double timeBubble;
  double timeHeap;
  double timeInsertion;
  double timeSelection;
  double timeShell;
  double timeMerge;
  double timeQuick;

	double intercalaTime;
	double mergeTime;
	for(int i = 0; i <= 6; i++)
	{
		std::cout<<"Generando arreglos de tamanio: " << pow(10,i) << std::endl;
		sorts_algorithm(pow(10,i),20,
    timesBubble,
    timesHeap,
    timesInsertion,
    timesSelection,
    timesShell,
    timesMerge,
    timesQuick);

    timeBubble = averageVector(timesBubble);
    timeHeap = averageVector(timesHeap);
    timeInsertion = averageVector(timesInsertion);
    timeSelection = averageVector(timesSelection);
    timeShell = averageVector(timesShell);
    timeMerge = averageVector(timesMerge);
    timeQuick = averageVector(timesQuick);

		std::cout<< pow(10,i) << " -> " 
    <<"Buble Sort" << timeBubble << "\n" 
    <<"Heap Sort" << timeHeap <<"\n"
    <<"Insertion Sort" << timeInsertion <<"\n"
    <<"Selection Sort" << timeSelection <<"\n"
    <<"Shell Sort" << timeShell <<"\n"
    <<"Merge Sort" << timeMerge <<"\n"
    <<"Quick Sort" << timeQuick<<"\n"
    << std::endl;

		ofs<< pow(10,i) << "\t" 
    << timeBubble << "\t" 
    << timeHeap << "\n"  
    << timeInsertion << "\n"
    << timeSelection << "\n"
    << timeShell << "\n"
    << timeMerge << "\n"
    << timeQuick << "\n";

		timesBubble.clear();
		timesHeap.clear();
    timesInsertion.clear();
    timesSelection.clear();
    timesShell.clear();
    timesMerge.clear();
    timesQuick.clear();
	}
}
