class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n=arr.size();
        int sum_n=n*(n+1)/2;

        int sum_arr=0;
        for(int i=0;i<n;i++){
            sum_arr+=arr[i];
        }
        return sum_n-sum_arr;
        
    }
};