def exec(a, b, oper):
    return oper(a, b)


def add(a, b):
    return a + b


def sub(a, b):
    return a - b


print(exec(3, 2, sub))

#------------------#
import abc


class Strategy(metaclass=abc.ABCMeta):
    @abc.abstractmethod
    def oper(a, b):
        pass


class Add(Strategy):
    def oper(self, a, b):
        return a + b


class Sub(Strategy):
    def oper(self, a, b):
        return a - b


class Context(object):
    def __init__(self, strategy):
        self.strategy = strategy

    def exec(self, a, b):
        return self.strategy.oper(a, b)


def main():
    add = Add()
    sub = Sub()
    con = Context(sub)
    print(con.exec(3, 4))


if __name__ == "__main__":
    main()
