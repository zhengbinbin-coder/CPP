https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        //若两个序列长度不相等，或任一序列为空，直接返回
        if(pre.size()!=vin.size()||pre.empty())    return nullptr;
        return reConstructBinaryTree_rec(pre,0,pre.size()-1,vin,0,vin.size()-1);
    }
    TreeNode* reConstructBinaryTree_rec(vector<int> pre,int pre_start,int pre_end,
                                        vector<int> vin,int vin_start,int vin_end)
    {
        //递归的出口，若前序开始>末尾 或者 中序开始 > 末尾，就结束递归
        if(pre_start > pre_end || vin_start > vin_end)    return nullptr;
        //创建根结点
        TreeNode* root = new TreeNode(pre[pre_start]);
        //在中序序列寻找根节点
        for(auto i = vin_start; i <= vin_end; ++i)
        {
            if(pre[pre_start] == vin[i])    //说明已在中序序列中找到根节点--[vin_start,i) i [i+1,vin_end]
            {
                root->left = reConstructBinaryTree_rec(pre,pre_start+1,pre_start+i-vin_start,vin,vin_start,i-1);
                root->right = reConstructBinaryTree_rec(pre,pre_start+i-vin_start+1,pre_end,vin,i+1,vin_end);
                break;
            }
        }
        return root;
    }
};
