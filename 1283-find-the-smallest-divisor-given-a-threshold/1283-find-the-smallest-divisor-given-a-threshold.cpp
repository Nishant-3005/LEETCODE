class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;
        int high=0;
        for(int i=0;i<n;i++){
            high=max(high,nums[i]);
        }
        int ans=high;
        while(low<=high){
            int divisor=low+(high-low)/2;
            long long sum=0;
            for(int i=0;i<n;i++){
                sum+=(nums[i]+divisor-1)/divisor;
            }
            if(sum<=threshold){
                ans=divisor;
                high=divisor-1;
            }else{
                low=divisor+1;
            }
        }
        return ans;
    }
};