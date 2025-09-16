class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD =1e9+7;
        int n =arr.size();
        vector<int> left(n), right(n);
        stack<int> st;

        for(int i=0; i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i]) st.pop();
            left[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0;i--){
              while(!st.empty()&&arr[st.top()]>=arr[i]) st.pop();
            right[i]=st.empty()?n:st.top();
            st.push(i);

        }

        long long ans=0;
        for(int i=0;i<n;i++){
            long long leftcount=i-left[i];
            long long rightcount=right[i]-i;
            ans = (ans + (long long)arr[i] * leftcount * rightcount) % MOD;
        }
        return (int)ans;
        

    }
};