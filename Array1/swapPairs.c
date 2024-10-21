struct ListNode* swapPairs(struct ListNode* head)
{
    typedef struct ListNode ListNode;
    ListNode *fakehead = (ListNode *)malloc(sizeof(ListNode));
    fakehead->next = head;
    ListNode *tmp=fakehead;
    while(tmp->next!=NULL && tmp->next->next!=NULL)
    {
        ListNode *node1=tmp->next;
        ListNode *node2=tmp->next->next;

        tmp->next=node2;
        node1->next=node2->next;
        node2->next=node1;
        tmp=node1;
    }
    return fakehead->next;//tmp一直在变化，但是fakehead不会变化。
}

