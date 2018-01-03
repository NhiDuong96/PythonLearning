import abc


class Subject:
    def __init__(self):
        self._observers = set()
        self._subject_state = None

    def attach(self, observer):
        observer._subject = self
        self._observers.add(observer)

    def _notifyAll(self):
        for ob in self._observers:
            ob.update()

    @property
    def subject_state(self):
        return self._subject_state

    @subject_state.setter
    def subject_state(self, arg):
        self._subject_state = arg
        self._notifyAll()


class Observer(metaclass=abc.ABCMeta):
    def __init__(self, state):
        self._subject = None
        self._state = state

    @abc.abstractmethod
    def update(self):
        pass


class Div(Observer):
    def update(self):
        self._state = self._subject.subject_state / self._state
        print(self._state)


class Mul(Observer):
    def update(self):
        self._state = self._subject.subject_state * self._state
        print(self._state)


def main():
    subject = Subject()
    div = Div(4)
    mul = Mul(3)
    subject.attach(mul)
    subject.attach(div)
    subject.subject_state = 8


if __name__ == "__main__":
    main()
