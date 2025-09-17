class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char c:num){
        while(!st.empty()&&k>0&&st.top()>c){
        st.pop();
        k--;
        }
    st.push(c);
      }

     while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

    string ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

     reverse(ans.begin(), ans.end());

     int i = 0;
        while (i < (int)ans.size() && ans[i] == '0') i++;
        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    
     }
};