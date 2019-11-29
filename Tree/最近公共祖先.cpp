// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先
#include<iostream>
#include<algorithm>
using namespace std;

typedef int ElemType;

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
    BiTNode(int data)
    {
        this->data = data;
        this->lchild = this->rchild = NULL;
    }
} BiTNode, *BiTree;

BiTNode* stack1[101];
BiTNode* stack2[101];
BiTNode* stack3[101];
int top1 = 0, top2, top3;

// 非递归的后序遍历
void Ancestor(BiTree T, int x, int y)
{
    BiTNode *p = T, *r = NULL; //r指向最近访问的结点
    while(p || top1 > 0)
    {
        if(p)
        {
            top1++;
            stack1[top1] = p;
            p = p -> lchild;
        }
        else
        {
            p = stack1[top1];
            if(p -> rchild && p -> rchild != r)
            {
                p = p -> rchild;
                top1++;
                stack1[top1] = p;
                p = p -> lchild;
            }
            else
            {
                p = stack1[top1];
                top1--;
                if(p->data == x) 
                {
                    for(int i = 1; i < 101; i++)
                        stack2[i] = stack1[i];
                    top2 = top1;
                    top2++;
                    stack2[top2] = p;
                }
                if(p->data == y)
                {
                    for(int i = 1; i < 101; i++)
                        stack3[i] = stack1[i];
                    top3 = top1;
                    top3++;
                    stack3[top3] = p;
                }
                r = p;
                p = NULL;
            }
        }
    }
    int result;
    for(int i = 1; i <= top2 && i <= top3; i++)
    {
        if(stack2[i]->data == stack3[i]->data)
        {
            result = stack2[i]->data;
        }
    }
    printf("%d", result);
}

void build(BiTNode* &T){
    int x;
    scanf("%d",&x);
    if(x==-1){
        T = NULL;
        return ;
    }else{
        T = new BiTNode(x);
        T->lchild = T->rchild = NULL;
        build(T->lchild);
        build(T->rchild);
    }
}

int main()
{
    BiTNode* node;
    build(node);
    
    int x, y;
    scanf("%d%d", &x,&y);
    Ancestor(node, x, y);

    return 0;
}