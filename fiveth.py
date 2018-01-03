def exec(callback):
    c = None
    a = 5
    b = 0
    try:
        c = callback(a, b)
    except ZeroDivisionError as e:
        print(e)
    else:
        print(c)
    finally:
        return c


def func(a, b):
    return a / b


exec(func)


def exec2():
    a = 5
    b = 0
    try:
        yield a, b
    except ZeroDivisionError as e:
        print(e)
    else:
        pass
    finally:
        print("finally")


for a, b in exec2():
    c = a / b
    print(c)
