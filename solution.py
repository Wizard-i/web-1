def solve():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        
        # Create a list of tuples containing (value, original index)
        indexed_a = [(val, idx) for idx, val in enumerate(a)]
        # Sort based on the values
        sorted_a = sorted(indexed_a, key=lambda x: x[0])
        
        # Create b by assigning the reverse of sorted values
        b = [0] * n
        for i in range(n):
            # The value at position i in b should be (n - i)
            b[sorted_a[i][1]] = n - i
        
        print(' '.join(map(str, b)))

if __name__ == "__main__":
    solve() 