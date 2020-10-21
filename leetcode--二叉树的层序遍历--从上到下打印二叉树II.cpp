https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 定义结果集
        vector<vector<int>> result;
        // 若根节点为空，直接返回
        if(root==nullptr)   return result;

        queue<TreeNode*> q1;        // 定义队列1用来按层遍历
        queue<TreeNode*> q2;        // 定义辅助队列2
        vector<int> v;              // 定义一个数组，保存每层遍历的结果
        q1.push(root);              // 先把树的根入进队列1
        while(!q1.empty())
        {
            int size=q1.size();     // 计算队列1中的元素个数(二叉树当前层的元素个数)
            // 遍历队列1内元素，将其结点的值挨个插入保存这层遍历结果的数组后释放
            for(int i = 0;i<size;++i)
            {
                TreeNode* father = q1.front();
                q1.pop();
                v.push_back(father->val);
                // 若遍历的这层的这个结点存在左孩子，则将它入队列2保存
                if(father->left)
                {
                    q2.push(father->left);
                } 
                // 若遍历的这层的这个结点存在右孩子，则将它入队列2保存   
                if(father->right)
                {
                    q2.push(father->right);
                }    
            }
            // 把保存这层遍历结果的数组插入到结果集中
            result.push_back(v);
            // 当辅助队列不为空时，把辅助队列中临时保存的元素再入到队列1中
            while(!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
            // 清空保存着当前层遍历结果的数组，以便保存下一层遍历结果
            v.clear();
        }
        return result;
    }
};