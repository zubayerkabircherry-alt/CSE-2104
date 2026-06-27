#include <bits/stdc++.h>
using namespace std;

vector<int> books;
int item;// global variable ok

void binarySearch()
{
    int low = 0;
    int high = books.size() - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (books[mid] == item)
        {
            cout<<endl<< "Book found";
            return;
        }
        else if (books[mid] < item)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "Book not found";
}

void lowerBound()
{
    int low = 0;
    int high = books.size();
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (books[mid] < item)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    cout << "The lower bound index of the Book ID is: " << low;
}

void upperBound()
{
    int low = 0;
    int high = books.size();
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (books[mid] <= item)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    cout << "The upper bound index of the Book ID is: " << low;
}

int main(void)
{
    int size, i, x, temp;
    cout << "Enter the number of Books you want to add: ";
    cin >> size;
    
    cout << "\nEnter the list of Book ID(s):\n";
    for (i = 0; i < size; i++)
    {
        cin >> x;
        books.push_back(x);
    }
    
    for (int m = 0; m < size - 1; m++)
    {
        for (int j = 0; j < size - 1 - m; j++)
        {
            if (books[j + 1] < books[j])
            {
                temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }  
    cout<<endl<< "Please enter the Book ID you want to search: ";
    cin >> item; 
    
    cout << "\nThe following answer is:";
    binarySearch();
    cout << endl;
    lowerBound();
    cout << endl;
    upperBound();
    cout << endl;

    return 0;
}