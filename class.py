class Cup:
    def __init__(self, color):
        self._color = color    # protected variable
        self.__content = None  # private variable

    def fill(self, beverage):
        self.__content = beverage

    def empty(self):
        self.__content = None

    def __content(self):
        print(self.__content)


redCup = Cup("red")
redCup.fill("i")
print(redCup._Cup__content)
