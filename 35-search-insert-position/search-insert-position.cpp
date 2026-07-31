class Solution {
public:
    int searchInsert(vector<int>& nums, int t) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == t) {
                return mid;
            }
            else if (nums[mid] < t) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};