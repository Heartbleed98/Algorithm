#include<iostream>
#include<algorithm>
using namespace std;

void HeapAdjust(int arr[], int start, int end)
{
    int current = start;
    int lc = 2 * current + 1;
    for( ; lc <= end; lc = 2 * lc + 1)
    {
        // lc是左孩子，lc+1是右孩子，比较后lc指向大的那个
        if(lc < end && arr[lc] < arr[lc+1])
            lc++;
        
        if(arr[current] >= arr[lc])
            break;
        else 
        {
            swap(arr[current], arr[lc]);
            current = lc;
        }
    }
}

void HeapSort(int arr[], int n)
{
    for(int i = n / 2; i >= 0; i--)
    {
        HeapAdjust(arr, i, n-1);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        HeapAdjust(arr, 0, i - 1);
    }
}

int main()
{
    int arr[8] = {12, 1, 30, 23, 6, 9, 99, 11};
    int n = sizeof(arr)/sizeof(arr[0]); 
    HeapSort(arr, n);
    for(int i = 0; i < 8; i++)
        printf("%d ", arr[i]);
    return 0;
}