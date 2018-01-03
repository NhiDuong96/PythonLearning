
from itertools import islice
# generators expression
g1 = (x for x in range(10))
print(next(g1))


# generators function
def generators():
    for i in range(10):
        yield i


class integers(object):
    """docstring for fibo"""

    def __init__(self):
        self.a = -1

    def __iter__(self):
        return self

    def __next__(self):
        self.a += 1
        return self.a


f = integers()
print(type(f))
print(list(islice(f, 0, 10)))
