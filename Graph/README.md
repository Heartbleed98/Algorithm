# **Graph**

## 图的表示
```C
// 邻接矩阵表示
const int MAXV = 100;
int matrix[MAXV][MAXV];

scanf("%d%d%d", &vertex_num,&edge_num, &source);
fill(matrix[0], matrix[0] + MAXV * MAXV, INT_MAX);
int a, b, z;
cout << "请输入各边的边的信息（所连的顶点和权数）：" << endl;
for(int i=0;i<edge_num;i++)
{
    scanf("%d%d%d", &a,&b,&z);
    matrix[a][b] = matrix[b][a] = z;
}
```

## Dijkstra Algorithm 
**基本思路：**
1. 对图G(V,E)设计集合S（用bool数组visited[]表示），存放已访问的顶点，然后每次从集合V-S（为访问的顶点）选择与起点source的最短距离最小的一个顶点（记为u），访问并加入集合S。
2. 之后令顶点u为中介点，优化起点source与所有从u能到达的顶点v之间的最短距离。这样的操作执行n次，知道集合S包含所有顶点。
3. 设置数组path[]，令path[v]表示从起点s到顶点v的最短路径上v的前一个顶点（前驱节点）的编号。
4. 使用递归的方式输出路径

**复杂度O(n^2)**