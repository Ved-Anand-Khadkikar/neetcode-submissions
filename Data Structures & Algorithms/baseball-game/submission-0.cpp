class Solution {
   public:
    void calculate(int a, int b, string op, stack<int>& st) {
        if (op == "+") {
            int sum = a + b;
            st.push(sum);
        } else if (op == "C") {
            st.pop();
        } else {
            int prod = a * 2;
            st.push(prod);
        }
    }
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int totalSum = 0;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+" || operations[i] == "C" || operations[i] == "D") {
                int a = st.top();
                int b;
                st.pop();
                if (st.empty()) {
                    b = 1;
                } else {
                    b = st.top();
                }
                st.push(a);
                calculate(a, b, operations[i], st);
            } else {
                st.push(stoi(operations[i]));
            }
        }
        while (!st.empty()) {
            totalSum += st.top();
            st.pop();
        }
        return totalSum;
    }
};