#include<iostream>

const int MAXV = 1000;

int n, matrix[MAXV][MAXV];
bool visited[MAXV] = {false};

void DFS(int u, int depth)
{
    visited[u] = true;
    for(int v = 0; v < n; v++)
    {
        if(visited[v] == false && matrix[u][v] != INT_MAX)
            DFS(v, depth + 1);
    }
}

void DFSTrave()
{
    for(int u = 0; u < n; u++)
    {
        if(visited[u] == false)
            DFS(u, 1);
    }
}