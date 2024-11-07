class Job:
    def __init__(self, id, deadline, profit):
        self.id = id
        self.deadline = deadline
        self.profit = profit

def job_sequencing(jobs, n):
    
    jobs.sort(key=lambda x: x.profit, reverse=True)

    # To keep track of free time slots
    result = [-1] * n

    # To keep track of the result (sequence of jobs)
    slot = [False] * n

    # Iterate through all given jobs
    for i in range(n):
        # Find a free slot for this job (note that we start from the last possible slot)
        for j in range(min(n, jobs[i].deadline) - 1, -1, -1):
            # Free slot found
            if not slot[j]:
                result[j] = i  # Add this job to the result
                slot[j] = True  # Mark this slot as occupied
                break

    # Print the result
    print("Following is the maximum profit sequence of jobs:")
    for i in range(n):
        if slot[i]:
            print(f"Job {jobs[result[i]].id}", end=" ")
    print()

if __name__ == "__main__":
    jobs = [Job(1, 2, 100), Job(2, 1, 19), Job(3, 2, 27), Job(4, 1, 25), Job(5, 3, 15)]
    n = len(jobs)

    job_sequencing(jobs, n)