class Solution {
public:
    int findKthNumber(int n, int k) {
        long curr = 1;
        k -= 1; // Start from 1, so we move k-1 steps

        while (k > 0) {
            long steps = countSteps(n, curr, curr + 1);
            if (steps <= k) {
                curr += 1;   // Move to next prefix
                k -= steps;  // Skip over 'steps' numbers
            } else {
                curr *= 10;  // Go deeper into the current prefix
                k -= 1;      // Move one step down
            }
        }
        return (int)curr;
    }

private:
    // Count how many numbers are in [prefix, nextPrefix) range
    long countSteps(int n, long prefix, long nextPrefix) {
        long steps = 0;
        while (prefix <= n) {
            steps += min((long)n + 1, nextPrefix) - prefix;
            prefix *= 10;
            nextPrefix *= 10;
        }
        return steps;
    }
};
