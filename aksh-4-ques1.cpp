#include<iostream>
using namespace std;

void merge(int arr[], int l, int r, int m, int& c, int& inversions)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }    
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
            inversions ++;
        }
        else
        {
            arr[k++] = R[j++];
            inversions ++;
        }
        c++; 
    }
    while (i < n1) 
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

void mergesort(int arr[], int l, int r, int& c, int& inversions)
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m, c, inversions);
        mergesort(arr, m + 1, r, c, inversions);
        merge(arr, l, r, m, c, inversions);
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
        int comparisons = 0;
        int inversions = 0;
        mergesort(arr, 0, n - 1, comparisons, inversions);
        cout << "Sorted array:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "The number of comparisons are: " << comparisons << endl;
        cout << "The number of inversions are: " << inversions << endl;
    }
    return 0;
}