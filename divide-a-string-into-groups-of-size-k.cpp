class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;

        // Loop through the string in steps of k
        for (int i = 0; i < s.size(); i += k) {
            string group = s.substr(i, k);

            // If the group is shorter than k, pad it
            while (group.size() < k) {
                group += fill;
            }

            result.push_back(group);
        }

        return result;
    }
};
