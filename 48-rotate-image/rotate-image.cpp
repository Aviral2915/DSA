class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n=a.size();
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                swap(a[i][j],a[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            int l=0;
            int r=n-1;
            while(l<r){
                swap(a[i][l],a[i][r]);
                l++;
                r--;
            }
        }
        
    }
};