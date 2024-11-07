def fibonacci_iter(n):
    if n <=1:
        return n,1
    steps = 1
    a = 0
    b = 1
    for i in range(2, n+1):
        c = a + b
        a = b
        b = c
        steps += 1
    return c, steps

def fibonacci_recur(n):
    if n <=1:
        return n,1
    fib1, steps1 = fibonacci_recur(n-1)
    fib2, steps2 = fibonacci_recur(n-2)
    return fib1 + fib2, steps1 + steps2 + 1

if __name__ == '__main__':
    n = int(input("Enter a number: "))
    print("Iterative:", fibonacci_iter(n)[0])
    print("Steps:", fibonacci_iter(n)[1])
    print("Recursive:", fibonacci_recur(n)[0])
    print("Steps:", fibonacci_recur(n)[1])

# Enter a number: 5
# Iterative: 5
# Steps: 5
# Recursive: 5
# Steps: 15
