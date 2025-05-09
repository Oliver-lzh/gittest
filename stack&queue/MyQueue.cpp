class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;

    MyQueue() {
     
    }
    
    void push(int x)
    {
        stIn.push(x);    
    }
    
    int pop()
    {
        //如果输出栈是空的，就先把数据导入
        if(stOut.empty())
        {
            while(!stIn.empty())
            {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }    
        int result=stOut.top();
        stOut.pop();
        return result;
    }
    
    int peek()
    {
        int result=this->pop();
        stOut.push(result);
        return result;    
    }
    
    bool empty()
    {
        return stIn.empty()&&stOut.empty();    
    }
};



