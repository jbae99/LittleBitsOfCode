// C++ program to sort an
// array using bucket sort
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

 void bucketSort(double arr[], int n);
/* Driver program */
int main()
{
    double arr[]
        = { 54, 65, 98, 32, 4, 87, 32, 54, 12, 11, 16 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
 
    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}


 
// Function to sort arr[] of
// size n using bucket sort
void bucketSort(double arr[], int n)
{
     
    // 1) Create n empty buckets (array of n vectors)
    vector<double>* b = new vector<double>[n];

  
    int min = 100, max = 0, buckets = (n/2);
    for(int i = 0;i < n; i++){
      if(arr[i] < min) min = arr[i];
      if(arr[i] > max) max = arr[i];
    }
  
    int range = max - min;
    int bucketRange = range/buckets;
    
    for (int i = 0; i < n; i++) {
        int bi = (arr[i] - min)/bucketRange; // Index of proper bucket
        b[bi].push_back(arr[i]);  //insert value into the appropriate bucket
    }
 
    // 3) Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
 
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];

  delete[] b;
}