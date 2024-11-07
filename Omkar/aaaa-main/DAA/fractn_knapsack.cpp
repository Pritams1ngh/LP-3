#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Item {
public:
    int profit, weight;
    Item(int profit, int weight) {
        this->profit = profit;
        this->weight = weight;
    }
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int w, vector<Item> &arr) {
    sort(arr.begin(), arr.end(), cmp);
    double finalValue = 0.0;

    for (auto &item : arr) {
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
    cout << "Enter number of items-\n";
    cin >> n;
    vector<Item> arr;
    
    for (int i = 0; i < n; ++i) {
        int profit, weight;
        cout << "Enter profit of item " << (i + 1) << "-\n";
        cin >> profit;
        cout << "Enter weight of item " << (i + 1) << "-\n";
        cin >> weight;
        arr.emplace_back(profit, weight);
    }

    int w;
    cout << "Enter capacity of knapsack-\n";
    cin >> w;

    cout << "Maximum value in knapsack: " << fractionalKnapsack(w, arr) << endl;

    return 0;
}
