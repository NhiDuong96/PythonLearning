def ld(x): return [a for a in range(x)]


def f(ham: str, eggs: str = 'eggs')->str:
    print(f.__annotations__)
    print(ham)


squares = list(map(lambda x: x * 2, range(10)))
print(squares)


print(b(5))
'''
a = [(x, y) for x in [1, 2, 3] for y in[3, 1, 2] if x != y]
print(a)
a = [[1, 2], [2, 3]]
b = [x for y in a for x in y]
print(b)
'''
