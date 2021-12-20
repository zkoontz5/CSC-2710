#include<iostream>
#include<fstream>
#include<cstdlib>
#include<array>
// #include<ctime>
#include<sys/time.h>
#include<sstream>

using namespace std;

void swap_ours(int arr[], int x, int p);
void selectionSort(int arr[], int n, int &swaps, int &compares);
void merge(int arr[], int start, int mid, int end);
void mergeSort(int arr[], int start, int end, int &compares);

//Heap Sort functions from GeeksForGeeks.com 
void heapify(int arr[], int heapSize, int i, int &compares);
void heapSort(int arr[], int heapSize, int &compares);
void bubbleSort(int arr[], int arraySize, int &compares);
int* arrayGenerator(int arr[], int n);

void exchangeSort(int arr[], int z, int &swaps, int &compares);

void insertionSort(int arr[], int n, int &compares);

void copy_ours(int arrA[], const int arrB[], int z);

int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high, int &compares);

int main()
{
    int arraySize = 0, heapSize, n;
    float runtime1, runtime2, runtime3, runtime4, runtime5, runtime6, runtime7, runtime8, runtime9, runtime10, runtime11, runtime12, runtime13, runtime14, runtime15, runtime16, runtime17, runtime18, runtime19, runtime20, runtime21, runtime22, runtime23, runtime24, runtime25, runtime26, runtime27, runtime28, runtime29, runtime30, runtime31, runtime32, runtime33, runtime34, runtime35;
    struct timeval tstart, tend;
    int size;
    cout<<"Enter the size of the data set: ";
    cin>>size;
    cout<<endl;

    int randomArray[size], fewUnique[size], reversedSorted[size], partiallySorted[1000], inFileArray[size];

    //Random Array Generator
    srand(time(0));

    for (int i = 0; i < size; i++)
    {
        int x = rand() % 1000;
        randomArray[i] = x;
        arraySize++;
    }
    
    //Reverse Sorted Array
    int i = size;

    for (int k = 0; k < size; k++)
    {
      reversedSorted[k] = i;
      i--;
    }

    //Partially Sorted Array
    ifstream inFile, inFile2;
    inFile.open("partiallysorted.txt");

    for (int j = 0; j < size; j++)
    {
        inFile >> partiallySorted[j];
    }
    inFile.close();

    //Dataset inFile
    int l = 0;
    char cNum[1000];

    inFile2.open("data.txt", ifstream::in);

    if (inFile2.is_open())
    {
      while (inFile2.good())
      {
        inFile2.getline(cNum, 256, ',');
        inFileArray[l] = atoi(cNum);
        l++;
      }
      inFile2.close();
    }

    //Array Size Variables for Functions
    heapSize = arraySize;
    n = arraySize;

    //Few Unique Array
    int* ptr = arrayGenerator(fewUnique, n);

    //Make copies of randomArray to pass same array to functions
    int swaps = 0;
    int compares = 0;
    int exgList[n], exgFew[n], exgReversed[n], exgPartially[n], exgInFile[n];
  
    copy_ours(exgList, randomArray, n);
    copy_ours(exgFew, fewUnique, n);
    copy_ours(exgReversed, reversedSorted, n);
    copy_ours(exgPartially, partiallySorted, n);
    copy_ours(exgInFile, inFileArray, n);

    //Exchange Sort: Random
    gettimeofday(&tstart, NULL);
    exchangeSort(exgList, n, swaps, compares);
    gettimeofday(&tend, NULL);
    runtime1 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Exchange Sort (Random) Time: " << runtime1 << endl;
    cout << "-Exchange Sort (Random) Counts: " << compares << endl;
    cout << "-Exchange Sort (Random) Swaps: " << swaps << endl;
    compares = 0;
    swaps = 0;

    //Exchange Sort: Few Unique
    gettimeofday(&tstart, NULL);
    exchangeSort(exgFew, n, swaps, compares);
    gettimeofday(&tend, NULL);
    runtime8 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Exchange Sort (Few Unique) Time: " << runtime8 << endl;
    cout << "-Exchange Sort (Few Unique) Counts: " << compares << endl;
    cout << "-Exchange Sort (Few Unique) Swaps: " << swaps << endl;
    compares = 0;
    swaps = 0;

    //Exchange Sort: Reversed Sorted
    gettimeofday(&tstart, NULL);
    exchangeSort(exgReversed, n, swaps, compares);
    gettimeofday(&tend, NULL);
    runtime15 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Exchange Sort (Reversed Sorted) Time: " << runtime15 << endl;
    cout << "-Exchange Sort (Reversed Sorted) Counts: " << compares << endl;
    cout << "-Exchange Sort (Reversed Sorted) Swaps: " << swaps << endl;
    compares = 0;
    swaps = 0;

    //Exchange Sort: Partially Sorted
    gettimeofday(&tstart, NULL);
    exchangeSort(exgPartially, n, swaps, compares);
    gettimeofday(&tend, NULL);
    runtime22 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Exchange Sort (Partially Sorted) Time: " << runtime22 << endl;
    cout << "-Exchange Sort (Partially Sorted) Counts: " << compares << endl;
    cout << "-Exchange Sort (Partially Sorted) Swaps: " << swaps << endl<<endl;
    compares = 0;
    swaps = 0;

    //Exchange Sort: Dataset
    gettimeofday(&tstart, NULL);
    exchangeSort(exgInFile, n, swaps, compares);
    gettimeofday(&tend, NULL);
    runtime29 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Exchange Sort (Dataset) Time: " << runtime29 << endl;
    cout << "-Exchange Sort (Dataset) Counts: " << compares << endl;
    cout << "-Exchange Sort (Dataset) Swaps: " << swaps << endl<<endl;
    compares = 0;
    swaps = 0;

    //Insertion Sort
    int insList[n], insInFile[n];
    copy_ours(insList, randomArray, n);
    copy_ours(insInFile, inFileArray, n);

    //Insertion Sort: Random
    gettimeofday(&tstart, NULL);
    insertionSort(insList, n, compares);
    gettimeofday(&tend, NULL);
    runtime2 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Insertion Sort (Random) Time: " << runtime2 << endl;
    cout << "-Insertion Sort (Random) Counts: " << compares << endl;
    compares = 0;

    //Insertion Sort: Few Unique
    gettimeofday(&tstart, NULL);
    insertionSort(ptr, n, compares);
    gettimeofday(&tend, NULL);
    runtime9 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Insertion Sort (Few Unique) Time: " << runtime9 << endl;
    cout << "-Insertion Sort (Few Unique) Counts: " << compares << endl;
    compares = 0;

    //Insertion Sort: Reversed Sorted
    gettimeofday(&tstart, NULL);
    insertionSort(reversedSorted, n, compares);
    gettimeofday(&tend, NULL);
    runtime16 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Insertion Sort (Reversed Sorted) Time: " << runtime16 << endl;
    cout << "-Insertion Sort (Reversed Sorted) Counts: " << compares << endl;
    compares = 0;

    //Insertion Sort: Partially Sorted
    gettimeofday(&tstart, NULL);
    insertionSort(partiallySorted, n, compares);
    gettimeofday(&tend, NULL);
    runtime23 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Insertion Sort (Partially Sorted) Time: " << runtime23 << endl;
    cout << "-Insertion Sort (Partially Sorted) Counts: " << compares << endl<<endl;
    compares = 0;

    //Insertion Sort: Dataset
    gettimeofday(&tstart, NULL);
    insertionSort(insInFile, n, compares);
    gettimeofday(&tend, NULL);
    runtime30 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Insertion Sort (Dataset) Time: " << runtime30 << endl;
    cout << "-Insertion Sort (Dataset) Counts: " << compares << endl<<endl;
    compares = 0;

    //Quicksort
    int listOints[n], listInFile[n];
    copy_ours(listOints, randomArray, n);
    copy_ours(listInFile, inFileArray, n);

    //Quicksort: Random
    gettimeofday(&tstart, NULL);
    quickSort(randomArray,0, n-1, compares);
    gettimeofday(&tend, NULL);
    runtime3 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Quicksort (Random) Time: " << runtime3 << endl;
    cout << "-Quicksort (Random) Counts: " << compares << endl;
    compares = 0;

    //Quicksort: Few Unique
    gettimeofday(&tstart, NULL);
    quickSort(ptr,0, n-1, compares);
    gettimeofday(&tend, NULL);
    runtime10 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Quicksort (Few Unique) Time: " << runtime10 << endl;
    cout << "-Quicksort (Few Unique) Counts: " << compares << endl;
    compares = 0;

    //Quicksort: Reversed Sorted
    gettimeofday(&tstart, NULL);
    quickSort(reversedSorted,0, n-1, compares);
    gettimeofday(&tend, NULL);
    runtime17 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Quicksort (Reversed Sorted) Time: " << runtime17 << endl;
    cout << "-Quicksort (Reversed Sorted) Counts: " << compares << endl;
    compares = 0;

    //Quicksort: Partially Sorted
    gettimeofday(&tstart, NULL);
    quickSort(partiallySorted,0, n-1, compares);
    gettimeofday(&tend, NULL);
    runtime24 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Quicksort (Partially Sorted) Time: " << runtime24 << endl;
    cout << "-Quicksort (Partially Sorted) Counts: " << compares << endl<<endl;
    compares = 0;

    //Quicksort: Dataset
    gettimeofday(&tstart, NULL);
    quickSort(listInFile,0, n-1, compares);
    gettimeofday(&tend, NULL);
    runtime31 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Quicksort (Dataset) Time: " << runtime31 << endl;
    cout << "-Quicksort (Dataset) Counts: " << compares << endl<<endl;
    compares = 0;
    
    
    //Bubble Sort
    int bubbleList[n], bubbleInFile[n];
    copy_ours(bubbleList, randomArray, n);
    copy_ours(bubbleInFile, inFileArray, n);

    //Bubble Sort: Random
    gettimeofday(&tstart, NULL);
    bubbleSort(bubbleList,n,compares);
    gettimeofday(&tend, NULL);
    runtime4 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Bubble Sort (Random) Time: " << runtime4 << endl;
    cout << "-Bubble Sort (Random) Counts: " << compares << endl;
    compares = 0;

    //Bubble Sort: Few Unique
    gettimeofday(&tstart, NULL);
    bubbleSort(ptr,n,compares);
    gettimeofday(&tend, NULL);
    runtime11 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Bubble Sort (Few Unique) Time: " << runtime11 << endl;
    cout << "-Bubble Sort (Few Unique) Counts: " << compares << endl;
    compares = 0;

    //Bubble Sort: Reversed Sorted
    gettimeofday(&tstart, NULL);
    bubbleSort(reversedSorted,n,compares);
    gettimeofday(&tend, NULL);
    runtime18 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Bubble Sort (Reversed Sorted) Time: " << runtime18 << endl;
    cout << "-Bubble Sort (Reversed Sorted) Counts: " << compares << endl;
    compares = 0;

    //Bubble Sort: Partially Sorted
    gettimeofday(&tstart, NULL);
    bubbleSort(partiallySorted,n,compares);
    gettimeofday(&tend, NULL);
    runtime25 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Bubble Sort (Partially Sorted) Time: " << runtime25 << endl;
    cout << "-Bubble Sort (Partially Sorted) Counts: " << compares << endl<<endl;
    compares = 0;

    //Bubble Sort: Dataset
    gettimeofday(&tstart, NULL);
    bubbleSort(bubbleInFile,n,compares);
    gettimeofday(&tend, NULL);
    runtime32 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Bubble Sort (Dataset) Time: " << runtime32 << endl;
    cout << "-Bubble Sort (Dataset) Counts: " << compares << endl<<endl;
    compares = 0;

    //Heap Sort
    int heapList[n], heapInFile[n];
    copy_ours(heapList, randomArray, n);
    copy_ours(heapInFile, inFileArray, n);

    //Heap Sort: Random
    gettimeofday(&tstart, NULL);
    heapSort(heapList,n, compares);
    gettimeofday(&tend, NULL);
    runtime5 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Heap Sort (Random) Time: " << runtime5 << endl;
    cout << "-Heap Sort (Random) Counts: " << compares << endl;
    compares = 0;

    //Heap Sort: Few Unique
    gettimeofday(&tstart, NULL);
    heapSort(ptr,n, compares);
    gettimeofday(&tend, NULL);
    runtime12 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Heap Sort (Few Unique) Time: " << runtime12 << endl;
    cout << "-Heap Sort (Few Unique) Counts: " << compares << endl;
    compares = 0;

    //Heap Sort: Reversed Sorted
    gettimeofday(&tstart, NULL);
    heapSort(reversedSorted,n, compares);
    gettimeofday(&tend, NULL);
    runtime19 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Heap Sort (Reversed Sorted) Time: " << runtime19 << endl;
    cout << "-Heap Sort (Reversed Sorted) Counts: " << compares << endl;
    compares = 0;

    //Heap Sort: Partially Sorted
    gettimeofday(&tstart, NULL);
    heapSort(partiallySorted,n, compares);
    gettimeofday(&tend, NULL);
    runtime26 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Heap Sort (Partially Sorted) Time: " << runtime26 << endl;
    cout << "-Heap Sort (Partially Sorted) Counts: " << compares << endl<<endl;
    compares = 0;

    //Heap Sort: Dataset
    gettimeofday(&tstart, NULL);
    heapSort(heapInFile,n, compares);
    gettimeofday(&tend, NULL);
    runtime33 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Heap Sort (Dataset) Time: " << runtime33 << endl;
    cout << "-Heap Sort (Dataset) Counts: " << compares << endl<<endl;
    compares = 0;

    //Merge Sort
    int mergeList[n], mergeInFile[n];
    copy_ours(mergeList, randomArray, n);
    copy_ours(mergeInFile, inFileArray, n);

    //Merge Sort: Random
    gettimeofday(&tstart, NULL);
    mergeSort(mergeList,0,n-1,compares);
    gettimeofday(&tend, NULL);
    runtime6 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Merge Sort (Random) Time: " << runtime6 << endl;
    cout << "-Merge Sort (Random) Counts: " << compares << endl;
    compares = 0;

    //Merge Sort: Few Unique
    gettimeofday(&tstart, NULL);
    mergeSort(ptr,0,n-1,compares);
    gettimeofday(&tend, NULL);
    runtime13 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Merge Sort (Few Unique) Time: " << runtime13 << endl;
    cout << "-Merge Sort (Few Unique) Counts: " << compares << endl;
    compares = 0;

    //Merge Sort: Reversed Sorted
    gettimeofday(&tstart, NULL);
    mergeSort(reversedSorted,0,n-1,compares);
    gettimeofday(&tend, NULL);
    runtime20 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Merge Sort (Reversed Sorted) Time: " << runtime20 << endl;
    cout << "-Merge Sort (Reversed Sorted) Counts: " << compares << endl;
    compares = 0;

    //Merge Sort: Partially Sorted
    gettimeofday(&tstart, NULL);
    mergeSort(partiallySorted,0,n-1,compares);
    gettimeofday(&tend, NULL);
    runtime27 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Merge Sort (Partially Sorted) Time: " << runtime27 << endl;
    cout << "-Merge Sort (Partially Sorted) Counts: " << compares << endl<<endl;
    compares = 0;

    //Merge Sort: Dataset
    gettimeofday(&tstart, NULL);
    mergeSort(mergeInFile,0,n-1,compares);
    gettimeofday(&tend, NULL);
    runtime34 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Merge Sort (Dataset) Time: " << runtime34 << endl;
    cout << "-Merge Sort (Dataset) Counts: " << compares << endl<<endl;
    compares = 0;

    //Selection Sort
    int selectionList[n], selectionInFile[n];
    copy_ours(selectionList, randomArray, n);
    copy_ours(selectionInFile, inFileArray, n);

    //Selection Sort: Random
    gettimeofday(&tstart, NULL);
    selectionSort(selectionList,n, swaps, compares);
    gettimeofday(&tend, NULL);
    runtime7 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Selection Sort (Random) Time: " << runtime7 << endl;
    cout << "-Selection Sort (Random) Counts: " << compares << endl;
    cout << "-Selection Sort (Random) Swaps: " << swaps << endl;
    compares = 0;
    swaps = 0;

    //Selection Sort: Few Unique
    gettimeofday(&tstart, NULL);
    selectionSort(ptr,n, swaps, compares);
    gettimeofday(&tend, NULL);
    runtime14 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Selection Sort (Few Unique) Time: " << runtime14 << endl;
    cout << "-Selection Sort (Few Unique) Counts: " << compares << endl;
    cout << "-Selection Sort (Few Unique) Swaps: " << swaps << endl;
    compares = 0;
    swaps = 0;

    //Selection Sort: Reversed Sorted
    gettimeofday(&tstart, NULL);
    selectionSort(reversedSorted,n,swaps,compares);
    gettimeofday(&tend, NULL);
    runtime21 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Selection Sort (Reversed Sorted) Time: " << runtime21 << endl;
    cout << "-Selection Sort (Reversed Sorted) Counts: " << compares << endl;
    cout << "-Selection Sort (Reversed Sorted) Swaps: " << swaps << endl;
    compares = 0;
    swaps = 0;

    //Selection Sort: Partially Sorted
    gettimeofday(&tstart, NULL);
    selectionSort(partiallySorted,n,swaps,compares);
    gettimeofday(&tend, NULL);
    runtime28 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Selection Sort (Partially Sorted) Time: " << runtime28 << endl;
    cout << "-Selection Sort (Partially Sorted) Counts: " << compares << endl;
    cout << "-Selection Sort (Partially Sorted) Swaps: " << swaps << endl<<endl;
    compares = 0;

    //Selection Sort: Dataset
    gettimeofday(&tstart, NULL);
    selectionSort(selectionInFile,n,swaps,compares);
    gettimeofday(&tend, NULL);
    runtime35 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Selection Sort (Dataset) Time: " << runtime35 << endl;
    cout << "-Selection Sort (Dataset) Counts: " << compares << endl;
    cout << "-Selection Sort (Dataset) Swaps: " << swaps << endl<<endl;
    compares = 0;

    return 0;
}

