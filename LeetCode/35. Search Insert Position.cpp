class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        int mid = lo + (hi - lo) / 2;

        while (hi >= lo) {
            mid = lo + (hi - lo) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if(nums[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        if(nums[mid] > target) {
            return mid;
        } else {
            return mid + 1;
        }
    }
};
