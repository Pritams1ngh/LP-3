#include <iostream>
#include <utility>

using namespace std;

pair<int, int> fibonacci_iter(int n)
{
    if (n <= 1)
    {
        return {n, 1};
    }
    
    int steps = 1;
    int a = 0, b = 1, c = 0;
    
    for (int i = 2; i <= n; ++i)
    {
        c = a + b;
        a = b;
        b = c;
        steps++;
    }
    return {c, steps};
}

pair<int, int> fibonacci_recur(int n)
{
    if(n <= 1)
    {
        return {n, 1};
    }
    
    auto [fib1, steps1] = fibonacci_recur(n - 1); 
    auto [fib2, steps2] = fibonacci_recur(n - 2);
    
    int fibonacci_number = fib1 + fib2;
    int steps = steps1 + steps2 + 1;
    
    return {fibonacci_number, steps};
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    auto [iter_fib, iter_steps] = fibonacci_iter(n);
    cout << "Iterative Fibonacci number: " << iter_fib << endl;
    cout << "Iterative steps: " << iter_steps << endl;
    
    auto [recur_fib, recur_steps] = fibonacci_recur(n);
    cout << "Recursive Fibonacci number: " << recur_fib << endl;
    cout << "Recursive steps: " << recur_steps << endl;
    
    return 0;
}

// Enter a number: 5
// Iterative Fibonacci number: 5
// Iterative steps: 5
// Recursive Fibonacci number: 5
// Recursive steps: 15
