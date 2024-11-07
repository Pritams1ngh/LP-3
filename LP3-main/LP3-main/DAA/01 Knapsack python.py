def knapSack(W, wt, val, n):
    # Initialize the DP table with 0 values
    K = [[0 for x in range(W + 1)] for x in range(n + 1)]

    # Build the table K[][] in bottom-up manner
    for i in range(n + 1):
        for w in range(W + 1):
            if i == 0 or w == 0:
                K[i][w] = 0
            elif wt[i-1] <= w:
                # Take the maximum of including or excluding the item
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w])
            else:
                K[i][w] = K[i-1][w]

    return K[n][W]


# Driver code with user input
if __name__ == '__main__':
    n = int(input("Enter the number of items: "))
    
    profit = []
    weight = []

    for i in range(n):
        p = int(input(f"Enter profit of item {i+1}: "))
        w = int(input(f"Enter weight of item {i+1}: "))
        profit.append(p)
        weight.append(w)
    
    W = int(input("Enter the capacity of the knapsack: "))
    
    # Call knapSack function and print the maximum profit
    print("Maximum profit in knapsack: ", knapSack(W, weight, profit, n))

# Enter the number of items: 3
# Enter profit of item 1: 60
# Enter weight of item 1: 10
# Enter profit of item 2: 100
# Enter weight of item 2: 20
# Enter profit of item 3: 120
# Enter weight of item 3: 30
# Enter the capacity of the knapsack: 50
# Maximum profit in knapsack:  220
