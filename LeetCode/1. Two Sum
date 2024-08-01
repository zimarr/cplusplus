class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> intMap;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int numMatch = target - num;
            
            if (intMap.find(numMatch) == intMap.end()) {
                intMap[num] = i;
            } else {
                return {intMap[numMatch], i};
            }
        }
        return {};
    }
};
