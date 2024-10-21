
//快慢指针
struct ListNode* reverseList(struct ListNode* head)
{
    typedef struct ListNode ListNode;

    ListNode *fast=head;
    ListNode *slow=NULL;

    while(fast)
    {
        ListNode *tmp=fast->next;
        fast->next=slow;
        slow=fast;
        fast=tmp;
    }
    return slow;
}



//递归
typedef struct ListNode ListNode;


ListNode* reverlist(ListNode *cur,ListNode *slow)
{
    if(cur==NULL)
    {
        return slow;
    }
    ListNode *tmp;
    tmp=cur->next;
    cur->next=slow;
    return reverlist(tmp,cur);
}
struct ListNode* reverseList(struct ListNode* head)
{
    return reverlist(head,NULL);    
}