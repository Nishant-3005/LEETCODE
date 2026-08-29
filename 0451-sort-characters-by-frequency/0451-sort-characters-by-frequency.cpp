class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char,int> freq;
       for(int i=0;i<s.size();i++){
        freq[s[i]]++;
       }
       vector<pair<char,int>>arr;
       for(auto it:freq){
        arr.push_back({it.first,it.second});
       }

       sort(arr.begin(),arr.end(),[](pair<char,int>& a,pair<char,int>& b){
        return a.second>b.second;
       });
       string ans="";
       for(auto it:arr){
        ans+=string(it.second,it.first);
       }
       return ans;
}
};