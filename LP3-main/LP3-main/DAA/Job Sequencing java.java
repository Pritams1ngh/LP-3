import java.util.*;

class Job {
    int id;
    int deadline;
    int profit;

    // Constructor to initialize Job
    Job(int id, int deadline, int profit) {
        this.id = id;
        this.deadline = deadline;
        this.profit = profit;
    }
}

public class JobSequencing {

    // Comparator to sort jobs by profit in descending order
    static class JobComparator implements Comparator<Job> {
        public int compare(Job a, Job b) {
            return Integer.compare(b.profit, a.profit); // Sort in decreasing order of profit
        }
    }

    // Function to perform job sequencing
    public static void jobSequencing(List<Job> jobs, int n) {
        // Sort jobs in decreasing order of profit
        jobs.sort(new JobComparator());

        // Free time slots (initialize with -1 meaning empty)
        int[] result = new int[n];
        Arrays.fill(result, -1);

        // Slots availability
        boolean[] slot = new boolean[n];
        Arrays.fill(slot, false);

        // Iterate through all the jobs
        for (int i = 0; i < n; i++) {
            // Try to find a free slot for this job (start from its deadline)
            for (int j = Math.min(n, jobs.get(i).deadline) - 1; j >= 0; j--) {
                if (!slot[j]) {
                    result[j] = i;     // Assign the job to this slot
                    slot[j] = true;    // Mark this slot as occupied
                    break;
                }
            }
        }

        // Print the result
        System.out.println("Following is the maximum profit sequence of jobs:");
        for (int i = 0; i < n; i++) {
            if (slot[i]) {
                System.out.print("Job " + jobs.get(result[i]).id + " ");
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of jobs: ");
        int n = sc.nextInt();

        List<Job> jobs = new ArrayList<>();

        // Input jobs (id, deadline, profit)
        System.out.println("Enter job ID, deadline, and profit for each job:");
        for (int i = 0; i < n; i++) {
            System.out.print("Job " + (i + 1) + ": ");
            int id = sc.nextInt();
            int deadline = sc.nextInt();
            int profit = sc.nextInt();
            jobs.add(new Job(id, deadline, profit));
        }

        // Call the job sequencing function
        jobSequencing(jobs, n);

        sc.close();
    }
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
