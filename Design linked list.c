


typedef struct MyLinkedList{
    int val;
    struct MyLinkedList *next;
} MyLinkedList;



MyLinkedList* myLinkedListCreate() 
{
    MyLinkedList *head;
    head=(MyLinkedList *)malloc(sizeof(MyLinkedList));
    head->next=NULL;
    return head;
}


//第一个参数传入是头结点的
int myLinkedListGet(MyLinkedList* obj, int index) 
{
    MyLinkedList *cur = obj->next;
    for (int i = 0; cur != NULL; i++){
        if (i == index){
            return cur->val;
        }
        else{
            cur = cur->next;
        }
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) 
{
    //这里传入的obj是虚拟的头结点
    MyLinkedList *head=(MyLinkedList *)malloc(sizeof(MyLinkedList));
    head->val=val;
    head->next=obj->next;
    obj->next=head;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val)
{
    MyLinkedList *cur=obj;
    //一直寻找使得cur指向了链表的最后，方便进行后续的操作。
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    //申请一个尾部的节点,初始化
    MyLinkedList *nail=(MyLinkedList *)malloc(sizeof(MyLinkedList));
    nail->val=val;
    cur->next=nail;
    nail->next=NULL;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) 
{
   if(index==0)
   {
        myLinkedListAddAtHead(obj,val);
        return ;
   }
    //指向真正的头结点
    MyLinkedList *cur=obj->next;
    for(int i=1;cur!=NULL;i++)//把循环变快，cur的更新变慢一个
    {
        if(i==index)
        {
            MyLinkedList *newnode=(MyLinkedList *)malloc(sizeof(MyLinkedList));
            newnode->val=val;
            newnode->next=cur->next;
            cur->next=newnode;
            return ;
        }
        else
        {
            cur=cur->next;
        }
    }
}


void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index)
{
    if(index==0)
    {
        MyLinkedList *tmp=obj->next;
        if(tmp!=NULL)
        {
            obj->next=tmp->next;
            free(tmp);
        }
        return ;
    }

     MyLinkedList *cur=obj->next;
     for(int i=1;cur!=NULL;i++)
     {
        if(i==index)
        {
            MyLinkedList *tmp;
            tmp=cur->next;
            if(tmp!=NULL)
            {
                cur->next=tmp->next;//等同于 cur->next=cur->next->next;
                free(tmp);
            }
            return ;
        }
        else
        {
            cur=cur->next;
        }
     }
}

//细节就是要一个个节点删除，不是只删除头结点
void myLinkedListFree(MyLinkedList* obj) 
{
    while(obj->next!=NULL)
    {
        MyLinkedList *tmp=obj;
        obj=obj->next;
        free(tmp);
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/