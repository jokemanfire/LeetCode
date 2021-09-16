#include"global.h"

 struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* first = head->next;
        ListNode* pre = head;
        ListNode* now = head->next;
        exchange(nullptr,pre);
        return first;
    }
    void exchange(ListNode * prepre,ListNode* pre)
    {
        ListNode* now = pre->next;
        if (now == nullptr)
            return;
        else
        {
            ListNode* Next = now->next;
            pre->next = Next;
            now->next = pre;
            if (prepre != nullptr)
                prepre->next = now;
            exchange(pre,Next);
        }
    }
};

void ListNode_init( ListNode * head,vector<int> & data)
{
    for (int i = 0; i < data.size(); i++)
    {
        head->val = data[i];
        ListNode* Next = new ListNode;
        head->next = Next;
        head = Next;
    }
}
int main()
{
    vector<int> data = { 1,2 };
    ListNode* head = new ListNode;
    ListNode_init(head,data);
    Solution s;
    s.swapPairs(head);

}