// 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

#include <iostream>
#include <vector>
#include <map>


using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {

        if(pHead == nullptr)
            return nullptr;
        
        ListNode* node1 = pHead;
        ListNode* node2 = pHead->next;
        
        while(node1->next)
        {
            node1 = node1->next;
            if(node2->next && node2->next->next)
                node2 = node2->next->next;
            else
                return nullptr;
            if(node1 == node2);
        }

        return nullptr;
    }
};

int main()
{
    map<ListNode*, int> im;
    cout << im[1] << endl;
    return 0;
}