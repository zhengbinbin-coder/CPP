
https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
https://leetcode-cn.com/problems/merge-two-sorted-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // //1.一个一个节点的归并
        // if(l1==nullptr) return l2;
        // if(l2==nullptr) return l1;

        // //定义新链表的头和尾
        // ListNode* head = nullptr;
        // ListNode* end = nullptr;

        // //两个链表都不为空时，进行归并
        // while(l1 && l2)
        // {
        //     //挑出两链表中较小的头
        //     ListNode* p = nullptr;
        //     if(l1->val > l2->val)   p=l2;
        //     else                    p=l1;
            
        //     //使较小的头指向下一个节点(删除较小的头)
        //     if(p==l1)               l1=l1->next;
        //     else                    l2=l2->next;

        //     //插入节点p到新链表
        //     if(head==nullptr)
        //     {
        //         head=p;
        //         end=p;
        //     }
        //     else
        //     {
        //         end->next=p;
        //         end=end->next;
        //     }
        // }

        // //走到这里时，pHead1可能为空，pHead2可能为空
        // if(l1==nullptr)             end->next=l2;   //链表1为空时，把链表2剩下的节点整体链到新链表上
        // else                        end->next=l1;   //链表2为空时，把链表1剩下的节点整体链到新链表上

        // //返回新链表的头
        // return head;

        //2.递归
        //递归的出口
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;

        //找到两个链表中较小的节点放入head中，再删除原链表中那个节点
        ListNode* head = nullptr;
        if(l1->val > l2->val)
        {
            head=l2;
            l2=l2->next;
        }
        else
        {
            head=l1;
            l1=l1->next;
        }

        //问题规模已缩小了一个节点，接着递归调用即可
        head->next = mergeTwoLists(l1, l2);
        return head;
    }
};