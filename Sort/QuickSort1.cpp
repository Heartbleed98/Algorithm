#include<iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int tmp = arr[low];
    int pivot = arr[low];
    while(low < high)
    {
        while(low < high && arr[high] >= pivot)
            high--;
        arr[low] = arr[high];
        while(low < high && arr[low] <= pivot)
            low++;
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

void QuickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 101, 1, 5, 5, 22, 0, -1, 98}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	QuickSort(arr, 0, n-1); 

    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}