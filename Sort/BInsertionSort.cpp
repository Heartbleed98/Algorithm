// 折半插入排序（Binary Insertion Sort)
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void BInsertionSort(int arr[], int n)
{
	int i, j, key;
    int low, high;
	for(int i = 1; i < n; i++)
	{
		key = arr[i];
        low = 0; high = i - 1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(key < arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

		for(int j = i - 1; j >= low; j--)
            arr[j+1] = arr[j];
        arr[low] = key;
	}
}

int main()
{
	int arr[] = {2, 2, 12, 11, 13, 5, 6, 43, 43, 27}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    BInsertionSort(arr, n);
    for(int i = 0; i < n; i++)
    {
    	cout<<arr[i]<<" ";
	}

	return 0;
}

