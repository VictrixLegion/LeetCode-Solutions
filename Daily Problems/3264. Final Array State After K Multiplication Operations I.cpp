vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int i = 0; i < k; i++) {
        // Find the index of the minimum element
        int min_index = min_element(nums.begin(), nums.end()) - nums.begin();
        // Replace the minimum value with its product
        nums[min_index] *= multiplier;
    }
    return nums;
    }
