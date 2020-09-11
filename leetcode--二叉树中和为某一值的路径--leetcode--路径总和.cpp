
https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/submissions/

https://leetcode-cn.com/problems/path-sum-ii/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void pathSumDFS(TreeNode* root, int sum,vector<vector<int>>& result,vector<int>& v)
    {
        // 若某条路径已经走到空，return
        if(root==nullptr)   return;

        v.push_back(root->val);     // 添加节点值到待选结果中
        sum-=root->val;             // 将给定值减去所添加的节点值

        // 若节点已经走到叶子，并且给定值已经减到0，说明此路径符合要求，将此待选结果添加到结果集中
        if(root->left==nullptr && root->right==nullptr && sum==0)
        {
            result.push_back(v);
        }

        // 深度优先遍历
        pathSumDFS(root->left,sum,result,v);
        pathSumDFS(root->right,sum,result,v);

        // 回退一步，继续遍历下一条路径
        v.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        // 回溯法
        vector<vector<int>> result;     // 定义结果集
        vector<int> v;                  // 定义待选结果
        pathSumDFS(root,sum,result,v);
        return result;
    }
};