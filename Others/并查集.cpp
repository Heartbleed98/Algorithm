#include<iostream>
using namespace std;

const int N = 100;
int father[N];

int findFather(int x)
{
    //如果father[x] == x说明该结点是该集合的根结点
    while(x != father[x])
        x = father[x];
}

void Union(int a, int b)
{
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB)
        father[faA] = faB;
}

int main()
{
    //初始化
    for(int i = 1; i < N; i++)
        father[i] = i;
}