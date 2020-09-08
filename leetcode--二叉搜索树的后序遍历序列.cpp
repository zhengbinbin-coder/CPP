https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
class Solution {
public:
    bool _verifyPostorder(vector<int>& postorder,int begin,int end)
    {
        // 递归出口--当范围缩小到空或者只有一个元素时，可认为满足二叉搜索树
        if(begin>=end)
        {
            return true;
        }

        // 后序遍历根节点为后序序列最后一个元素
        int root=postorder[end];

        // 从第0个元素开始找到根结点处，只要小于根节点就是它的左子树
        int i=0;
        while(i<end && postorder[i]<root)
        {
            ++i;
        }

        // 从左子树的下一个节点开始找到根结点处，全是右子树序列，只要有一个节点<根节点，就不满足二叉搜索树
        for(int j=i;j<end;++j)
        {
            if(postorder[j]<root)
            {
                return false;
            }
        }

        // 递归判断左右子树序列
        return _verifyPostorder(postorder,begin,i-1) && _verifyPostorder(postorder,i,end-1);
    }
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.empty())
        {
            return true;
        }
        return _verifyPostorder(postorder,0,postorder.size()-1);
    }
};