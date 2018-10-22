// 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
// 重复的结点不保留，返回链表头指针。
// 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

#include <vector>
#include <map>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    { 
        map<int, int> record;
        ListNode* node = pHead;
        while(node)
        {
            record[node->val]++;
            node = node->next;
        }

        ListNode* pre = nullptr;
        ListNode* cur = pHead;
        ListNode* nHead = pHead;

        while(cur)
        {
            ListNode* next = cur->next;
            if(record[cur->val]>1)
            {
                if(pre)
                    pre->next = next;
                else
                    nHead = next;

                delete cur;
            }
            else
                pre = cur;
            cur = next;
        }

        return nHead;
    }    
};

int main()
{
    ListNode* p = new ListNode(1);
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(5);
    ListNode* p4 = new ListNode(3);
    p->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = nullptr;

    Solution s;
    ListNode* pHead = s.deleteDuplication(p);

    while(pHead)
    {
        cout << pHead->val << endl;
        pHead = pHead->next;
    }

    return 0;
    
}