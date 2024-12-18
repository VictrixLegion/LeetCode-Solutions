vector<int> finalPrices(vector<int>& prices) {
    int n = prices.size();
    vector<int> result(n); // Array to store the final prices

    // Iterate through each item
    for (int i = 0; i < n; i++) {
        result[i] = prices[i]; // Initially set result to the original price

        // Look for the discount in subsequent items
        for (int j = i + 1; j < n; j++) {
            if (prices[j] <= prices[i]) {
                result[i] = prices[i] - prices[j]; // Apply the discount
                break; // Stop once the discount is applied
            }
        }
    }

    return result;
}
