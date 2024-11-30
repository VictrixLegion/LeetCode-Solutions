vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    // Graph to store adjacency list
    unordered_map<int, vector<int>> graph;

    // Maps to store the in-degree and out-degree of each node
    unordered_map<int, int> outDegree, inDegree;

    // Step 1: Build the graph and compute the in-degree and out-degree for each node
    for (auto& pair : pairs) {
        int start = pair[0];  // Start of the edge
        int end = pair[1];    // End of the edge

        graph[start].push_back(end); // Add an edge from start to end
        outDegree[start]++;          // Increment out-degree of start
        inDegree[end]++;             // Increment in-degree of end
    }

    // Step 2: Find the start node for the Eulerian path
    int startNode = pairs[0][0]; // Default to the first node in pairs
    for (auto& [node, _] : graph) { // Iterate through all nodes in the graph
        // If a node has outDegree > inDegree, it is the start node for the path
        if (outDegree[node] > inDegree[node]) {
            startNode = node;
            break; // Break since we only need one start node
        }
    }

    // Step 3: Initialize structures for Hierholzer's algorithm
    stack<int> stk;          // Stack to keep track of the current traversal path
    vector<int> path;        // Vector to store the final Eulerian path
    stk.push(startNode);     // Start the traversal from the identified start node

    // Step 4: Perform Hierholzer's algorithm to find the Eulerian path
    while (!stk.empty()) {  // Continue until all nodes are processed
        int curr = stk.top(); // Get the current node from the top of the stack
        if (!graph[curr].empty()) { // If the current node has outgoing edges
            int next = graph[curr].back(); // Get the last edge (neighbor)
            graph[curr].pop_back();        // Remove this edge from the graph
            stk.push(next);                // Push the next node onto the stack
        } else { // If the current node has no outgoing edges
            path.push_back(curr); // Add the node to the final path
            stk.pop();            // Remove the node from the stack
        }
    }

    // Step 5: Reverse the path to get the correct order
    reverse(path.begin(), path.end());

    // Step 6: Build the result as a list of pairs from the Eulerian path
    vector<vector<int>> result;
    for (int i = 0; i < path.size() - 1; ++i) { // Iterate over consecutive nodes in the path
        result.push_back({path[i], path[i + 1]}); // Form a pair from consecutive nodes
    }

    return result; // Return the valid arrangement of pairs
}
