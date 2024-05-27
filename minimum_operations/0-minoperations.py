#!/usr/bin/python3
""" Module to calculate the minimum number of operations to reach a number """


def minOperations(n):
    """ Function to calculate the minimum number of operations to reach a number """
    if n <= 1:
        return 0
    operations = 0
    i = 2
    while i <= n:
        if n % i == 0:
            operations += i
            n = n / i
        else:
            i += 1
    return operations
