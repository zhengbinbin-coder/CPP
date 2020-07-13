/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

typedef struct ListNode ListNode;
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> s;
        ListNode* pHead = head;
        int num=0;
        while(pHead!=NULL)
        {
            s.push(pHead->val);
            pHead=pHead->next;
            num++;
        }

        vector<int> v(num);
        int i=0;
        while(!s.empty())
        {
            v[i]=s.top();
            s.pop();
            i++;
        }
        return v;
    }
};
