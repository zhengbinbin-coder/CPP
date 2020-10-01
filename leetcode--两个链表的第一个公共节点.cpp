https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // 计算链表长度的函数  
    int GetListLength(ListNode* head)
    {
        ListNode* cur=head;
        int count =0;
        while(cur)
        {
            cur=cur->next;
            count++;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 若任一链表为空，直接返回空
        if(headA==nullptr || headB==nullptr)    return nullptr;
        // 计算两链表长度
        int len1=GetListLength(headA);
        int len2=GetListLength(headB);
        // 计算两链表长度差
        int step = abs(len1-len2);
        // 让长的先走长度差步
        if(len1>len2)
        {
            while(step)
            {
                headA=headA->next;
                --step;
            }
        }
        else
        {
            while(step)
            {
                headB=headB->next;
                --step;
            }
        }
        // 再让两链表同时走，当两链表不为空时，若两链表结点相同，则说明相交，返回这个节点
        while(headA!=nullptr && headB!=nullptr)
        {
            if(headA==headB)
            {
                return headA;
            }
            headA=headA->next;
            headB=headB->next;
        }
        // 若走到空还未遇到两链表的相同节点，则说明两链表未相交，返回空
        return nullptr;
    }
};
