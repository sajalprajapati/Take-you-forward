#include<bits/stdc++.h>
using namespace std;

bool load_on_the_student(vector<int> &books, int middle, int studentCount)
{
    int currentPages = 0;
    int requiredStudents = 1;

    for (int i = 0; i < books.size(); i++)
    {
        if (currentPages + books[i] <= middle)
        {
            currentPages += books[i];
        }
        else
        {
            requiredStudents++;
            currentPages = books[i]; // Start new student with current book
            if (requiredStudents > studentCount)
            {
                return false;
            }
        }
    }

    return true;
}

int allocation_of_books(vector<int> &books, int studentCount)
{
    // Initialize binary search range
    int lower = *max_element(books.begin(), books.end());
    int higher = accumulate(books.begin(), books.end(), 0);
    int answer = higher;

    while (lower <= higher)
    {
        int middle = lower + (higher - lower) / 2;

        if (load_on_the_student(books, middle, studentCount))
        {
            answer = middle;
            higher = middle - 1; // Try for smaller maximum pages
        }
        else
        {
            lower = middle + 1; // Increase the maximum pages
        }
    }

    return answer;
}

int main()
{
    int size;
    cout<<endl;
    cout << "Enter the number of books: "<<endl;;
    cin >> size;

    vector<int> books;
    cout << "Enter the number of pages of each book:" << endl;
    for (int i = 0; i < size; i++)
    {
        int element;
        cin >> element;
        books.push_back(element);
    }

    int studentCount;
    cout << "Enter the number of students: ";
    cin >> studentCount;

    if (studentCount > size)
    {
        cout << "Number of students cannot be greater than the number of books." << endl;
        return 1;
    }

    int result = allocation_of_books(books, studentCount);
    cout << "The minimum maximum pages any student can get is: " << result << endl;

    return 0;
}
