/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val)
{
    // 将struct ListNode这个关键字化简为ListNode，就是一个结构体类型
   typedef struct ListNode ListNode;
   //初始化这个虚拟的头结点
   /*
   1.申请头结点的内存
   2.虚拟将头结点的指针向后指向头结点
   3.初始化一个结构体指针指向虚拟头结点
   */
   ListNode *shead;
   shead=(ListNode *)malloc(sizeof(ListNode));//申请头节点的内存
   shead->next=head;
   ListNode *cur=shead;

    while(cur->next!=NULL)
    {
        
        if(cur->next->val==val)
        {
            ListNode *tmp=cur->next;
            cur->next=cur->next->next;
            free(tmp);
        }
        else
        {
            //不用head是因为head是不更新的
            cur=cur->next;
        }
    }
    //重新更新头结点的位置
    head=shead->next;
    free(shead);
    //返回链表的头结点是因为，知道了头节点就知道整个链表，返回的是一个结构体的指针
    return head;
}