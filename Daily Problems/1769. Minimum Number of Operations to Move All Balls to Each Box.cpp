vector<int> minOperations(string boxes) {
    int n = boxes.size();
    vector<int> answer(n, 0);
    int count = 0, operations = 0;

    // Traverse from left to right
    for (int i = 0; i < n; ++i) {
        answer[i] += operations;
        count += (boxes[i] - '0');  // Update the count of balls
        operations += count;       // Accumulate operations
    }

    count = 0;
    operations = 0;

    // Traverse from right to left
    for (int i = n - 1; i >= 0; --i) {
        answer[i] += operations;
        count += (boxes[i] - '0');  // Update the count of balls
        operations += count;       // Accumulate operations
    }

    return answer;   
    }
