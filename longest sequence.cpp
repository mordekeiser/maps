class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            // Only check numbers that are the start of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int count = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    count++;
                }

                longest = max(longest, count);
            }
        }
        return longest;
    }
};
