class Solution {
public:
       
       int countAtMost(vector<int>& nums,int k){
        if(k<0) return 0;
        int left=0,oddCount=0,right=0; int total=0;

        for (int right = 0; right < nums.size(); right++) {
            if(nums[right]%2!=0){
                oddCount++;
            }

            while (oddCount > k) {
                if (nums[left] % 2 != 0)
                    oddCount--;
                left++;
            }
            
                total += (right - left + 1);
            }
             return total;
       }

    
    int numberOfSubarrays(vector<int>& nums, int k) {
          return countAtMost(nums, k) - countAtMost(nums, k - 1);
    }
};