class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());              // reverse whole array
        reverse(nums.begin(), nums.begin() + k);       // reverse first k elements
        reverse(nums.begin() + k, nums.end());         // reverse remaining
    }
};