class Solution {
public:
    int possibleStringCount(string word) {
        unordered_set<string> seen;
        queue<pair<string, bool>> q; // {current string, has mistake been used}
        q.push({word, false});
        seen.insert(word);

        while (!q.empty()) {
            auto [cur, used] = q.front();
            q.pop();

            int n = cur.size();
            for (int i = 0; i < n;) {
                int j = i;
                while (j < n && cur[j] == cur[i]) j++;

                int len = j - i;
                // If length > 1 and we haven't used the "mistake" fix yet
                if (len > 1 && !used) {
                    for (int newLen = 1; newLen < len; ++newLen) {
                        string next = cur.substr(0, i) + string(newLen, cur[i]) + cur.substr(j);
                        if (seen.insert(next).second) {
                            q.push({next, true});
                        }
                    }
                }
                i = j;
            }
        }

        return seen.size();
    }
};

