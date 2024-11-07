import java.util.*;

class Item {
    int profit;
    int weight;

    // Constructor to initialize profit and weight
    Item(int profit, int weight) {
        this.profit = profit;
        this.weight = weight;
    }
}

public class FractionalKnapsack {

    // Function to calculate the maximum value in the knapsack
    public static double fractionalKnapsack(int w, List<Item> arr) {
        // Sort items based on profit/weight ratio in descending order
        arr.sort((a, b) -> Double.compare((double)b.profit / b.weight, (double)a.profit / a.weight));

        double finalValue = 0.0;

        // Process the sorted items
        for (Item item : arr) {
            if (w >= item.weight) {
                finalValue += item.profit;
                w -= item.weight;
            } else {
                finalValue += item.profit * ((double) w / item.weight);
                break;
            }
        }

        return finalValue;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of items: ");
        int n = sc.nextInt();

        List<Item> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            System.out.print("Enter profit of item " + (i + 1) + ": ");
            int profit = sc.nextInt();
            System.out.print("Enter weight of item " + (i + 1) + ": ");
            int weight = sc.nextInt();
            arr.add(new Item(profit, weight));
        }

        System.out.print("Enter capacity of knapsack: ");
        int w = sc.nextInt();

        // Calculate and print the maximum value in the knapsack
        System.out.println("Maximum value in knapsack: " + fractionalKnapsack(w, arr));

        sc.close();
    }
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
