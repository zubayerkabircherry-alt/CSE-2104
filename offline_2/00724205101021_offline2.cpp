/*-array of books with its title,publication year, author’s name
-year compare korle descending order,same year publication hole author name lexicography(basically alphabet order with numbers in ascending order)
-selectiong sorting use korte hobe in ascending order
*/
#include <bits/stdc++.h>
using namespace std;

struct bookInfo
{
    int publicationYear;
    string title;
    string author;
};

void selectionSort(bookInfo books[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (books[j].publicationYear > books[maxIndex].publicationYear)
            {
                maxIndex = j;
            }
            else if (books[j].publicationYear == books[maxIndex].publicationYear)
            {
                if (books[j].author < books[maxIndex].author)
                {
                    maxIndex = j;
                }
                else if (books[j].author == books[maxIndex].author)
                {
                    if (books[j].title < books[maxIndex].title)
                    {
                        maxIndex = j;
                    }
                }
            }
        }
        swap(books[i], books[maxIndex]);
    }

    cout << "Sorted book information: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << books[i].title << ", " 
         << books[i].author << ", " 
         << books[i].publicationYear << endl;
    }
}
int main(void)
{
    int n;
    cout << "Please enter the number of books: " << endl;
    cin >> n;
    bookInfo books[n];
    if (1 <= n && n <= 100)
    {
        cout << "Please enter the book information: " << endl;
    }
    else
    {
        cout << "Invalid input" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Please enter the book title: " << endl;
        getline(cin>>ws, books[i].title);
        if (1 > books[i].title.length() || books[i].title.length() > 100)
        {
            cout << "Invalid input" << endl;
            return 0;
        }
        cout << "Please enter the book's author: " << endl;
        getline(cin>>ws, books[i].author);
        if (1 > books[i].author.length() || books[i].author.length() > 100)
        {
            cout << "Invalid input" << endl;
            return 0;
        }
        cout << "Please enter the book publication year: " << endl;
        cin >> books[i].publicationYear;
        if (1900 > books[i].publicationYear || books[i].publicationYear > 2025)
        {
            cout << "Invalid input" << endl;
            return 0;
        }
    }
    selectionSort(books, n);
}
