#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

//comapre jobs by profit
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobSequencing(vector<Job>& jobs, int n) {
    // Sort in decreasing order of profit
    sort(jobs.begin(), jobs.end(), compare);

    //free time slots
    vector<int> result(n, -1);

    //result
    vector<bool> slot(n, false);

    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = i; // Add job to the result
                slot[j] = true; // Mark this slot as occupied
                break;
            }
        }
    }

    // Print the result
    cout << "Following is the maximum profit sequence of jobs:" << endl;
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            cout << "Job " << jobs[result[i]].id << " ";
        }
    }
    cout << endl;
}

int main() {
    vector<Job> jobs = { {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15} };
    int n = jobs.size();

    jobSequencing(jobs, n);

    return 0;
}