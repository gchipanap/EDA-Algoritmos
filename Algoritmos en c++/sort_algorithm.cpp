void swap(int* a, int* b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

//bubble Sort
void bubbleSortCost(int* arr, int n, unsigned long long& sum)
{
	int asig = 0, comp = 0, create = 0, array = 0;
	int i, j;
	create = create + 400;
	bool swapped;
	create = create + 200;
	asig = asig + 8; 
	comp = comp + 2;
	for (i = 0; i < n-1; i++)
	{
	asig = asig + 8;
	comp = comp + 2; 
	swapped = false;
	asig = asig + 8;
	for (j = 0; j < n-i-1; j++)
	{
		asig = asig + 8;
		comp = comp + 2;
		if (*(arr+j) > *(arr+j+1))
	    {
	       swap(&arr[j], &arr[j+1]);
	       asig = asig + 24; 
	       swapped = true;
	       asig = asig + 8;
	    }
	}
	
	comp = comp + 2;
	if (swapped == false)
	    break;
	}
	sum = asig + comp + create;
}

void bubbleSort(int* arr, int n,unsigned long long& sum)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n-1; i++)
	{
	 swapped = false;
	 for (j = 0; j < n-i-1; j++)
	 {
	    if (*(arr+j) > *(arr+j+1))
	    {
	       swap(&arr[j], &arr[j+1]);
	       swapped = true;
	    }
	 }
	
	 if (swapped == false)
	    break;
	}
}

void bubbleSort(int* arr, int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n-1; i++)
	{
	 swapped = false;
	 for (j = 0; j < n-i-1; j++)
	 {
	    if (*(arr+j) > *(arr+j+1))
	    {
	       swap(&arr[j], &arr[j+1]);
	       swapped = true;
	    }
	 }
	
	 if (swapped == false)
	    break;
	}
}

//heap sort 
void heapify(int arr[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2; 
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);
 
  for (int i = n - 1; i > 0; i--) {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
  }
}

//insertion Sort
void insertionSort(int arr[], int n,unsigned long long& sum) 
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertionSortCost(int arr[], int n,unsigned long long& sum)
{ 
	int asig = 0 , comp = 0 , create = 0 , array = 0;
    int i, key, j;
    create = create + 600;
    asig = asig + 8;
	comp = comp + 2;
    for (i = 1; i < n; i++)
    {
		comp = comp + 2;
    	asig = asig + 8;
    	asig = asig + 8;
        key = arr[i];
        asig = asig + 8;
        j = i - 1;

        comp = comp + 4;
        while (j >= 0 && arr[j] > key)
        {
        	comp = comp + 2;
            arr[j + 1] = arr[j];
            asig = asig + 8;
            j = j - 1;
        }
        asig = asig + 8;
        arr[j + 1] = key;
    }
    sum =  asig + comp + create;
}


void insertionSort(int arr[], int n) 
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//Selection Sort
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
 
        swap(&arr[min_idx], &arr[i]);
    }
}

//Shell Sort
void shellSort(int arr[], int n)
{
  for (int gap = n/2; gap > 0; gap /= 2)
  {
      for (int i = gap; i < n; i += 1)
      {
          int temp = arr[i];
          int j;           
          for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
              arr[j] = arr[j - gap];
            
          arr[j] = temp;
      }
  }
}

//Merge Sort 
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[],int l,int r){
    if(l>=r)
	  {
      return;
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
void mergeSort(int arr[], int size)
{
	mergeSort(arr, 0, size-1);
}

//Quick Sort
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++) 
    { 
      if (arr[j] < pivot) 
      { 
          i++;
          swap(&arr[i], &arr[j]); 
      } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
  if (low < high) 
  { 
    int pi = partition(arr, low, high); 

    quickSort(arr, low, pi - 1); 
    quickSort(arr, pi + 1, high); 
  } 
}

void quickSort(int arr[], int size)
{
  quickSort(arr, 0, size-1); 
}

