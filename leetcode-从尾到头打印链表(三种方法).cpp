https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// // 把链表中的值入栈，再出栈放入数组中
// class Solution {
// public:
//     vector<int> reversePrint(ListNode* head) {
//         stack<int> s;
//         while(head)
//         {
//             s.push(head->val);
//             head=head->next;
//         }
//         vector<int> v;
//         while(!s.empty())
//         {
//             v.push_back(s.top());
//             s.pop();
//         }
//         return v;
//     }
// };

// // 把链表元素放入数组，逆置数组
// class Solution {
// public:
//     vector<int> reversePrint(ListNode* head) {
//         vector<int> v;
//         while(head)
//         {
//             v.push_back(head->val);
//             head=head->next;
//         }
//         reverse(v.begin(),v.end());
//         return v;
//     }
// };

// 递归
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> v;
        //递归
        reversePrint_rec(head,v);
        return v;
    }
    void reversePrint_rec(ListNode* head,vector<int> &v)
    {
        if(head==nullptr)   return;
        reversePrint_rec(head->next,v);
        v.push_back(head->val);
    }
};