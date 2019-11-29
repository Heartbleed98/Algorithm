// 求一棵二叉树的直径
// 二叉树的直径是指二叉树中相距最远的两个点的距离
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct BtNode {
     int val;
     BtNode *lchild;
     BtNode *rchild;
};

int lheight, rheight;

void build(BtNode* &T){
    int x;
    scanf("%d",&x);
    if(x==-1){
        T = NULL;
        return ;
    }else{
        T = new BtNode;
        T->val = x;
        T->lchild = T->rchild = NULL;
        build(T->lchild);
        build(T->rchild);
    }
}

int height(BtNode* T)
{
    if(T == NULL)
        return 0;
    lheight = height(T->lchild);
    rheight = height(T->rchild);
    if(lheight > rheight)
        return lheight+1;
    else
        return rheight+1;
}

int maxDist(BtNode* T)
{
    if(T == NULL)
        return 0;
    int lh = height(T->lchild);
    int rh = height(T->rchild);
    int ldist = maxDist(T->lchild);
    int rdist = maxDist(T->rchild);
    int dist = lh + rh; 
    int Max = max(ldist, rdist);
    return max(dist, Max);
}

int main()
{
    BtNode* T = NULL;
    build(T);
    
    cout<<maxDist(T)<<endl;

    return 0;
}