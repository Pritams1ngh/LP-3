#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

// Compare jobs by profit
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobSequencing(vector<Job>& jobs, int n) {
    // Sort in decreasing order of profit
    sort(jobs.begin(), jobs.end(), compare);

    // Free time slots
    vector<int> result(n, -1);

    // Result slots
    vector<bool> slot(n, false);

    for (int i = 0; i < n; i++) {
        // Find a free slot for this job, from its deadline down to 0
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = i;      // Add job to the result
                slot[j] = true;     // Mark this slot as occupied
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
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter job ID, deadline, and profit for each job:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << ": ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    jobSequencing(jobs, n);

    return 0;
}

// Enter the number of jobs: 5
// Enter job ID, deadline, and profit for each job:
// Job 1: 1 2 100
// Job 2: 2 1 19
// Job 3: 3 2 27
// Job 4: 4 1 25
// Job 5: 5 3 15
// Following is the maximum profit sequence of jobs:
// Job 3 Job 1 Job 5 
