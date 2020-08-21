https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

class Solution {
public:
    bool IsSameTree(TreeNode* p1, TreeNode* p2)
    {
        // 若p2已经比较完了，说明p2是p1的子树
        if(p2==nullptr)    return true;
        
        // 若p1已经比较完，说明p2比p1大，不是p1的子树
        if(p1==nullptr)    return false;
        
        // 若两节点值不同，则返回false
        if(p1->val!=p2->val)    return false;
        
        // 分别比较p1和p2的左子树、p1和p2的右子树是否相等
        return IsSameTree(p1->left, p2->left) && IsSameTree(p1->right, p2->right);
    }
    
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        // 根据题意，若两树任一为空，则返回false
        if(pRoot1==nullptr||pRoot2==nullptr)    return false;
        
        bool result=false;
        // 若p1的根=p2的根，判断它们是否是相同树
        if(pRoot1->val==pRoot2->val)
        {
            result=IsSameTree(pRoot1,pRoot2);
        }
        // 若不是，判断p1的左子树中是否包含p2
        if(result!=true)
        {
            result=HasSubtree(pRoot1->left,pRoot2);
        }
        // 若不是，判断p1的右子树中是否包含p2
        if(result!=true)
        {
            result=HasSubtree(pRoot1->right,pRoot2);
        }
        return result;
    }
};