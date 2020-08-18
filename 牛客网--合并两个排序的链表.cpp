https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

/*
//1.一个一个节点的归并
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==nullptr)    return pHead2;
        if(pHead2==nullptr)    return pHead1;
        //定义新链表的头和尾
        ListNode* new_head=nullptr;
        ListNode* new_end=nullptr;
        while(pHead1 && pHead2)
        {
            //挑出两链表中较小的头
            ListNode* p = pHead1->val > pHead2->val ? pHead2 : pHead1;
            //使较小的头指向下一个节点(删除较小的头)
            p == pHead1 ? pHead1 = pHead1->next : pHead2 = pHead2->next;
            //插入节点p到新链表
            if(new_head==nullptr)
            {
                new_head=p;
                new_end=p;
            }
            else
            {
                new_end->next=p;
                new_end=new_end->next;
            }
        }
        //走到这里时，pHead1可能为空，pHead2可能为空
        if(pHead1==nullptr)
        {
            new_end->next=pHead2;    //链表1为空时，把链表2剩下的节点整体链到新链表上
        }
        else
        {
            new_end->next=pHead1;    //链表2为空时，把链表1剩下的节点整体链到新链表上
        }
        return new_head;    //返回新链表的头
    }
};
*/

//2.递归
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        //递归出口
        if(pHead1==nullptr)    return pHead2;
        if(pHead2==nullptr)    return pHead1;
        
        //找到两个链表中较小的节点放入head中，再删除原链表中那个节点
        ListNode* head=nullptr;					
        if(pHead1->val > pHead2->val)
        {
            head=pHead2;
            pHead2=pHead2->next;
        }
        else
        {
            head=pHead1;
            pHead1=pHead1->next;
        }
        head->next = Merge(pHead1, pHead2);
        return head;
    }
};