class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int freq[26]={0};
                for(int k=i;k<=j;k++){
                    freq[s[k]-'a']++;
                }
                int maxi=0;
                int mini=INT_MAX;
                for(int f:freq){
                    if(f>0){
                        maxi=max(maxi,f);
                        mini=min(mini,f);
                    }
                }
                ans+=maxi-mini;
            }
        }
        return ans;
    }
};