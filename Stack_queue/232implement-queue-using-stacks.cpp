//用双栈实现倒腾反反得正，实现队列
class MyQueue {
public:
    stack<int> stin;
    stack<int> stout;
    MyQueue() {

    }
    
    void push(int x) {
        stin.push(x);
    }
    
    void fulfill_stout(){
        if(stout.empty()){
            while(!stin.empty()){
                stout.push(stin.top());
                stin.pop();
            }
        }
    }

    int pop() {
        fulfill_stout();
        int result =stout.top();
        stout.pop(); 
        return result;
    }
    
    int peek() {
        fulfill_stout();
        return stout.top();
    }
    
    bool empty() {
        return stin.empty()&&stout.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */