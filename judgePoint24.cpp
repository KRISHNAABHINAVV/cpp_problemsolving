class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }

private:
    bool solve(vector<double>& nums) {
        // Base case: only one number remains
        if (nums.size() == 1) {
            // Check if it's close enough to 24 (floating-point tolerance)
            return fabs(nums[0] - 24.0) < 1e-6;
        }

        // Try all pairs of numbers
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue; // can't use the same number twice

                // Create a new list without nums[i] and nums[j]
                vector<double> nextNums;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) nextNums.push_back(nums[k]);
                }

                // Try all operations with nums[i] and nums[j]
                for (int op = 0; op < 4; op++) {
                    // To avoid duplicate computations, enforce ordering
                    if ((op < 2) && (i > j)) continue; 

                    if (op == 0) nextNums.push_back(nums[i] + nums[j]);     // addition
                    if (op == 1) nextNums.push_back(nums[i] * nums[j]);     // multiplication
                    if (op == 2) nextNums.push_back(nums[i] - nums[j]);     // subtraction
                    if (op == 3 && fabs(nums[j]) > 1e-6)                   // division (avoid div by 0)
                        nextNums.push_back(nums[i] / nums[j]);

                    // Recurse with the new list
                    if (solve(nextNums)) return true;

                    // Backtrack (remove last result)
                    if (!nextNums.empty()) nextNums.pop_back();
                }
            }
        }
        return false;
    }
};
