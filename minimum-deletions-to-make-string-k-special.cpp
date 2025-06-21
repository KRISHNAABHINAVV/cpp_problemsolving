class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;

        // Count frequency of each character
        for (char c : word) {
            freq[c]++;
        }

        // Store frequencies in a list
        vector<int> freqList;
        for (auto& pair : freq) {
            freqList.push_back(pair.second);
        }

        int minDeletions = INT_MAX;
        int maxFreq = *max_element(freqList.begin(), freqList.end());

        // Try every possible target frequency
        for (int target = 1; target <= maxFreq; target++) {
            int deletions = 0;
            for (int f : freqList) {
                if (f < target) {
                    deletions += f; // delete all if too small
                } else if (f > target + k) {
                    deletions += f - (target + k); // delete excess if too big
                }
            }
            minDeletions = min(minDeletions, deletions);
        }

        return minDeletions;
    }
};

