#!/usr/bin/python3
"""Input stats"""
import sys

# Initialize a dictionary to hold HTTP status codes and their counts
stats = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0
}

# Initialize a list to hold file sizes
sizes = [0]


def print_stats():
    """Prints the total file size and count of each status code"""
    print('File size: {}'.format(sum(sizes)))
    for s_code, count in sorted(stats.items()):
        if count:
            print('{}: {}'.format(s_code, count))


try:
    # Enumerate over each line from the standard input
    for i, line in enumerate(sys.stdin, start=1):
        matches = line.rstrip().split()
        try:
            # Extract the status code and file size from the line
            status_code = matches[-2]
            file_size = matches[-1]
            # If the status code is in our dictionary, increment its count
            if status_code in stats.keys():
                stats[status_code] += 1
            # Add the file size to our list
            sizes.append(int(file_size))
        except Exception:
            pass
        # Print the stats every 10 lines
        if i % 10 == 0:
            print_stats()
    # Print the stats at the end
    print_stats()
except KeyboardInterrupt:
    # If the program is interrupted, print the stats before exiting
    print_stats()
    raise
