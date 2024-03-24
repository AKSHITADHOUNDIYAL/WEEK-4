#include<iostream>
using namespace std;

int partition(int arr[], int l, int r, int& s, int& c) 
{
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(arr[i], arr[j]);
            s++;
        }
        c++; 
    }
    swap(arr[i + 1], arr[r]);
    s++;
    return i + 1;
}

void quicksort(int arr[], int l, int r, int& s, int& c)
{
    if (l < r) 
    {
        int p = partition(arr, l, r, s, c);
        quicksort(arr, l, p - 1, s, c);
        quicksort(arr, p + 1, r, s, c);
    }
}

int main()
{
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    for (int j = 0; j < t; j++) 
    {
        int n;
        cout << "Enter the array limit: ";
        cin >> n;
        int arr[n];
        cout << "Enter the array elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int s = 0; 
        int c = 0; 
        quicksort(arr, 0, n - 1, s, c);
        cout << "Sorted array:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "The number of swaps are: " << s << endl;
        cout << "The number of comparisons are: " << c << endl;
    }

    return 0;
}
