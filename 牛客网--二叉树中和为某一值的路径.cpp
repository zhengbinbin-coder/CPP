https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?
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
    void FindPathDFS(TreeNode* root,int expectNumber,vector<vector<int>>& result,vector<int>& v)
    {
        // 若某条路径已经走到空，return
        if(root==nullptr)    return;
        
        v.push_back(root->val);     // 添加节点值到待选结果中
        expectNumber-=root->val;    // 将给定值减去所添加的节点值
        
        // 若节点已经走到叶子，并且给定值已经减到0，说明此路径符合要求，将此待选结果添加到结果集中
        if(root->left==nullptr && root->right==nullptr && expectNumber==0)
        {
            result.push_back(v);
        }
        
        // 深度优先遍历
        FindPathDFS(root->left,expectNumber,result,v);
        FindPathDFS(root->right,expectNumber,result,v);
        
        // 回退一步，继续遍历下一条路径
        v.pop_back();
    }
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        // 回溯法
        vector<vector<int>> result;    // 定义结果集
        vector<int> v;                 // 定义待选结果
        FindPathDFS(root,expectNumber,result,v);
        return result;
    }
};