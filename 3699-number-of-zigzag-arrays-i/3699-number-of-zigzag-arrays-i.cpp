class Solution {
public:
      static constexpr long long MOD=1000000007L;
    int zigZagArrays(int n, int l, int r) {
        int m=r-l+1;
        if(n==1)return m;
        vector<long long>up(m+1),down(m+1);
        for(int x=1;x<=m;x++){
            up[x]=x-1;
            down[x]=m-x;

        }
        if (n==2){
            long long ans=0;
            for(int x=1;x<=m;x++){
                ans=(ans+up[x]+down[x])% MOD;
            }
            return (int)ans;
        }
        for (int len =3;len<=n;len++){
            vector<long long>newUp(m+1),newDown(m+1);

            long long pref=0;
            for(int x=1;x<=m;x++){
                newUp[x]=pref;
                pref=(pref+down[x])% MOD;

            }
             long long suf = 0;
            for (int x = m; x >= 1; x--) {
                newDown[x] = suf;
                suf = (suf + up[x]) % MOD;
            }

            up.swap(newUp);
            down.swap(newDown);
        }
        long long ans=0;
        for(int x=1;x<=m;x++){
            ans=(ans+up[x]+down[x])%MOD;
        }
        return (int)ans;
    }
};