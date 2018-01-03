class SingletonMeta(type):
    def __init__(self, *args, **kwargs):
        self._instance = None
        super(SingletonMeta, self).__init__(*args, **kwargs)

    def __call__(self, *args, **kwargs):
        print("call")
        if not self._instance:
            self._instance = super(SingletonMeta, self).__call__(*args, **kwargs)
        return self._instance


class Person(metaclass=SingletonMeta):

    def __init__(self):
        self.name = 'kiennt'
        self.age = 26


a = Person()
print(a.name)  # kiennt
print(a.age)  # 26
b = Person()
print(b == a)  # True
