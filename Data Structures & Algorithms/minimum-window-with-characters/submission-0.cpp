class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();

        // Edge case: if t is longer than s, impossible to find a window
        if (n > m) return "";

        // Step 1: Build frequency map of characters in t
        unordered_map<char, int> mp;
        for (char &ch : t) {
            mp[ch]++;
        }

        // requiredCount = how many chars from t we still need to match
        int requiredCount = n;

        // Sliding window boundaries
        int i = 0, j = 0;

        // Track result (min window length and starting index)
        int minWindowSize = INT_MAX;
        int start_i = 0;

        // Step 2: Expand window using j (right pointer)
        while (j < m) {
            char ch = s[j];

            // If this char is required (mp[ch] > 0), reduce requiredCount
            if (mp[ch] > 0) {
                requiredCount--;
            }

            // Decrease map count anyway (could go negative if extra chars)
            mp[ch]--;

            // Step 3: When all characters are matched (requiredCount == 0),
            // try to shrink the window from the left (i pointer)
            while (requiredCount == 0) {
                int currWindowSize = j - i + 1;

                // Update answer if this window is smaller
                if (minWindowSize > currWindowSize) {
                    minWindowSize = currWindowSize;
                    start_i = i;  // store starting index of best window
                }

                // Before moving i forward, restore the count of s[i]
                mp[s[i]]++;

                // If restoring made a char count > 0,
                // it means this char is now missing from the window
                if (mp[s[i]] > 0) {
                    requiredCount++;
                }

                // Shrink window from the left
                i++;
            }

            // Expand window by moving j
            j++;
        }

        // Step 4: Return smallest valid window, or "" if not found
        return (minWindowSize == INT_MAX) ? "" : s.substr(start_i, minWindowSize);
    }
};