//swap_ours function for the selection sort
void swap_ours(int arr[], int first, int second) {
    int temp = arr[second];
    arr[second] = arr[first];
    arr[first] = temp;
}

//selection sort
void selectionSort(int arr[], int n, int &swaps, int &compares)
{
    int i, j, minIndex;
    for (i = 0; i < n-1; i++)
    {
        minIndex = i;
        for (j = i+1; j < n; j++)
        {
          compares++;
          if (arr[j] < arr[minIndex])
          {
            minIndex = j;
          }
        }
        swap_ours(arr, minIndex, i);
        if(minIndex != i)
          swaps++;
    }
}   

//Merge Function
void merge(int arr[], int start, int mid, int end)
{
   int length1 = mid - start + 1;
   int length2 = end - mid;  

    int leftArr[length1], rightArr[length2];

  for (int i = 0; i < length1; i++)
    leftArr[i] = arr[start + i];
  for (int j = 0; j < length2; j++)
    rightArr[j] = arr[mid + 1 + j];

  int a, b, c;
  a = 0;
  b = 0;
  c = start;

  while (a < length1 && b < length2) {
    if (leftArr[a] <= rightArr[b]) {
      arr[c] = leftArr[a];
      a++;
    } else {
      arr[c] = rightArr[b];
      b++;
    }
    c++;
  }

  while (a < length1) {
    arr[c] = leftArr[a];
    a++;
    c++;
  }

  while (b < length2) {
    arr[c] = rightArr[b];
    b++;
    c++;
  }
}

