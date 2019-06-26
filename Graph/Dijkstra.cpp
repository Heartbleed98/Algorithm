#include<iostream>
#include<cstring>
using namespace std;

const int INF = 1000000000;
const int MAXV = 1000;
int matrix[MAXV][MAXV];
bool visited[MAXV] = { false };
int dist[MAXV];
int path[MAXV];
int source, vertex_num, edge_num;

void Dijkstra(int);
void printPath(int);

int main() 
{
	scanf("%d%d%d", &vertex_num,&edge_num, &source);
	//矩阵的初始化
	fill(matrix[0], matrix[0] + MAXV * MAXV, INF);
	int a, b, z;
	cout <<"Please enter info:"<< endl;
	for(int i=0;i<edge_num;i++)
	{
		scanf("%d%d%d", &a,&b,&z);
		matrix[a][b] = matrix[b][a] = z;
	}

	Dijkstra(source);

	for (int i = 0; i < vertex_num; i++)
	{
		if (i != source)
		{
			printf("%d to %d shortest path length is: %d, the path is: ", source, i, dist[i]);
			printPath(i);
			printf("\n");
		}
	}

	return 0;
}

void Dijkstra(int source) 
{
	fill(dist, dist + MAXV, INF);
  	dist[source] = 0;	

	for(int i = 0; i < vertex_num; i++) 
		path[i] = i;

	for (int i = 1; i < vertex_num; i++)
	{
		int u = -1, min = INF; 
		for (int j = 0; j < vertex_num; j++)
		{
			if (visited[j] == false && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		}

		if(min == -1) return;
		visited[u] = true;

		for (int j = 0; j < vertex_num; j++)
		{
			if (visited[j] == false &&
				matrix[u][j] != INF &&
				matrix[u][j] + dist[u] < dist[j])
			{
				dist[j] = matrix[u][j] + dist[u];
				path[j] = u;
			}
		}
	}
}

void printPath(int v) {
    if(v == source) {
        printf("%d ", v);
        return ;
    }
    printPath(path[v]);
    printf("%d ", v);
}

