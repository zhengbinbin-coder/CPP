https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        //如果头为空，直接返回
        if(pListHead==nullptr)    return nullptr;
        //定义两个快慢指针
        ListNode* fast=pListHead;
        ListNode* slow=pListHead;
        //先让快指针走k步
        while(k&& fast)
        {
            fast=fast->next;
            --k;
        }
        //若k>0，说明快指针还没走完k步就已经到尾，直接返回
        if(k>0)    return nullptr;
        //再让快慢指针一起走，直到快指针走到尾
        while(fast)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};