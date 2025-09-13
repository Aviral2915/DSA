class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int a:asteroids){
            bool alive = true;
 
            while(alive && !st.empty()&& st.top()>0 && a<0){
                if(abs(st.top())<abs(a)){
                    st.pop();
                }
                else if(abs(st.top())==abs(a)){
                    st.pop();
                    alive = false;
                }
                else{
                    alive = false;
                }
            
            }
            if(alive) st.push(a);
        }
        vector<int> ans(st.size());
         for (int i = st.size() - 1; i >= 0; --i) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
        
    }
};