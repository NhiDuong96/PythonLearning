def integers():
    i = 0
    while True:
        yield i
        i += 1


def take(n, iterables):
    itr = iter(iterables)
    results = []
    try:
        for i in range(n):
            results.append(next(itr))
    except StopIteration as e:
        pass
    return results


def squares():
    for i in integers():
        yield i * i


print(take(4, squares()))

double = (x * 2 for x in integers())

print(take(4, double))
