#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Class to represent an item
class Item {
public:
    int profit;
    int weight;

    Item(int p, int w) {
        profit = p;
        weight = w;
    }
};

// Function to calculate the maximum value in the knapsack
double fractionalKnapsack(int w, vector<Item>& arr) {
    // Sort items based on profit/weight ratio in descending order
    sort(arr.begin(), arr.end(), [](const Item& a, const Item& b) {
        return (double)a.profit / a.weight > (double)b.profit / b.weight;
    });

    double finalValue = 0.0;

    // Process the sorted items
    for (const auto& item : arr) {
        if (w >= item.weight) {
            finalValue += item.profit;
            w -= item.weight;
        } else {
            finalValue += item.profit * ((double)w / item.weight);
            break;
        }
    }

    return finalValue;
}

int main() {
    int n;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> arr;
    for (int i = 0; i < n; i++) {
        int profit, weight;
        cout << "Enter profit of item " << i + 1 << ": ";
        cin >> profit;
        cout << "Enter weight of item " << i + 1 << ": ";
        cin >> weight;
        arr.push_back(Item(profit, weight));
    }

    int w;
    cout << "Enter capacity of knapsack: ";
    cin >> w;

    // Calculate and print the maximum value in the knapsack
    cout << "Maximum value in knapsack: " << fractionalKnapsack(w, arr) << endl;

    return 0;
}

// # Enter number of items-
// # 3
// # Enter profit of item 1-
// # 60
// # Enter weight of item 1-
// # 10
// # Enter profit of item 2-
// # 100
// # Enter weight of item 2-
// # 20
// # Enter profit of item 3-
// # 120
// # Enter weight of item 3-
// # 30
// # Enter capacity of knapsack-
// # 50
// # Maximum value in knapsack:  240.0
