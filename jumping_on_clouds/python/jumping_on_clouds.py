class cloud:
    def __init__(self, i):
        self.value = i
        self.one, self.two = None, None

    def get_value(self):
        return self.value

    def set_one(self, cl):
        self.one = cl

    def set_two(self, cl):
        self.two = cl

def build_binary_graph(clouds, i):
    n = cloud(clouds[i])
    if(len(clouds) - 2) > i:
        n.set_two(build_binary_graph(clouds, i + 2))
        if(n.two.get_value() == 1):
            n.set_one(build_binary_graph(clouds, i + 1))
    elif(len(clouds) - 1) > i:
        n.set_one(build_binary_graph(clouds, i + 1))
    return n

def greedy_search(n):
    if(not(n.two == None)) and (n.two.get_value() == 0):
        return 1 + greedy_search(n.two)
    elif(not(n.one == None)) and (n.one.get_value() == 0):
        return 1 + greedy_search(n.one)
    else:
        return 0

if __name__ == "__main__":
    clouds = [0, 1, 0, 0, 1, 0, 1, 0 ,1, 0, 0, 1, 0]
    head = build_binary_graph(clouds, 0)

    print("Minimum # of jumps: {}".format(greedy_search(head)))
