#include<iostream>
using namespace std;

void HeapAdjust(int arr[], int start, int end)
{
    int current = start;
    int lc = 2 * current + 1;
    int tmp = arr[current];
    for( ; lc <= end; lc = 2 * lc + 1)
    {
        // lc是左孩子，lc+1是右孩子
        if(lc < end && arr[lc] < arr[lc+1])
            lc++;
        
        if(tmp >= arr[lc])
            break;
        else 
        {
            // 交换值
            arr[current] = arr[lc];
            arr[lc] = tmp;
        }
        
    }
}

void HeapSort(int arr[], int n)
{
    for(int i = n / 2; i > 0; i--)
    {
        HeapAdjust(arr, i, n-1);
    }
}