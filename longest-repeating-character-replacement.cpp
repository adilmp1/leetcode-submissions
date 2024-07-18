int characterReplacement(string s, int k) {
    unordered_map<char, int> mp;
    int left = 0;
    int right = 0;
    int ans = 0;
    int largestFreq = 0;

    while (right < s.size()) {
        mp[s[right]]++;
        largestFreq = max(largestFreq, mp[s[right]]);
        right++;

        if (right - left - largestFreq > k) {
            mp[s[left]]--;
            left++;
        }
        ans = max(ans, right - left);
    }
    return ans;
}
