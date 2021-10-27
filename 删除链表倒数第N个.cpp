#include"global.h"

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}  
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* FastPoint = head;
        ListNode* SlowPoint = head;
        while (FastPoint != nullptr)
        {
            FastPoint = FastPoint->next;

            count++;
            if (count > n + 1)
            {
                SlowPoint = SlowPoint->next;
            }
        }
        cout << "SlowPoint : " << SlowPoint->val;
        if (SlowPoint->next == nullptr)
        {
            head = nullptr;
        }
        else if (SlowPoint->next != nullptr && SlowPoint->next->next != nullptr)
        {
            SlowPoint->next = SlowPoint->next->next;
        }
        else
        {
            SlowPoint->next = nullptr;
        }
        return head;
    }
};

ListNode* GetListNode(int n)
{
    ListNode* head = new ListNode;
    head->val = 0;
    ListNode* rhead = head;
    for (int i = 1; i < n; i++)
    {
        ListNode* temp = new ListNode;
        temp->val = i;
        head->next = temp;
        head = head->next;
    }
    return rhead;
    
}
int main()
{
    ListNode* head = GetListNode(2);
    Solution().removeNthFromEnd(head, 1);
}