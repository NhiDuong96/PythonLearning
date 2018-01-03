
class MLists():
    def __init__(self):
        self.list = []

    def append(self, x):
        self.list[len(self.list):] = [x]

    def extend(self, iterables):
        self.list[len(self.list):] = iterables

    def insert(self, i, x):
        self.list[i:i] = [x]

    def remove(self, i):
        self.list[i:i + 1] = []

    def pop(self):
        self.remove(len(self.list) - 1)

    def clear(self):
        del self.list[:]

    def reverse(self):
        self.list[:] = self.list[::-1]

    def __str__(self):
        return str(self.list)


list = MLists()
list.append(7)

list.extend([2, 3, 4])
list.insert(2, 6)
# list.remove(2)
# list.pop()
list.reverse()
print(list)
