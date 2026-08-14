class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
       if((long long )m*k>n)
       return -1;
       int low=1;
       int high=0;
       for(int i=0;i<n;i++){
        high=max(high,bloomDay[i]);
       }
       int ans=-1;
       while(low<=high){
        int day=low+(high-low)/2;
        int flowers=0;
        int bouquets=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day){
                flowers++;
                if(flowers==k){
                    bouquets++;
                    flowers=0;
                }
            }
            else{
                flowers=0;
            }
        }
        if(bouquets>=m){
            ans=day;
            high=day-1;
        }
        else{
            low=day+1;
        }
       }
       return ans;
}
};