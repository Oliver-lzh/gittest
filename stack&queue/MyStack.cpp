class MyStack {
public:
    queue<int> que;

    MyStack() {

    }

    void push(int x) {
        que.push(x);
    }

    //思路就是将需要弹出的元素后的所有元素先全部重新入当前队列（除了最后一个），然后弹出。目的是不打乱原始的顺序
    int pop()
    {
        //将需要弹出的元素前面的元素往后面备份，之后弹出需要的
        int size = que.size();
        size--;
        while (size--)
        {
            //在后面添加一个最前面的元素，然后将最前面的元素删除（pop操作）
            que.push(que.front());
            que.pop();
        }
        int result = que.front();
        que.pop();
        return result;


        int size = que.size();
        size--;
        while (size--)
        {
            que.push(que.front());
            que.pop();
        }
        int result = que.front();
        que.pop();
        return result;
    }

    int top()
    {
        int size = que.size();
        size--;
        while (size--)
        {
            que.push(que.front());
            que.pop();
        }
        int result = que.front();
        //为了保证原始的队列的顺序是一样的
        que.push(que.front());
        que.pop();
        return result;
    }

    bool empty()
    {
        return que.empty();
    }
};

