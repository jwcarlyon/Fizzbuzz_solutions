def sock_lord(sequence):
    sequence.sort() #python uses an algorithm called Timsort which is
    # related to merge sort and insertion sort. Here is an informational link:
    # https://stackoverflow.com/questions/10948920/what-algorithm-does-pythons-sorted-use
    last = sequence[0]
    pairs = 0
    count = 0

    for x in sequence:
        if last == x:
            count += 1
        else:
            last = x
            pairs += int(count / 2)
            count = 1

    return pairs
if __name__ == "__main__":
    # execute only if run as a script, meaning this file is run from the command line
    # otherwise the above method declarations are the only script that runs - like "import sock_lord"
    sequence = [3, 3, 1, 1, 6, 2, 4, 8, 5, 3, 4, 6, 7, 8, 4, 2, 5, 7, 7]
    #sequence = [5, 5, 5, 9, 8, 7, 6, 5];
    print("Number of pairs: {}".format(sock_lord(sequence)))
