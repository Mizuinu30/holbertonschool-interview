#!/usr/bin/python3
""" Module that contains a function to determine if all boxes can be opened """


def canUnlockAll(boxes):
    # number of boxes
    n = len(boxes)
    # to keep track of unlocked boxes
    unlocked = [False] * n
    unlocked[0] = True  # first box is always unlocked
    # queue to process boxes as they become unlocked
    queue = [0]

    # BFS to traverse through boxes
    while queue:
        current_box = queue.pop(0)
        # iterate over keys in the current unlocked box
        for key in boxes[current_box]:
            # if the key corresponds to a box we haven't unlocked yet
            if key < n and not unlocked[key]:
                unlocked[key] = True
                queue.append(key)

    # if all boxes are unlocked, all entries in 'unlocked' should be True
    return all(unlocked)
