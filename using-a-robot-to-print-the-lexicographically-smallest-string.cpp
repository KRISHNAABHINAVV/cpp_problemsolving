class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<char> minRight(n);
        char minChar = s[n - 1];

        // Precompute the smallest character from i to end
        for (int i = n - 1; i >= 0; --i) {
            minChar = min(minChar, s[i]);
            minRight[i] = minChar;
        }

        stack<char> t;
        string result;

        for (int i = 0; i < n; ++i) {
            t.push(s[i]);

            // Pop from t if top is <= the min remaining character
            while (!t.empty() && (i == n - 1 || t.top() <= minRight[i + 1])) {
                result += t.top();
                t.pop();
            }
        }

        return result;
    }
};
