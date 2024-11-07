import java.util.Scanner;

// Helper class to store Fibonacci number and step count
class FibonacciResult {
    int fibonacciNumber;
    int steps;

    FibonacciResult(int fibonacciNumber, int steps) {
        this.fibonacciNumber = fibonacciNumber;
        this.steps = steps;
    }
}

public class FibonacciCalculator {

    // Iterative Fibonacci function
    public static FibonacciResult fibonacciIter(int n) {
        if (n <= 1) {
            return new FibonacciResult(n, 1);
        }

        int steps = 1;
        int a = 0, b = 1, c = 0;

        for (int i = 2; i <= n; ++i) {
            c = a + b;
            a = b;
            b = c;
            steps++;
        }

        return new FibonacciResult(c, steps);
    }

    // Recursive Fibonacci function
    public static FibonacciResult fibonacciRecur(int n) {
        if (n <= 1) {
            return new FibonacciResult(n, 1);
        }

        FibonacciResult fib1 = fibonacciRecur(n - 1);
        FibonacciResult fib2 = fibonacciRecur(n - 2);

        int fibonacciNumber = fib1.fibonacciNumber + fib2.fibonacciNumber;
        int steps = fib1.steps + fib2.steps + 1; // +1 for the current call

        return new FibonacciResult(fibonacciNumber, steps);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        
        // Input validation
        while (!scanner.hasNextInt()) {
            System.out.print("Please enter a valid integer: ");
            scanner.next();
        }
        
        int n = scanner.nextInt();
        
        if (n < 0) {
            System.out.println("Please enter a non-negative integer.");
            scanner.close();
            return;
        }

        // Calculate Fibonacci iteratively
        FibonacciResult iterResult = fibonacciIter(n);
        System.out.println("Iterative Fibonacci number: " + iterResult.fibonacciNumber);
        System.out.println("Iterative steps: " + iterResult.steps);

        // Calculate Fibonacci recursively
        FibonacciResult recurResult = fibonacciRecur(n);
        System.out.println("Recursive Fibonacci number: " + recurResult.fibonacciNumber);
        System.out.println("Recursive steps: " + recurResult.steps);

        scanner.close();
    }
}

// Enter a number: 5
// Iterative Fibonacci number: 5
// Iterative steps: 5
// Recursive Fibonacci number: 5
// Recursive steps: 15
