def repeated_string(s, n):
    if len(s) > n:
        return s[:n].count('a')
    while (len(s) < n):
        s += s
    return s[:n].count('a')

if __name__ == "__main__":
    s = "aba"
    print("Number of occurrences: " + str(repeated_string(s, 10)))
