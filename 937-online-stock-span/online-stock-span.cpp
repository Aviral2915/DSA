class StockSpanner {
     vector<int> prices;
      vector<int> prevHigh;
      stack<int> st;
public:
       StockSpanner() {





    }
    
    int next(int price) {
        int i=prices.size();
        prices.push_back(price);
        
        while (!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }

        int prev=st.empty()?-1:st.top();
        prevHigh.push_back(prev);
        st.push(i);

        return i-prev;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */