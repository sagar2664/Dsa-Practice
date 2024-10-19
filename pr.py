MOD = 998244353

# Function to compute modular inverse using Fermat's Little Theorem
def mod_inverse(a, m):
    return pow(a, m - 2, m)

def calculate_days(W, G, L):
    # dp array to store the expected number of days for each weight
    dp = [0] * (W + G + L + 1)
    
    # Base case: if we reach G, 0 days are needed
    dp[G] = 0

    # Traverse the weights from G + 1 up to W + L and compute dp
    for w in range(G + 1, W + L + 1):
        if w == W + L:
            dp[w] = 1 + dp[w - 1]  # Forced to lose weight at the maximum weight
        else:
            dp[w] = 1 + 0.5 * (dp[w - 1] + dp[w + 1])

    # Traverse from W down to G to get the expected number of days starting at W
    for w in range(W - 1, G - 1, -1):
        dp[w] = 1 + 0.5 * (dp[w - 1] + dp[w + 1])

    # Return the expected number of days for starting at weight W
    p = dp[W] * 2  # We need to multiply the probability by 2 to get p/q format
    q = 2  # Since the probability is always in halves, q = 2
    return int(p), q

# Read input
T = int(input())  # Number of test cases
for case_num in range(1, T + 1):
    W, G, L = map(int, input().split())
    
    # Calculate the expected number of days
    p, q = calculate_days(W, G, L)
    
    # Calculate the modular result
    q_inv = mod_inverse(q, MOD)
    result = (p * q_inv) % MOD
    
    # Output the result
    print(f"Case #{case_num}: {result}")
