#include<iostream>
#include<cstring>
using namespace std;

const int MAXV = 100;
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
	//����ĳ�ʼ��
	fill(matrix[0], matrix[0] + MAXV * MAXV, INT_MAX);
	int a, b, z;
	cout << "��������ߵıߵ���Ϣ�������Ķ����Ȩ������" << endl;
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
            printf("%d��%d����̾����ǣ�%d��·���ǣ�", source, i, dist[i]);
            printPath(i);
            printf("\n");
		}
	}

	return 0;
}

void Dijkstra(int source) 
{
	visited[source] = true;

	for (int i = 0; i < vertex_num; i++)
	{
		dist[i] = matrix[source][i];
		path[i] = source;
	}

	int min_cost;//��СȨֵ
	int min_cost_index;//��СȨֵ���±�

	for (int i = 1; i < vertex_num; i++)
	{
		min_cost = INT_MAX;
		for (int j = 0; j < vertex_num; j++)
		{
			if (visited[j] == false && dist[j] < min_cost)
			{
				min_cost = dist[j];
				min_cost_index = j;
			}
		}

		visited[min_cost_index] = true;

		for (int j = 0; j < vertex_num; j++)
		{
			if (visited[j] == false &&
				matrix[min_cost_index][j] != INT_MAX&&
				matrix[min_cost_index][j] + min_cost < dist[j])
			{
				dist[j] = matrix[min_cost_index][j] + min_cost;
				path[j] = min_cost_index;
			}
		}
	}
}

void printPath(int i)
{
    int tmp = source;
    if(i == source)
    {
        printf("%d ", source);
        return;
    }
    printPath(path[i]);
    printf("%d ", i);
}

