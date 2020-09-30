https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?
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
    // 计算链表长度的函数
    int GetListLength(ListNode* head)
    {
        ListNode* cur=head;
        int count = 0;
        while(cur)
        {
            cur=cur->next;
            count++;
        }
        return count;
    }
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        // 若任一链表为空，直接返回空
        if(pHead1==nullptr||pHead2==nullptr)    return nullptr;
        
        // 计算两链表长度
        int length1 = GetListLength(pHead1);
        int length2 = GetListLength(pHead2);
        
        // 计算两链表长度差
        int step = abs(length1-length2);
        // 让长的先走长度差步
        if(length1>length2)
        {
            while(step>0)
            {
                pHead1=pHead1->next;
                --step;
            }
        }
        else
        {
            while(step>0)
            {
                pHead1=pHead1->next;
                --step;
            }
        }
        // 再让两链表同时走，当两链表不为空时，若两链表结点相同，则说明相交，返回这个节点
        while(pHead1!=nullptr && pHead2!=nullptr)
        {
            if(pHead1==pHead2)
            {
                return pHead1;
            }
            pHead1=pHead1->next;
            pHead2=pHead2->next;
        }
        // 若走到空还未遇到两链表的相同节点，则说明两链表未相交，返回空
        return nullptr;
    }
};