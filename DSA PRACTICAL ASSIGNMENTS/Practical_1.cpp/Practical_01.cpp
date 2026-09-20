#include <iostream>
#include <cstring>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;
struct Student
{
    int id;
    char name[50];
    float cgpa;
};

Student *students = NULL;
int n = 0;

//---------------- Add Student ----------------//
void addStudent()
{
    students = (Student*)realloc(students, (n + 1) * sizeof(Student));

    cout << "\nEnter Student ID : ";
    cin >> students[n].id;

    cout << "Enter Student Name : ";
    cin >> students[n].name;

    cout << "Enter CGPA : ";
    cin >> students[n].cgpa;

    n++;

    cout << "\nStudent Added Successfully.\n";
}

//---------------- Display ----------------//
void display()
{
    if (n == 0)
    {
        cout << "\nDatabase Empty\n";
        return;
    }

    cout << "\n-----------------------------------------\n";
    cout << "ID\tName\tCGPA\n";
    cout << "-----------------------------------------\n";

    for (int i = 0; i < n; i++)
    {
        cout << students[i].id << "\t"
             << students[i].name << "\t"
             << students[i].cgpa << endl;
    }

    cout << "-----------------------------------------\n";
}

//---------------- Linear Search ----------------//
int linearSearch(int key)
{
    for (int i = 0; i < n; i++)
    {
        if (students[i].id == key)
            return i;
    }

    return -1;
}

//---------------- Sort By ID ----------------//
void sortByID()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (students[j].id > students[j + 1].id)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

//---------------- Binary Search ----------------//
int binarySearch(int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (students[mid].id == key)
            return mid;

        if (key < students[mid].id)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

//---------------- Bubble Sort Name ----------------//
void bubbleSortName()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(students[j].name, students[j + 1].name) > 0)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    cout << "\nSorted By Name Successfully.\n";
}

//---------------- Selection Sort CGPA ----------------//
void selectionSortCGPA()
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (students[j].cgpa < students[min].cgpa)
                min = j;
        }

        Student temp = students[min];
        students[min] = students[i];
        students[i] = temp;
    }

    cout << "\nSorted By CGPA Successfully.\n";
}

//---------------- Performance ----------------//
void compareSearch()
{
    if (n == 0)
    {
        cout << "\nDatabase Empty\n";
        return;
    }

    int key;

    cout << "\nEnter ID to Search : ";
    cin >> key;

    auto start = high_resolution_clock::now();

    int pos = linearSearch(key);

    auto stop = high_resolution_clock::now();

    auto linearTime = duration_cast<nanoseconds>(stop - start);

    if (pos != -1)
        cout << "\nLinear Search : Record Found";
    else
        cout << "\nLinear Search : Record Not Found";

    // Sort records before binary search
    sortByID();

    start = high_resolution_clock::now();

    pos = binarySearch(key);

    stop = high_resolution_clock::now();

    auto binaryTime = duration_cast<nanoseconds>(stop - start);

    if (pos != -1)
        cout << "\nBinary Search : Record Found";
    else
        cout << "\nBinary Search : Record Not Found";

    cout << "\n\nSearch Performance\n";

    cout << "\nLinear Search Time : "
         << linearTime.count()
         << " ns";

    cout << "\nBinary Search Time : "
         << binaryTime.count()
         << " ns" << endl;
}

//---------------- Main ----------------//
int main()
{
    int choice;

    do
    {
        cout << "\n========== STUDENT DATABASE ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Linear Search\n";
        cout << "4. Bubble Sort by Name\n";
        cout << "5. Selection Sort by CGPA\n";
        cout << "6. Binary Search\n";
        cout << "7. Compare Search Performance\n";
        cout << "8. Exit\n";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                display();
                break;

            case 3:
            {
                int id;

                cout << "Enter ID : ";
                cin >> id;

                int pos = linearSearch(id);

                if (pos != -1)
                    cout << "\nRecord Found";
                else
                    cout << "\nRecord Not Found";

                break;
            }

            case 4:
                bubbleSortName();
                display();
                break;

            case 5:
                selectionSortCGPA();
                display();
                break;

            case 6:
            {
                sortByID();

                int id;

                cout << "Enter ID : ";
                cin >> id;

                int pos = binarySearch(id);

                if (pos != -1)
                    cout << "\nRecord Found";
                else
                    cout << "\nRecord Not Found";

                break;
            }

            case 7:
                compareSearch();
                break;

            case 8:
                free(students);
                cout << "\nProgram Ended";
                break;

            default:
                cout << "\nInvalid Choice";
        }

    } while (choice != 8);

    return 0;
}
