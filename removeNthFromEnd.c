/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    typedef struct ListNode ListNode;
    ListNode *fakehead=(ListNode *)malloc(sizeof(ListNode));
    fakehead->next=head;

    ListNode *fast=fakehead;
    ListNode *slow=fakehead;

    //2 0 1
    for(int i=0;i<=n;i++)
    {
        fast=fast->next;
    }

    //同时移动指针，使得fast指向最后的NULL
    while(fast)
    {
        slow=slow->next;
        fast=fast->next;
    }

    //删除对应结点
    ListNode *tmp;
    tmp=slow->next;
    slow->next=slow->next->next;
    free(tmp);

    return fakehead->next;
}