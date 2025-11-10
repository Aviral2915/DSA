class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();

        int lsum=0;
        int rsum=0;
        int totalsum=0;

        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        totalsum=lsum;

        for(int i=0;i<k;i++){
            lsum-=cardPoints[k-1-i];
            rsum+=cardPoints[n-1-i];
            totalsum=max(totalsum,lsum+rsum);
        }

        return totalsum;

        
    }
};