#include<iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct ListNode * test()
{
    ListNode* point1 = NULL;
    ListNode* point2 = NULL;
    vector<ListNode*> array_p;
    while (point1 != NULL || point2 != NULL)
    {
        if (find(array_p.begin(), array_p.end(), point2) != array_p.end())
        {
            return array_p.back();
        }
        if (point1 != NULL)
        {
            array_p.push_back(point1);
            point1 = point1->next;
        }
        if (point2 != NULL)
            point2 = point2->next;

    }
    return NULL;
}

int main()
{
    test();
    return 1;

}