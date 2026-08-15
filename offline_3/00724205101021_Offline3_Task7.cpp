
#include <bits/stdc++.h>
using namespace std;

vector<int> mergeArrays(const vector<int> &a, const vector<int> &b)
{
    vector<int> merged;
    int i = 0, j = 0;

    while (i < (int)a.size() && j < (int)b.size())
    {
        if (a[i] <= b[j])
            merged.push_back(a[i++]);
        else
            merged.push_back(b[j++]);
    }
    while (i < (int)a.size())
        merged.push_back(a[i++]);
    while (j < (int)b.size())
        merged.push_back(b[j++]);

    return merged;
}

double findMedian(const vector<int> &merged)
{
    int n = merged.size();
    if (n % 2 == 1)
        return merged[n / 2];
    else
        return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
}

int main(void)
{
    int N1, N2;
    cout << "Please enter the size of the first sorted array: " << endl;
    cin >> N1;
    vector<int> a(N1);
    cout << "Please enter the elements of the first sorted array: " << endl;
    for (int i = 0; i < N1; i++)
        cin >> a[i];

    cout << "Please enter the size of the second sorted array: " << endl;
    cin >> N2;
    vector<int> b(N2);
    cout << "Please enter the elements of the second sorted array: " << endl;
    for (int i = 0; i < N2; i++)
        cin >> b[i];

    vector<int> merged = mergeArrays(a, b);

    cout << "Merged array: " << endl;
    for (int x : merged)
        cout << x << " ";
    cout << endl;

    double median = findMedian(merged);
    cout << "Median of combined array: " << median << endl;

    return 0;
}
/*Output
Please enter the size of the first sorted array: 
3
Please enter the elements of the first sorted array: 
1 4 8
Please enter the size of the second sorted array: 
4
Please enter the elements of the second sorted array: 
2 5 6 9
Merged array: 
1 2 4 5 6 8 9 
Median of combined array: 5
*/
