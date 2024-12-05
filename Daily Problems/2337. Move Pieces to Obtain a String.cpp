bool canChange(string start, string target) {
    int i = 0, j = 0; // Pointers for start and target
    int n = start.size();

    while (i < n || j < n) {
        // Skip '_' in start
        while (i < n && start[i] == '_') i++;
        // Skip '_' in target
        while (j < n && target[j] == '_') j++;

        // If both pointers are at the end, the strings match
        if (i == n && j == n) return true;

        // If one pointer reaches the end before the other, return false
        if (i == n || j == n) return false;

        // Check if characters at i and j are different
        if (start[i] != target[j]) return false;

        // Movement validation
        if (start[i] == 'L' && i < j) return false; // 'L' cannot move right
        if (start[i] == 'R' && i > j) return false; // 'R' cannot move left

        // Move to the next character
        i++;
        j++;
    }

    return true;
}
