#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAXV = 1000;
vector<int> G[MAXV];
int inDegree[MAXV] = {0};
int n; //顶点数
int toposort[MAXV];

bool TopoSort()
{
    int num = 0; //记录加入拓扑序列的顶点数
    queue<int> q;
    for(int i = 0; i < n; i++)
    {
        if(inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    int node = 0;
    while(!q.empty())
    {
        int u = q.front();
        toposort[node++] = u;
        q.pop();
        for(int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            inDegree[v]--;
            if(inDegree[v] == 0)
            {
                q.push(v);
            }
        }
        // G[u].clear(); //可写可不写
        num++;
    }
    if(num == n)
        return true;
    else 
        return false;
}

int main()
{
    n = 8;

    G[7].push_back(0);
    G[7].push_back(5);
    G[7].push_back(6);
    G[4].push_back(5);
    G[3].push_back(7);
    G[3].push_back(4);
    G[2].push_back(7);
    G[1].push_back(4);
    G[1].push_back(6);

    for(int i = 0; i < MAXV; i++)
    {
        for(int j = 0; j < G[i].size(); j++)
        {
            inDegree[G[i][j]]++;
        }
    }

    if(TopoSort())
        for (int i = 0; i < n; i++) 
            printf("%d ",toposort[i]);
    else
        printf("The graph is not DAG which cannot be toposorted.");

    return 0;
}