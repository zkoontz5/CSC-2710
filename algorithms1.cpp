/*
   Zach Koontz
   Algorithims 2710
   Due: Sep 10 2021
   Location: zkoontz/csc2710/assignments/prg1.cpp
*/

#include <iostream>
#include <string>

using namespace std;

//Prototypes
int binarySearch(int arr[], int l, int r, int x);
int seqSearch(int list[], int start, int bounds, int key);
void exchangeSort(int arr[], int n);
int fibRec(int n);
void fibIt(int num);
void arrPrint(int array[],int sizeall);
void arrFill(int array[], int sizeall);

int main(void)
{
    bool control = true;
       while(control)
       {
           string red;
           int size;
           cout << "Enter <Seq, Bin or Fib> for the search type or enter stop to terminate program" << endl;
           cin >> red;
           if(red == "stop"){return 0;}
           if(red == "Seq" || (red == "Bin"))
           {
               cout << "Enter the size of the Array or hit 2 to quit ";
               cin >> size;
               
               if(size == 2){return 0;}
               int arr[size];
               arrFill(arr, size);
               arrPrint(arr,size);
           
           
               if(red == "Seq")
               {
                   int iArray[] = {1706, 30, 45, 60, 90, 42, 1138, 47, 451, 6174, 73};
                   int key, returnVal = 0;

                   std::cout << "Please enter a value to search for: ";
                   std::cin >> key;

                   if((returnVal=seqSearch(iArray, 0, sizeof(iArray) / sizeof(int), key))<0){
                       std::cout << "Value not found." << std:: endl;
                   } else {
                       std::cout << "Value found at index " << returnVal << std::endl;
                   }
               }
               
               if(red == "Bin")
               {
                   int arr[] = { 2, 3, 4, 10, 40 };
                    int x = 10;
                    int n = sizeof(arr) / sizeof(arr[0]);
                    int result = binarySearch(arr, 0, n - 1, x);
                    (result == -1) ? cout << "Element is not present in array"
                                   : cout << "Element is present at index " << result;
                   return 0;
           }
           if(red == "Fib")
           {
               int num;
               cout << "Enter the number : ";
               cin >> num;
               cout << "\nThe fibonacci series : " ;
               fibIt(num);
               return 0;
               
           }
        }
     }
  }

//Binary Search
int binarySearch(int arr[], int z, int a, int c)
{
    if (a >= z) {
        int mid = z + (a - z) / 2;
        if (arr[mid] == c)
            return mid;
        if (arr[mid] > c)
            return binarySearch(arr, z, mid - 1, c);
            return binarySearch(arr, mid + 1, a, c);
    }
    return -1;
}

//Sequential Search
int seqSearch(int list[], int start, int bounds, int key)
{
    while(start < bounds){
        if(list[start]==key){
            return start;
        } else {
            start++;
        }
    }
    //no match found
    return -1;
}

//Exchange Sort
void exchangeSort(int arr[], int z)
{
    int length = z;
    int n;
    for (int j = 0; j < length-1; j++)
    {
        for(n = j+1; n < length; n++)
        {
            int temp;
            if (arr[j] > arr[n]){
                temp = arr[j];
                arr[j] = arr[n];
                arr[n] = temp;}
        }
    }
}

//Fibonacci Recursive
int fibRec(int n)
{
    if (n <= 1)
        return n;
    return fibRec(n-1) + fibRec(n-2);
}


//Fibanocci Iteration
void fibIt(int num)
{
   int x = 0, y = 1, z = 0;
   for (int i = 0; i < num; i++) {
      cout << x << " ";
      z = x + y;
      x = y;
      y = z;
   }
}

//Array Print
void arrPrint(int array[],int sizeall)
{
    for( int i = 0; i<sizeall ; i++ )
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

//Array Filler
void arrFill(int array[], int sizeall)
{
    for(int i = 0; i < sizeall; i++)
    {
        array[i] = rand() % sizeall +1 ;
    }
}
