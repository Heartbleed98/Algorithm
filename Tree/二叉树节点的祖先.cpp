// 输出一棵二叉树的节点的所有祖先
#include<iostream>
using namespace std;

typedef struct BiTNode{
    int data;
    BiTNode *lchild, *rchild;
} BiTNode;

BiTNode* stack1[101];
int top1 = 0;
BiTNode* node;

// 按照先序顺序输入一棵二叉树
void build(BiTNode* &T){
    int x;
    scanf("%d",&x);
    if(x==-1){
        T = NULL;
        return ;
    }else{
        T = new BiTNode;
        T->data = x;
        T->lchild = T->rchild = NULL;
        build(T->lchild);
        build(T->rchild);
    }
}

// 非递归的后序遍历
void Ancestor(BiTNode *T, int x)
{
    BiTNode *p = T, *r = NULL; //r指向最近访问的结点
    while(p || top1 > 0)
    {
        if(p)
        {
            stack1[++top1] = p;
            p = p -> lchild;
        }
        else
        {
            p = stack1[top1];
            if(p -> rchild && p -> rchild != r)
            {
                p = p -> rchild;
                stack1[++top1] = p;
                p = p -> lchild;
            }
            else
            {
                p = stack1[top1--];
                if(p->data == x)
                {
                    if(p == node)
                        printf("No Ancestor!");
                    int i = 1;
                    while(i <= top1)
                    {
                        printf("%d ", stack1[i]->data);
                        i++;
                    }
                    exit(0);
                }
                r = p;
                p = NULL;
            }
        }
    }
}

int main()
{
    build(node);
    int x;
    scanf("%d", &x);
    Ancestor(node , x);
    printf("No Node!");
    return 0;
}