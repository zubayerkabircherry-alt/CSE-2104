
#include <bits/stdc++.h>
using namespace std;

int PartitionOnValue(vector<int> &arr, int low, int high, int pivotValue)
{
    int pivotPos = -1;
    for (int k = low; k <= high; k++)
    {
        if (arr[k] == pivotValue)
        {
            pivotPos = k;
            break;
        }
    }
    if (pivotPos == -1)
    {
        cout << "Pivot value not found in array!" << endl;
        return -1;
    }
    swap(arr[pivotPos], arr[high]);

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
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

    int pivotValue;
    cout << "Please enter the pivot value: " << endl;
    cin >> pivotValue;

    int finalIndex = PartitionOnValue(arr, 0, N - 1, pivotValue);

    if (finalIndex != -1)
    {
        cout << "Array after partitioning around pivot " << pivotValue << ": " << endl;
        for (int i = 0; i < N; i++)
            cout << arr[i] << " ";
        cout << endl;
        cout << "Pivot placed at index: " << finalIndex << endl;
    }

    return 0;
}
/*Output 
Please enter the size of the array: 
7
Please enter the elements of the array: 
10 80 30 90 40 50 70
Please enter the pivot value: 
50
Array after partitioning around pivot 50: 
10 30 40 50 80 70 90 
Pivot placed at index: 3
*/
