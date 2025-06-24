class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> result;  // Using set to store unique indices in sorted order

        // Step 1: Traverse the array to find all positions where nums[i] == key
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == key) {
                // Step 2: For each such index, mark all indices within distance k
                int start = max(0, i - k);
                int end = min((int)nums.size() - 1, i + k);

                for (int j = start; j <= end; j++) {
                    result.insert(j);
                }
            }
        }

        // Step 3: Convert set to vector to return as result
        return vector<int>(result.begin(), result.end());
    }
};