//Merge Sort
void mergeSort(int arr[], int start, int end, int &compares)
{
  if(start < end){
     int mid = start + (end - start)/2;
     mergeSort(arr,start,mid,compares);
     mergeSort(arr,mid + 1,end,compares);
     merge(arr, start, mid, end);
  }
  compares++;
}
    
//Heapify Function
void heapify(int arr[], int n, int i, int &compares)
{
  int largest = i; //Last element becomes root
  int l = 2 * i + 1; //Left element
  int r = 2 * i + 2; //Right element

  //Left > Largest Case
  if (l < n && arr[l] > arr[largest])
  {
      largest = l;
      compares++;
  }

  //Right > Largest Case
  if (r < n && arr[r] > arr[largest])
  {
      largest = r;
      compares++;
  }

  //If Largest isn't the root
  if (largest != i)
  {
    swap(arr[i],arr[largest]);
    compares++;
    heapify(arr, n, largest, compares);
  }
}

//Main Heap Sort Function
void heapSort(int arr[], int n, int &compares)
{
  //Builds the heap
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(arr, n, i, compares);
  }

  //Removes an element from heap
  for (int i = n - 1; i >= 0; i--)
  {
    //Moves root to the end of the array
    swap(arr[0], arr[i]);

    //Call max heapify on reduced heap
    heapify(arr, i, 0, compares);
  }
}

