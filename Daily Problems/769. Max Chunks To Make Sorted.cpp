int maxChunksToSorted(vector<int>& arr) {
    int max_seen = 0;  // Tracks the maximum value seen so far
    int chunks = 0;    // Count of valid chunks

    for (int i = 0; i < arr.size(); i++) {
        max_seen = max(max_seen, arr[i]);  // Update the maximum value
        if (max_seen == i) {
            chunks++;  // A valid chunk is found
        }
    }

    return chunks;
}
