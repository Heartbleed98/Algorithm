#include<iostream>
#include<string>
#include<vector>
using namespace std;

void SelectionSort(int arr[], int n)
{
	int i, j, min_index;
	for(int i = 0; i < n - 1; i++)
	{
		min_index = i;
		for(j = i + 1; j < n; j++)
			if(arr[j] < arr[min_index])
				min_index = j;
		swap(arr[min_index], arr[i]);
	}
}
int main()
{
	int arr[8] = {99, 22, 27, 98, 10, 1, 27, 32};
	SelectionSort(arr, 8);
	for(int i = 0; i < 8; i++)
	{
		cout<<arr[i]<<" ";
	}

	return 0;
}

