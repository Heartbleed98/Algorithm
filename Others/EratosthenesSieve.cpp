//埃氏筛法，复杂度O(n * log log n)
#include<iostream>
using namespace std;

const int MAXV = 101;
int prime[MAXV], pNum = 0;
bool p[MAXV] = {false};

void FindPrime()
{
    for(int i = 2; i < MAXV; i++)
    {
        if(p[i] == false) //没有被筛去说明是素数
        {
            prime[pNum++] = i;
            for(int j = i + i; j < MAXV; j += i)
                p[j] = true;
        }
    }
}

int main()
{
    FindPrime();
    for(int i = 0; i < pNum; i++)
        printf("%d ", prime[i]);
    return 0;
}