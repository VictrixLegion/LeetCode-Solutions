bool isPrefixAndSuffix(const string& str1, const string& str2) {
    int n = str1.size();
    int m = str2.size();
    if (n > m) return false; // str1 cannot be a prefix or suffix if it's longer than str2
    return str2.substr(0, n) == str1 && str2.substr(m - n, n) == str1;
}

// Function to count prefix and suffix pairs
int countPrefixSuffixPairs(vector<string>& words) {
    int n = words.size();
    int count = 0;

    // Iterate over all pairs (i, j) where i < j
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (isPrefixAndSuffix(words[i], words[j])) {
                count++;
            }
        }
    }

    return count;
}
