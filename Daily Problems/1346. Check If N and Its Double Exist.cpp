bool checkIfExist(vector<int>& arr) {
    unordered_set<int> seen; // Set to store visited numbers
    for (int num : arr) {
        // Check if double of the current number or half of the current number exists in the set
        if (seen.count(2 * num) || (num % 2 == 0 && seen.count(num / 2))) {
            return true;
        }
        // Add the current number to the set
        seen.insert(num);
    }
    return false; // No such pair found
    }
