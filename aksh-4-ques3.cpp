#include<iostream>
using namespace std;

int partition(int arr[], int l, int r) 
{
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quicksort(int arr[], int l, int r)
{
    if (l < r) 
    {
        int p = partition(arr, l, r);
        quicksort(arr, l, p - 1);
        quicksort(arr, p + 1, r);
    }
}

int main()
{
    int t,key_s,key_l;
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
        quicksort(arr, 0, n - 1);
        cout<<"Enter the smallest element to be found"<<endl;
        cin>>key_s;
        cout<<"Enter the largest element to be found"<<endl;
        cin>>key_l;
        cout << "Sorted array:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        int m= key_s - 1;
        int p= n - key_l;
        cout<<"The"<<" "<<key_s <<" "<<"smallest element is"<<" " <<arr[m] <<" "<<endl;
        cout<<"The"<<" "<< key_l<<" "<<"largest element is"<<" "<< arr[p] <<" "<<endl;
    }
    return 0;
}