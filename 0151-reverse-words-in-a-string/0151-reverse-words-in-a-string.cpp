class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        reverse(s.begin(),s.end());
        int i=0;
        while(i<n){
            while(i<n && s[i]==' '){
                i++;
            }int start=i;
            while(i<n && s[i]!=' '){
                i++;
            }
            reverse(s.begin()+start,s.begin()+i);
        }
        int write=0;
        i=0;
        while(i<n){
            while(i<n && s[i]==' '){
                i++;
            }if(i==n){
                break;
            }if(write>0){
                s[write++]=' ';
            }
            while(i<n && s[i]!=' '){
                s[write++]=s[i++];
            }
        }
        s.resize(write);
        return s;
    }
};