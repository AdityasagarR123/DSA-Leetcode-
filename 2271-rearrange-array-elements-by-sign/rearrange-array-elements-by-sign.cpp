class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;

        int n = nums.size();

        // Step 1: separate
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                pos.push_back(nums[i]);
            } else {
                neg.push_back(nums[i]);
            }
        }

        // Step 2: merge
        vector<int> fin(n);

        int p = 0, ne = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                fin[i] = pos[p];
                p++;
            } else {
                fin[i] = neg[ne];
                ne++;
            }
        }

        return fin;
    }
};