class Solution {
public:
    int compress(vector<char>& chars) {

        int n=chars.size();
        int write=0;
        int i=0;

        while(i<n){
            char ch=chars[i];
            int j=i;

            while(j<n && chars[j]==ch){
                j++;
            }

            int count=j-i;

            chars[write++]=ch;

            if(count>1){
                string num= to_string(count);

                for (char c:num){
                    chars[write++]=c;
                }
            }
            i=j;
        }
        return write;
        
    }
};