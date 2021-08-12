#!/usr/bin/python3
"""
This is the 0-minoperations.py module.
"""

def minOperations(n):
    """
    find the prime factorization of n
    """

    if (n <= 0):
        return 0

    prime_factors = []
    while n % 2 == 0:
        prime_factors.append(2)
        n = n / 2
    for i in range(3, int(n ** 0.5) + 1, 2):
        while n % i == 0:
            prime_factors.append(i)
            n = n / i
    if n > 2:
        prime_factors.append(n)
    return int(sum(prime_factors))
