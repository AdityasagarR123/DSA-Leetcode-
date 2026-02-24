class Solution {
public:
    int singleNumber(vector<int>& arr) {
        int n = arr.size();
        int x = 0;   // initialize

        for(int i = 0; i < n; i++) {
            x = x ^ arr[i];
        }

        return x;
    }
};