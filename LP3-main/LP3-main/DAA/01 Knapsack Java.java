import java.util.Scanner;

public class Knapsack {

    // Function to solve the 0/1 Knapsack problem using dynamic programming
    public static int knapSack(int W, int[] wt, int[] val, int n) {
        // Create a 2D array to store the maximum profit for each subproblem
        int[][] K = new int[n + 1][W + 1];

        // Build the table K[][] in bottom-up manner
        for (int i = 0; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (i == 0 || w == 0) {
                    K[i][w] = 0;  // Base case: no items or no capacity
                } else if (wt[i - 1] <= w) {
                    // Take the maximum of including or excluding the item
                    K[i][w] = Math.max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
                } else {
                    K[i][w] = K[i - 1][w];  // If item cannot be included, just exclude it
                }
            }
        }

        return K[n][W];  // Return the maximum profit
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // User input for the number of items
        System.out.print("Enter the number of items: ");
        int n = sc.nextInt();

        // Arrays to store the profit and weight of each item
        int[] profit = new int[n];
        int[] weight = new int[n];

        // User input for the profit and weight of each item
        for (int i = 0; i < n; i++) {
            System.out.print("Enter profit of item " + (i + 1) + ": ");
            profit[i] = sc.nextInt();
            System.out.print("Enter weight of item " + (i + 1) + ": ");
            weight[i] = sc.nextInt();
        }

        // User input for the knapsack capacity
        System.out.print("Enter the capacity of the knapsack: ");
        int W = sc.nextInt();

        // Call knapSack function and print the maximum profit
        System.out.println("Maximum profit in knapsack: " + knapSack(W, weight, profit, n));

        sc.close();
    }
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