//Bubble Sort
void bubbleSort(int arr[], int arraySize, int &compares)
{
  int temp;

  for (int i = 0; i < arraySize; i++)
  {
      //The Bubble
      for (int j = 0; j < arraySize; j++)
      {
          if (arr[j] > arr[j+1])
          {
            temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
            compares++;
          }
      }
  }
}

//Exchange Sort 
void exchangeSort(int arr[], int z, int &swaps, int &compares)
{
    int length = z;
    int n;
    //int swaps = 0, compares = 0;
    for (int j = 0; j < length-1; j++)
    {
        for(n = j+1; n < length; n++)
        {
            if (arr[j] > arr[n])
            {
                swaps++;
                swap_ours(arr, j, n);
            }
            compares++;
        }
    }
}

//Insertion Sort
void insertionSort(int arr[], int n, int &compares)
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
            compares++;
        }
        compares++;
        arr[j + 1] = key;
    }
}

//Array copy_ours function
void copy_ours(int arrA[], const int arrB[], int z)
{
    for(int i=0; i < z; i++)
        arrA[i] = arrB[i];
}


//Partition function
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];   
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;    
            swap_ours(arr, i, j);
        }
    }
    swap_ours(arr, (i + 1), high);
    return (i + 1);
}
 
//quick sort function 
void quickSort(int arr[], int low, int high, int &compares)
{
    if (low < high)
    {
        compares++;
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1, compares);
        quickSort(arr, pi + 1, high, compares);
    }
}

int* arrayGenerator(int arr[], int n)
{
  srand(time(0));

  //First integer
  int x = rand() % n;

  for (int i = 0; i < n / 4; i++)
  {
    x = arr[i];
  }

  //Second integer
  x = rand() % n;

  for (int j = 0; j < n / 4; j++)
  {
    x = arr[j];
  }

  //Third integer
  x = rand() % 1000;

  for (int k = 0; k < n / 4; k++)
  {
    x = arr[k];
  }

  //Fourth integer
  x = rand() % 1000;

  for (int l = 0; l < n / 4; l++)
  {
    x = arr[l];
  }

  return arr;
}
