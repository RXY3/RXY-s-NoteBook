#  a doc to rush python basics

# Class
class Test:
    def __init__(self, name):
        self.name = name
        self.number = 0

    def say_hello(self):
        print(f'Hello {self.name}!')
        self.number += 1
    
    def say_goodbye(self):
        print(f'Goodbye {self.name}!')
        self.number += 1
    def get_number(self):
        return self.number
    
# Function
def main():
    """
    >>> test = Test('Python')
    >>> test.say_hello()
    Hello Python!
    >>> test.say_goodbye()
    Goodbye Python!
    >>> print(f'Number of times called: {test.get_number()}')
    Number of times called: 2
    """
    # test = Test('Python')
    # test.say_hello()
    # test.say_goodbye()
    # print(f'Number of times called: {test.get_number()}')
from doctest import testmod
if __name__ == '__main__':
    testmod()
    print(1)
    print(1/2)
    print(1//2)