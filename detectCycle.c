struct ListNode *detectCycle(struct ListNode *head)
{
    typedef struct ListNode ListNode;
    ListNode *fast=head,*slow=head;

    while(fast&&fast->next)//判断fast->next不为空才不会操作空指针
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)//指针的地址相同
        {
            ListNode *index=fast,*index1=head;
            while(index!=index1)
            {
                index=index->next;
                index1=index1->next;
            }
            return index;
        }
    }
    return NULL;
}