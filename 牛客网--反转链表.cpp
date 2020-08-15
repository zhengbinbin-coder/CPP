https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?
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
    ListNode* ReverseList(ListNode* pHead) {
        /*
        //1.定义三个指针，整体右移，边移动，边翻转，保证不会断链。
        //如果链表为空或只有一个节点，直接返回第一个节点
        if(pHead==nullptr||pHead->next==nullptr)    return pHead;
        //到这里说明至少有两个节点
        ListNode* first = pHead;            //指向第一个节点
        ListNode* second = pHead->next;     //指向第二个节点
        ListNode* third = second->next;     //指向第三个节点，有可能为空
        //third在最前面，只需判断它是否合法
        while(third)
        {
            //翻转
            second->next=first;
            //将三个指针整体向后移
            first=second;
            second=third;
            third=third->next;
        }
        //到这里时，third指向空，最后一个节点并未翻转
        second->next=first;
        //最开始的头变为了尾，但并未置空
        pHead->next=nullptr;
        //second变为了头，返回second
        return second;
        */
        
        //2.头插反转
        //如果链表为空或只有一个节点，直接返回第一个节点
        if(pHead==nullptr||pHead->next==nullptr)    return pHead;
        //创建一个新链表
        ListNode* new_head=nullptr;
        while(pHead)
        {
            //把原链表第一个节点拿下来
            ListNode* p=pHead;
            pHead=pHead->next;
            //把节点头插到新链表
            p->next=new_head;
            new_head=p;
        }
        return new_head;
    }
};