class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> valWithIndex;
        for (int i = 0; i < nums.size(); i++) {
            valWithIndex.push_back({nums[i], i});
        }

        // Step 1: Sort by value descending
        sort(valWithIndex.begin(), valWithIndex.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        // Step 2: Take top-k elements
        valWithIndex.resize(k);

        // Step 3: Sort by index to preserve original order
        sort(valWithIndex.begin(), valWithIndex.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        // Step 4: Extract values only
        vector<int> result;
        for (auto &p : valWithIndex) {
            result.push_back(p.first);
        }
        return result;
    }
};
