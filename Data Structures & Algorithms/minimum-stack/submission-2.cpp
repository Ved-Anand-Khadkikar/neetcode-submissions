class MinStack {
public:
    stack<long long>st;
    long long mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            mini=val;
            st.push(val);
        }
        else if(val>=mini){
            st.push(val);
        }
        else{
            st.push(2LL*val-mini);
            mini=val;
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        else if(st.top()>=mini){
            st.pop();
        }
        else{
            mini=2*mini-st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        else if(st.top()>=mini){
            return st.top();
        }
        else{
            return mini;
        }
    }
    
    int getMin() {
        if(st.empty()){
            return -1;
        }
        else{
            return mini;
        }
    }
};
