#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapSack(int W, vector<int>& wt, vector<int>& val, int n) {
    // Initialize DP table with 0s
    vector<vector<int>> K(n + 1, vector<int>(W + 1, 0));

    // Build the table K[][] in bottom-up manner
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if (wt[i-1] <= w) {
                // Take the maximum of including or excluding the item
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            } else {
                K[i][w] = K[i-1][w];
            }
        }
    }

    return K[n][W];  // Maximum profit
}

int main() {
    int n;
    
    // User input for number of items
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> profit(n);
    vector<int> weight(n);

    // User input for profit and weight of each item
    for (int i = 0; i < n; ++i) {
        cout << "Enter profit of item " << i + 1 << ": ";
        cin >> profit[i];
        cout << "Enter weight of item " << i + 1 << ": ";
        cin >> weight[i];
    }

    // User input for knapsack capacity
    int W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    // Call knapSack function and print the maximum profit
    cout << "Maximum profit in knapsack: " << knapSack(W, weight, profit, n) << endl;

    return 0;
}

// # Enter the number of items: 3
// # Enter profit of item 1: 60
// # Enter weight of item 1: 10
// # Enter profit of item 2: 100
// # Enter weight of item 2: 20
// # Enter profit of item 3: 120
// # Enter weight of item 3: 30
// # Enter the capacity of the knapsack: 50
// # Maximum profit in knapsack:  220
