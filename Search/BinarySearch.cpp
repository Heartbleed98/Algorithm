#include<iostream>
#include<string>
#include<vector>
using namespace std;

int binarySearch(int arr[], int x, int l, int r)
{
	int mid = l + (r - l) / 2;
	while(l <= r)
	{
		if(x == arr[mid])
			return mid;
		else if(x < arr[mid])
			r = mid - 1;
		else
			l = mid + 1;	
	}	
	return -1;
}

int main()
{
	int arr[8] = {0, 2, 7, 21, 23, 54, 77, 89};
	cout<<binarySearch(arr, 21, 0, 7);

	return 0;
}

