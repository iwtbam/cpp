// 输入两个链表，找出它们的第一个公共结点。

#include <iostream>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {

        
        if(pHead1==nullptr || pHead2 == nullptr)
            return nullptr;

        int len1 = 1, len2 = 1;

        ListNode* node1 = pHead1; 
        ListNode* node2 = pHead2;

        while((node1 = node1->next) && len1++);
        while((node2 = node2->next) && len2++);

      
        node1 = pHead1;
        node2 = pHead2;
        

        int k = len1 - len2;

        if(k > 0)
            while(k-- && (node1 = node1->next));
        else
            while(k++ && (node2 = node2->next));

        if(node1 == node2)
            return node1;

        while((node1 = node1->next) != (node2 = node2->next));
        return node1;       
    }
};