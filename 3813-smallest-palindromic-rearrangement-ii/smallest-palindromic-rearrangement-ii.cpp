class Solution {
public:
    static const long long LIM = 1000001;

    long long comb(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);

        long long res = 1;

        for (int i = 1; i <= r; i++) {
            long long a = n - r + i;
            long long b = i;

            long long g = gcd(a, b);
            a /= g;
            b /= g;

            g = gcd(res, b);
            res /= g;
            b /= g;

            if (res > LIM / a)
                return LIM;

            res *= a;
            res /= b;

            if (res > LIM)
                return LIM;
        }

        return min(res, LIM);
    }

    long long countWays(vector<int>& cnt) {
        int remain = 0;
        for (int x : cnt) remain += x;

        long long ans = 1;

        for (int x : cnt) {
            if (x == 0) continue;

            long long cur = comb(remain, x);

            if (ans > LIM / cur)
                return LIM;

            ans *= cur;

            if (ans > LIM)
                return LIM;

            remain -= x;
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {

        vector<int> freq(26,0);

        for(char c:s)
            freq[c-'a']++;

        vector<int> half(26,0);

        char mid=0;

        for(int i=0;i<26;i++){
            half[i]=freq[i]/2;
            if(freq[i]%2)
                mid='a'+i;
        }

        if(countWays(half)<k)
            return "";

        int len=s.size()/2;

        string left;

        for(int pos=0;pos<len;pos++){

            for(int c=0;c<26;c++){

                if(half[c]==0)
                    continue;

                half[c]--;

                long long ways=countWays(half);

                if(ways>=k){
                    left.push_back('a'+c);
                    break;
                }

                k-=ways;
                half[c]++;
            }
        }

        string right=left;
        reverse(right.begin(),right.end());

        if(mid)
            return left+mid+right;

        return left+right;
    }
};