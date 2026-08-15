
#include <bits/stdc++.h>
using namespace std;

long long swapCount = 0;

int Partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
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
        Quick_Sort(arr, low, pivotIndex - 1);
        Quick_Sort(arr, pivotIndex + 1, high);
    }
}

int main(void)
{
    int N;
    cout << "Please enter the size of the array: " << endl;
    cin >> N;

    vector<int> arr(N);
    cout << "Please enter the elements of the array: " << endl;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    Quick_Sort(arr, 0, N - 1);

    cout << "Number of swaps: " << swapCount << endl;

    cout << "Sorted array: " << endl;
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
/*Output
Please enter the size of the array: 
5
Please enter the elements of the array: 
8 4 7 3 5
Number of swaps: 5
Sorted array: 
3 4 5 7 8
*/