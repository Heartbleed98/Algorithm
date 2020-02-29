//欧拉筛法，复杂度O(n)
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
            prime[pNum++] = i;
        for(int j = 0; j < pNum && i * prime[j] < MAXV; j++)
        {
            p[i * prime[j]] = true;
            if(i % prime[j] == 0) //说明i之前被prime[j]筛选过了，此时的prime[j]一定是i的最小质因子
                break;
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