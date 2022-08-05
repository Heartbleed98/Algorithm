#include<vector>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
};

TreeNode* reverseEdge(TreeNode* node)
{
	TreeNode* pre = NULL;
	TreeNode* next = NULL;
	while (node != NULL)
	{
		next = node->right;
		node->right = pre;
		pre = node;
		node = next;
	}
	return pre;
}

void printEdge(vector<int>& res,TreeNode* node)
{
	TreeNode* tail = reverseEdge(node);
	TreeNode* cur = tail;
	while (cur != NULL)
	{
		res.push_back(cur->val);
		cur = cur->right;
	}
	reverseEdge(tail);
}

vector<int> posorderTraversal(TreeNode* root) 
{
	vector<int> res;
	TreeNode* pre = NULL;
	TreeNode* cur = root;
	while(cur != NULL)
	{
		if(cur->left != NULL)
		{
			pre = cur->left;
			while(pre->right != NULL && pre->right != cur)
				pre = pre->right;

			if(pre->right == NULL)
			{
				pre->right = cur;
				cur = cur->left;
			}
			else
			{
				pre->right = NULL;
				printEdge(res, cur->left);
				cur = cur->right;
			}  
		}
		else
		{
			cur = cur->right;
		}
	}
	printEdge(res, root);
	return res;
}



int main()
{
	TreeNode *root = new TreeNode(1, NULL, NULL);
	TreeNode *n2 = new TreeNode(2, NULL, NULL);
	TreeNode *n3 = new TreeNode(3, NULL, NULL);
	TreeNode *n4 = new TreeNode(4, NULL, NULL);
	TreeNode *n5 = new TreeNode(5, NULL, NULL);
	TreeNode *n6 = new TreeNode(6, NULL, NULL);
	TreeNode *n7 = new TreeNode(7, NULL, NULL);

	root->left = n2;
	root->right = n3;

	n2->left = n4;
	n2->right = n5;

	n3->left = n6;
	n3->right = n7;

	vector<int> res;
	res = posorderTraversal(root);

	for(int i = 0; i < res.size(); i++)
		printf("%d ", res[i]);

	return 0;
}