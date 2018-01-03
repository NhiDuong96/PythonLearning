matrix = [
    [1, 2, 3, 4],
    [2, 3, 4, 5]
]


def T(matrix):
    return [[row[i] for row in matrix] for i in range(len(matrix[0]))]


def zip(*iterables):
    sentinel = object()
    iterators = [iter(it) for it in iterables]
    while iterators:
        result = []
        for it in iterators:
            elem = next(it, sentinel)
            if elem is sentinel:
                return
            result.append(elem)
        yield tuple(result)


print(list(zip(*matrix)))
print(T(matrix))

a = [1, 2]
b = iter(a)
print(next(b))
