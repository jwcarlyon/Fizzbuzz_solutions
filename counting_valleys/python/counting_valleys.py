def count_valleys(str):
    above = True
    pos = 0
    valleys = 0
    for x in str:
        if(x == 'U'):
            pos += 1
        if(x == 'D'):
            pos -= 1
        if((pos < 0) and above):
            above = False
        elif((pos >= 0) and not(above)):
            above = True
            valleys += 1
    return valleys

if __name__ == "__main__":
    # execute only if run as a script
    case0 = "UUDUDDDDUUUDDDDUUU";
    print("Number of valleys traversed: {}".format(count_valleys(case0)))
