https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?
class Solution {
public:
    bool _VerifySquenceOfBST(vector<int> sequence,int begin,int end)
    {
        // 递归出口--当范围缩小到空或者只有一个元素时，可认为满足二叉搜索树
        if(begin>=end)
        {
            return true;
        }
        
        // 后序遍历根节点为后序序列最后一个元素
        int root=sequence[end];
        int i=0;
        
        // 从第0个元素开始找到根结点处，只要小于根节点就是它的左子树
        while(i<end && sequence[i]<root)
        {
            ++i;
        }
        
        // 从左子树的下一个节点开始找到根结点处，全是右子树序列，只要有一个节点<根节点，就不满足二叉搜索树
        for(int j=i;j<end;++j)
        {
            if(sequence[j]<root)
            {
                return false;
            }
        }
        // 递归判断左右子树序列
        return _VerifySquenceOfBST(sequence,begin,i-1) && _VerifySquenceOfBST(sequence,i,end-1);
    }
    
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() == 0)
        {
            return false;
        }
        return _VerifySquenceOfBST(sequence,0,sequence.size()-1);
    }
};