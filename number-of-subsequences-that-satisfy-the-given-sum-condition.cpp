class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // Precompute powers of 2
        vector<int> pow2(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow2[i] = (pow2[i - 1] * 2LL) % mod;
        }

        int left = 0, right = n - 1;
        int res = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                res = (res + pow2[right - left]) % mod;
                left++;
            } else {
                right--;
            }
        }

        return res;
    }
};
