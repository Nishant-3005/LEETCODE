class Solution {
public:
bool ispossible(vector<int>& nums,int k,long long maxsum){
    int n=nums.size();
    int parts=1;
    int long long currsum=0;
    for(int i=0;i<n;i++){
        if(currsum + nums[i]<=maxsum){
            currsum +=nums[i];
        }else{
            parts++;
            currsum=nums[i];
            if(parts>k){
            return false;
        }
    }
}
return true ;
}
    int splitArray(vector<int>& nums, int k) {
        long long low=*max_element(nums.begin(),nums.end());
        long long high=accumulate(nums.begin(),nums.end(),0LL);
        long long ans=high;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(ispossible(nums,k,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return(int)ans;
    }
};