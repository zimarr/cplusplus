class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        map<int, bool> map;

        for (int i = 0; i < n; i++) {
            map[nums[i]] = true;
        }

        for (auto it : map) {
            if (!map[it.first]){
                return it.first;
            }
        }

        return -1;
    }
};
