
#include <bits/stdc++.h>
using namespace std;
int compareCount = 0;
int swapCount = 0;

int Partition(vector<int> &arr, int low, int high);

int Partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    cout << "Pivot: " << pivot << endl;

    int elements_less = 0;
    for (int k = low; k < high; k++)
    {
        if (arr[k] < pivot)
            elements_less++;
    }
    cout << "Pivot " << pivot << " has " << elements_less
         << " element(s) less than it in this subarray.\n";

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        compareCount++;
        if (arr[j] < pivot)
        {
            i++;
            if (i != j)
            {
                swap(arr[i], arr[j]);
                swapCount++;
            }
        }
    }

    swap(arr[i + 1], arr[high]);
    swapCount++;

    return i + 1;
}

void Quick_Sort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = Partition(arr, low, high);
        cout << "Final index of pivot: " << pivotIndex << endl;
        Quick_Sort(arr, low, pivotIndex - 1);
        Quick_Sort(arr, pivotIndex + 1, high);
    }
}

int main(void)
{
    int N, x;
    cout << "Please enter the size of the array: " << endl;
    cin >> N;

    vector<int> arr;
    cout << "Please enter the elements of the array: " << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    Quick_Sort(arr, 0, N - 1);

    cout << "Number of comparisons: " << compareCount << endl;
    cout << "Number of swaps: " << swapCount << endl;

    cout << "Sorted array: " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
/*1. Given an array of N integers, simulate Quick Sort using the last element as pivot and
count the number of comparisons performed during the sorting process.
2. Given an array and a pivot, rearrange the array such that elements less than pivot come
before it and greater come after.
3. Count the number of swaps required to sort an array using quick sort.
4. Output the pivot chosen at each recursive call in quick sort (always pick the last element
as pivot).
5. For each recursive quick sort call, output the final index where pivot is placed.
6. For each pivot selected in quick sort (last element as pivot), count how many elements
are less than the pivot at that step.*/
// Answers :
/*Please enter the size of the array:
Please enter the elements of the array:
Pivot: 88
Pivot 88 has 5 element(s) less than it in this subarray.
Final index of pivot: 5
Pivot: 66
Pivot 66 has 4 element(s) less than it in this subarray.
Final index of pivot: 4
Pivot: 45
Pivot 45 has 3 element(s) less than it in this subarray.
Final index of pivot: 3
Pivot: 21
Pivot 21 has 0 element(s) less than it in this subarray.
Final index of pivot: 0
Pivot: 44
Pivot 44 has 1 element(s) less than it in this subarray.
Final index of pivot: 2
Number of comparisons: 15
Number of swaps: 5
Sorted array:
21 22 44 45 66 88*/