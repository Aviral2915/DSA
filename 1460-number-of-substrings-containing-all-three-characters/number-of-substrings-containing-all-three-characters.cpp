class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=(int)s.size();
        int left=0;
        int right=0;
        int cntA=0,cntB=0,cntC=0;
        long long ans=0;

        auto ok = [&]() { return cntA > 0 && cntB > 0 && cntC > 0; };

         for (int r = 0; r < n; ++r) {
            if (s[r] == 'a') ++cntA;
            else if (s[r] == 'b') ++cntB;
            else ++cntC;
             while (ok()) {

                ans += (n - r);
                if (s[left] == 'a') --cntA;
                else if (s[left] == 'b') --cntB;
                else --cntC;
                ++left;
            }
        }
        return (int)ans;
    }
};
        