#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void FindSameRowAndColumn(int** a, const int n);
int SumRowsWithNegativeElements(int** a, const int n);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -3;
    int High = 3;
    int n;

    cout << "n = "; cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High);
    Print(a, n);

    FindSameRowAndColumn(a, n);

    int sum = SumRowsWithNegativeElements(a, n);
    cout << "Sum of rows with negative elements: " << sum << endl;

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void FindSameRowAndColumn(int** a, const int n)
{
    cout << "Rows and columns that are the same:" << endl;
    for (int k = 0; k < n; k++)
    {
        bool found = true;
        for (int i = 0; i < n; i++)
        {
            if (a[k][i] != a[i][k])
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            cout << "Row " << k << " and Column " << k << endl;
        }
    }
}

int SumRowsWithNegativeElements(int** a, const int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        bool hasNegative = false;
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] < 0)
            {
                hasNegative = true;
                break;
            }
        }
        if (hasNegative)
        {
            for (int j = 0; j < n; j++)
            {
                sum += a[i][j];
            }
        }
    }
    return sum;
}
