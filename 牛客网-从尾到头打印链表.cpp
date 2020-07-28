https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
/*
// 把链表中的值入栈，再出栈放入数组中
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> s;
        while(head)
        {
            s.push(head->val);
            head=head->next;
        }
        vector<int> v;
        while(!s.empty())
        {
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
};
*/

/*
// 把链表元素放入数组，逆置数组
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        while(head)
        {
            v.push_back(head->val);
            head=head->next;
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
*/

// 递归
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        //递归
        printListFromTailToHead_rec(head,v);
        return v;
    }
    void printListFromTailToHead_rec(ListNode* head,vector<int> &v)
    {
        if(head==nullptr)   return;
        printListFromTailToHead_rec(head->next,v);
        v.push_back(head->val);
    }
};