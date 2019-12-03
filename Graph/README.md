# **Graph**

## 图的表示
### 邻接矩阵 
```C
const int MAXV = 100;
int matrix[MAXV][MAXV];

scanf("%d%d%d", &vertex_num,&edge_num, &source);
fill(matrix[0], matrix[0] + MAXV * MAXV, INT_MAX);
int a, b, z;
printf("请输入各边的边的信息（所连的顶点和权数）：\n");
for(int i=0;i<edge_num;i++)
{
    scanf("%d%d%d", &a,&b,&z);
    matrix[a][b] = matrix[b][a] = z;
}
```
### 邻接表
```C
// 方法一，使用vector
struct Node 
{
    int v; //边的终点编号
    int w; //边权
    Node(int _v, int _w) : v(_v), w(_w) {} //构造函数
};

vector<Node> Adj[vertex_num]; 

Adj[1].push_back(Node(3, 4)); //添加1->3权值为4的边
```

```C
//方法二，使用list
class Graph 
{ 
    int V;    // No. of vertices 
  
    // Pointer to an array containing 
    // adjacency lists 
    list<int> *adj; 
   
public: 
    Graph(int V);   // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int v, int w); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
```

## Dijkstra Algorithm 
### 思路：
1. 对图G(V,E)设计集合S（用bool数组visited[]表示），存放已访问的顶点，然后每次从集合V-S（未访问的顶点）选择与起点source的最短距离最小的一个顶点（记为u），访问并加入集合S。
2. 之后令顶点u为中介点，优化起点source与所有从u能到达的顶点v之间的最短距离。这样的操作执行n次，直到集合S包含所有顶点。
3. 设置数组path[]，令path[v]表示从起点s到顶点v的最短路径上v的前一个顶点（前驱节点）的编号。
4. 使用递归的方式输出路径

### 复杂度：O(n^2)

## Topological Sorting（拓扑排序）
### 思路：
1. 定义队列q，并把所有入度为0的结点加入队列。
2. 取队首结点。然后山区所有从它出发得便，并令这些边到达的顶点的入度减1，如果某个顶点入度减为0则加入队列。
3. 反复进行2操作，直至队列为空。如果加入到拓扑排序的顶点数等于图的顶点数则排序成功；反之排序失败，图中有环。

### 复杂度：O(V+E)
