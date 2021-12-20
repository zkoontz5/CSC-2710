/*
Zach Koontz
Dr. Williams
CSC-2710
3 December 2021
Hashed vs Non-Hashed Sorting Program
*/

#include<iostream>
#include<cstdlib>
#include<string>
#include<chrono>
#include<ctime>

using namespace std;

void merge(int arr[], int start, int mid, int end);
void mergeSort(int arr[], int start, int end, int &compares);
void hashSort(int arr[], int n, int &compares);

int main()
{
    //Variables and Array
    int array1[] = {1, 3, 2, 7, 5, 4, 8, 7}, array2[] = {1, 3, 2, 7, 5, 4, 8, 7};
    int compares1, compares2, compares3, compares4, n = sizeof(array1)/sizeof(array1[0]), m = 0, size = 1000;
    int randomArray[size], randomArray2[size];
    std::chrono::time_point<std::chrono::system_clock> start, end, start2, end2, start3, end3, start4, end4;

    //Random Array Generator
    srand(time(0));

    for (int i = 0; i < size; i++)
    {
        int x = rand() % 1000;
        randomArray[i] = x;
        randomArray2[i] = x;
    }

    //Hashed Sort: Small Array
    start = std::chrono::system_clock::now();
    hashSort(array1, n, compares1);
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = (end - start);
    std::cout << "Hashed Sort Time: " << elapsed_seconds.count() << "s\n";
    cout << "Compares: " << compares1 << endl << endl;

    //Hashed Sort: Random Array
    start3 = std::chrono::system_clock::now();
    hashSort(randomArray, size, compares3);
    end3 = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds3 = (end3 - start3);
    std::cout << "Random Array Hashed Sort Time: " << elapsed_seconds3.count() << "s\n";
    cout << "Compares: " << compares3 << endl << endl;

    //Non-Hashed Sort: Small Array
    start2 = std::chrono::system_clock::now();
    mergeSort(array2, m, n, compares2);
    end2 = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds2 = (end2 - start2);
    std::cout << "Non-Hashed Merge Sort Time: " << elapsed_seconds2.count() << "s\n";
    cout << "Compares: " << compares2 << endl << endl;

    //Non-Hashed Sort: Random Array
    start4 = std::chrono::system_clock::now();
    mergeSort(randomArray2, m, size, compares4);
    end4 = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds4 = (end4 - start4);
    std::cout << "Random Array Non-Hashed Merge Sort Time: " << elapsed_seconds4.count() << "s\n";
    cout << "Compares: " << compares4 << endl << endl;

    return 0;
}


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

//Algorithm provided from TutorialCup
void hashSort(int arr[], int n, int &compares)
{
    int max = *std::max_element(arr, arr + n);
    int min = abs(*std::min_element(arr, arr + n));
    
    int positiveNum[max + 1];
    int negativeNum[min + 1];

    for (int i = 0; i < max; i++)
    {
        positiveNum[i] = 0;
    }

    for (int j = 0; j < min; j++)
    {
        negativeNum[j] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0) {
            positiveNum[arr[i]] += 1;
            compares++;
        }
        else {
            negativeNum[abs(arr[i])] += 1;
            compares++;
        }
    }
    for (int i = min; i > 0; i--)
    {
        if (negativeNum[i])
        {
            for (int j = 0; j < negativeNum[i]; j++)
            {
                //cout << (-1) * i << " ";
            }
        }
    }
    for (int i = 0; i <= max; i++)
    {
        if (positiveNum[i])
        {
            for (int j = 0; j < positiveNum[i]; j++)
            {
                //cout << i << " ";
            }
        }
    }
}
