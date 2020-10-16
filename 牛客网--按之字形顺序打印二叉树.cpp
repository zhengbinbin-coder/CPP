https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> result;    // 定义结果集
        // 若树根为空，直接返回
        if(pRoot==nullptr)    return result;
        
        stack<TreeNode*> s;        // 定义一个栈，用来保存每层遍历的节点
        queue<TreeNode*> q;        // 定义一个辅助队列
        int flag = 1;              // 定义方向标志--1：从左向右遍历 2：从右向左遍历
        vector<int> v;             // 定义一个数组，保存每层遍历的结果
        s.push(pRoot);             // 先把树的根入进栈
        while(!s.empty())
        {
            int size = s.size();    // 计算栈内元素个数(二叉树当前层的元素个数)
            // 遍历当前栈内元素，将其结点的值挨个插入保存这层遍历结果的数组后释放
            for(int i = 0; i < size; ++i)
            {
                TreeNode* cur = s.top();
                s.pop();
                v.push_back(cur->val);
                // 若这层标志是从左向右，就先把当前结点的左孩子插进q，后把当前结点的右孩子插进q
                // 否则，就先把当前结点的左孩子插进q，后把当前结点的右孩子插进q
                TreeNode* first = (flag==1)?cur->left:cur->right;    // 定义先插的结点
                TreeNode* last = (flag==1)?cur->right:cur->left;     // 定义后插的结点
                if(first!=nullptr)    q.push(first);
                if(last!=nullptr)    q.push(last);
            }
            result.push_back(v);        // 把保存这层遍历结果的数组插入到结果集中
            // 当q不为空时，再把q结点插入栈中
            // 整体相当于：若上层从左向右遍历，这层从左向右插入上层的子节点，pop时就可以从右向左遍历
            //           若上层从右向左遍历，这层从右向左插入上层的子节点，pop时就可以从左向右遍历
            while(!q.empty())
            {
                s.push(q.front());
                q.pop();
            }
            // 改变方向标志
            flag=(flag==1)?2:1;
            // 清空保存着当前层遍历结果的数组，以便保存下一层遍历结果
            v.clear();
        }
        return result;
    }
};