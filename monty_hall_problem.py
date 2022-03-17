from distutils.util import change_root
import random


def monty_hall():
    i, found, not_found = 0, 0, 0

    # if not change
    while i < 100000:
        position = random.randint(1, 3)
        i += 1
        # if not change
        selection = random.randint(1, 3)
        if position == selection:
            found += 1
        else:
            not_found += 1
    print(found, not_found)

    # if change
    i, found, not_found = 0, 0, 0
    while i < 100000:
        position = random.randint(1, 3)
        i += 1
        # if not change
        selection = random.randint(1, 3)
        if position != selection:
            found += 1
        else:
            not_found += 1

    print(found, not_found)


monty_hall()
