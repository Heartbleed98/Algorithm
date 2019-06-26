#include<iostream>
#include<queue>
using namespace std;

const int MAXV = 1000;
const int INF = 1000000000;
int n, matrix[MAXV][MAXV];
bool inqueue[MAXV] = {false};

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v = 0; v < n; v++)
        {
            if(inqueue[v] == false && matrix[u][v] != INF)
            {
                q.push(v);
                inqueue[v] = true;
            }
        }
    }
}

// 如果给定的图是一个连通图，则此步不需要做
void BFSTrave()
{
    for(int u = 0; u < n; u++)
        if(inqueue[u] == false)
            BFS(u); // 访问u所在的连通块
}