class Solution {
public:
int countpairs(vector<int>& nums,int low,int mid,int high){
    int j=mid+1;
    int cnt=0;
    for(int i=low;i<=mid;i++){
        while(j<=high && (long long)nums[i]>2LL*nums[j]){
            j++;
        }
        cnt+=j-(mid+1);
    }
    vector<int>temp;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(nums[left]<=nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
        else{
            temp.push_back(nums[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(nums[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(nums[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        nums[i]=temp[i-low];
    }
    return cnt;
}

int mergesort(vector<int>& nums,int low,int high){
    if(low>=high)
    return 0;
    int mid=low+(high-low)/2;
    int cnt=0;
    cnt+=mergesort(nums,low,mid);
    cnt+=mergesort(nums,mid+1,high);
    cnt+=countpairs(nums,low,mid,high);
    return cnt;
}
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};