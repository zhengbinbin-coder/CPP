https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
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
    vector<int> levelOrder(TreeNode* root) {
        if(root==nullptr)
        {
            return vector<int>();
        }
        // 定义一个返回数组
        vector<int>v;
        // 定义一个辅助队列
        queue<TreeNode*> q;
        // 先将根节点入队
        q.push(root);
        // 当队列不空时，将队头节点出队，将数据插入返回数组，如果出队的结点有左孩子就插入队尾，有右孩子也插入队尾
        while(!q.empty())
        {
            TreeNode* father=q.front();
            q.pop();
            v.push_back(father->val);
            if(father->left)
            {
                q.push(father->left);
            }
            if(father->right)
            {
                q.push(father->right);
            }
        }
        return v;
    }
};