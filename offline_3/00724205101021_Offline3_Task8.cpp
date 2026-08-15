
#include <bits/stdc++.h>
using namespace std;

long long compareCount = 0;

void Merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> left(arr.begin() + low, arr.begin() + mid + 1);
    vector<int> right(arr.begin() + mid + 1, arr.begin() + high + 1);

    int i = 0, j = 0, k = low;

    while (i < (int)left.size() && j < (int)right.size())
    {
        compareCount++;
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < (int)left.size())
        arr[k++] = left[i++];
    while (j < (int)right.size())
        arr[k++] = right[j++];
}

void Merge_Sort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        Merge_Sort(arr, low, mid);
        Merge_Sort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
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

    Merge_Sort(arr, 0, N - 1);

    cout << "Number of comparisons: " << compareCount << endl;

    cout << "Sorted array: " << endl;
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
/*Output
Please enter the size of the array: 
6
Please enter the elements of the array: 
12 11 13 5 6 7
Number of comparisons: 9
Sorted array: 
5 6 7 11 12 13
*/
