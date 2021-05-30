// LEETCODE PROBLEM - https://leetcode.com/problems/two-sum/

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> lookup;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (lookup.find(target - nums[i]) != lookup.end()) {
                res.push_back(i);
                res.push_back(lookup[target - nums[i]]);
                break;
            }
            lookup[nums[i]] = i;
        }
        return res;
    }
};