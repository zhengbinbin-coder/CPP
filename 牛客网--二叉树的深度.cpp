https://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b?
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
    int TreeDepth(TreeNode* pRoot)
    {
        // 递归最简版本
        /*
        if(pRoot==nullptr)    return 0;
        return 1+ max(TreeDepth(pRoot->left),TreeDepth(pRoot->right));
        */
        
        /* 
        //递归
        // 将初始深度置为0
        int depth=0;
        // 递归出口，若当前根为空，返回0
        if(pRoot==nullptr)
        {
            return 0;
        }
        // 若当前根不为空，高度设为1
        if(pRoot!=nullptr)
        {
            depth =1;
        }
        // 递归求左子树高度和右子树高度
        int LeftDepth = TreeDepth(pRoot->left);
        int RightDepth = TreeDepth(pRoot->right);
        // 返回左右子树高度中较大的+1
        return LeftDepth > RightDepth ? depth+LeftDepth : depth+RightDepth;
        */
        
        // 层序遍历，每过一层深度+1
        if(pRoot==nullptr)    return 0;
        
        queue<TreeNode*> q;    // q里永远只保存一层
        q.push(pRoot);
        int depth = 0;
        while(!q.empty())
        {
            int size = q.size();    // 记录当前层的元素个数
            // for循环只处理一层，因此深度应该放在for循环外面、while里面++
            depth++;
            // 把当前层的节点依次pop，并把它们的子节点依次入队
            for(int i = 0; i<size; ++i)
            {
                TreeNode* root = q.front();
                q.pop();
                if(root->left != nullptr)    q.push(root->left);
                if(root->right != nullptr)    q.push(root->right);
            }
        }
        return depth;
    }
};