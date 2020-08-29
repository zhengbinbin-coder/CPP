https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==nullptr)    return pHead;
        
        // 考虑到有可能全部相同，构建一个头节点
        ListNode* head=new ListNode(0);
        head->next=pHead;
        
        // 定义快慢指针
        ListNode* slow=head;
        ListNode* fast=slow->next;
        while(fast!=nullptr)    // 当快指针不为空时，进入循环
        {
            // 当快指针的后一个节点不为空，并且快指针后一个节点的值不等于快指针的值时，快慢指针整体后移
            while(fast->next!=nullptr && fast->val!=fast->next->val)
            {
                slow=slow->next;
                fast=fast->next;
            }
            // 当快指针的后一个节点不为空，并且快指针后一个节点的值等于快指针的值时，快指针后移
            while(fast->next!=nullptr && fast->val==fast->next->val)
            {
                fast=fast->next;
            }
            //走到这里结果一共有三种,slow永远指向的是前驱有效节点：
            //1. fast->next != nullptr && (slow, fast] 限定了一段重复范围，此时进行去重
            //2. fast->next == nullptr && (slow, fast] 限定了一段重复范围，此时进行去重，最后相当于slow->next = nullptr
            //3. fast->next == nullptr && slow->next == fast,这说明从本次循环开始所有元素都不相同，这就不需要进行去重，是特殊情况
            if(slow->next!=fast)
            {
                slow->next=fast->next;    // 去重
            }
            fast=fast->next;    // 继续向后找
        }
        return head->next;
    }
};