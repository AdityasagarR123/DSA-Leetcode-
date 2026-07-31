class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        // Count frequency
        for (char c : word)
            freq[c - 'a']++;

        // Sort in descending order
        sort(freq.begin(), freq.end(), greater<int>());

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break;

            ans += freq[i] * (i / 8 + 1);
        }

        return ans;
    }
};