class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       if(nums.size()==0)
       return 0;
       unordered_set<int> st;
       for(int num:nums){
        st.insert(num);
       }
       int longest=0;
       for(int num:st){
        if(st.find(num-1)==st.end()){
            int cur=num;
            int cnt=1;
            while(st.find(cur+1)!=st.end()){
                cur++;
                cnt++;
            }
            longest=max(longest,cnt);
        }
       }
       return longest;
    }
};