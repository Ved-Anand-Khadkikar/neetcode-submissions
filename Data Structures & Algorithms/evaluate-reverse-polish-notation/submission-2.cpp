class Solution {
public:

    int calculate(int a,int b,string op){
        if(op=="+"){
            return b+a;
        }
        else if(op=="-"){
            return b-a;
        }
        else if(op=="*"){
            return a*b;
        }
        else{
            return b/a;
        }
        return -1;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int result;
        int n=tokens.size();
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"|| tokens[i]=="-" || tokens[i]=="*" ||tokens[i]=="/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                result=calculate(a,b,tokens[i]);
                st.push(result);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
