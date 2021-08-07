class Solution {

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unsigned short size, start, end;

        size = nums.size();

        for (start = 0; start < size; start++)
        {
            for (end = start + 1; end < size; end++)
            {
                if (nums[start] + nums[end] == target) {
                    return { start, end };
                }
            }

        }
        return {};
    }
};