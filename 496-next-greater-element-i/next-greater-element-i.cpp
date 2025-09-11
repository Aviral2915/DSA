class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int> &nums2) {
        unordered_map<int,int>  nextGreater;
        stack <int> st;

        for(int x:nums2){
            while(!st.empty() && x>st.top()){
                nextGreater[st.top()]=x;
                st.pop();
            }
            st.push(x);
        }

        vector<int> ans;
        for(int num:nums1){
            if(nextGreater.find(num)!=nextGreater.end()){
                ans.push_back(nextGreater[num]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
    