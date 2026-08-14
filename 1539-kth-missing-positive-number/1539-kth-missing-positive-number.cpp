class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
       int num=1;
       while(k>0){
        bool found =false;
        for(int i=0;i<n;i++){
            if(arr[i]==num){
                found=true;
                break;
            }
        }
        if(!found){
            k--;
        }if(k==0)
        return num;
        num++;
       } return num;
    }
};