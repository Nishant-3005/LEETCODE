class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string last=strs[strs.size()-1];
        int i=0;
        while(i<first.size() && i<last.size()){
            if(first[i] != last[i]){
                break;
            }i++;
        }
        return first.substr(0,i);
    }
};