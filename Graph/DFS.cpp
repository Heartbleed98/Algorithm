const int MAXV = 1000;
const int INF = 1000000000;
int n, matrix[MAXV][MAXV];
bool visited[MAXV] = {false};

void DFS(int u, int depth)
{
    visited[u] = true;
    for(int v = 0; v < n; v++)
    {
        if(visited[v] == false && matrix[u][v] != INF)
            DFS(v, depth + 1);
    }
}

// 如果给定的图是一个连通图，则此步不需要做
void DFSTrave()
{
    for(int u = 0; u < n; u++)
    {
        if(visited[u] == false)
            DFS(u, 1); // 访问u所在的连通块
    }
}