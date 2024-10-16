# Fundamental Python
It is a record of Python basics.
## 1. 生成器（Generator）
### 1.1 生成器的定义
生成器是一种特殊的迭代器，它的元素是按需生成的，而不是一次性生成所有元素。
### 1.2 生成器的创建
生成器可以通过生成器表达式或生成器函数创建。
#### 1.2.1 生成器表达式
生成器表达式是一种类似于列表推导的生成器创建方式，它的语法为：
```python
(generator_expression)
```
生成器表达式的语法与列表推导的语法类似，只是将中括号`[]`改为圆括号`()`，并且生成器表达式返回的是一个生成器对象，而不是列表。
```python
# 生成器表达式
gen = (x for x in range(5))
for i in gen:
    print(i)
```
生成器表达式的优点是简洁，但是只能用于生成简单的生成器，如果生成器的生成逻辑较为复杂，建议使用生成器函数。
#### 1.2.2 生成器函数
生成器函数是一种定义生成器的函数，它的语法为：
```python
def generator_function():
    yield value
```
生成器函数使用`yield`语句产生元素，每次调用生成器的`__next__()`方法时，生成器函数会从上一次`yield`语句的位置继续执行，直到遇到下一个`yield`语句或函数结束。
```python
# 生成器函数
def generator_function():
    for i in range(5):
        yield i
```
        
生成器函数的优点是灵活，可以生成复杂的生成器，但是需要显式地使用`yield`语句产生元素。  
如果一个函数定义中包含yield关键字，那么这个函数就不再是一个普通函数，而是一个generator函数，调用一个generator函数将返回一个generator：  
generator对象的值为yield的值，当generator函数执行到yield时，会暂停执行，返回yield的值，并保留函数的状态，下次调用时会从yield的下一行继续执行。  
```python
>>> g = generator_function()
>>> g
<generator object generator_function at 0x0000021D3D3A3F90>
>>> next(g)
0
>>> next(g)
1
```

### 1.3 生成器的应用
生成器可以用于迭代器的场景，例如遍历文件、遍历数据库查询结果等。生成器还可以用于实现协程，实现异步编程。

### 1.4 生成器一些具体使用
#### 1.4.1 斐波那契数列
```python
def fibonacci(n):
    a, b = 0, 1
    for _ in range(n):
        yield a
        a, b = b, a + b
```
#### 1.4.2 杨辉三角
```python
def triangles():
    L=[1]
    while 1:
        yield L
        L=[1] + [L[i] + L[i + 1] for i in range(len(L) - 1)] + [1]
```

### 1.5 生成器的特点
1. 惰性计算：生成器的元素是按需生成的，只有在需要时才会生成元素，可以节省内存。
2. 可迭代：生成器是一种迭代器，可以使用`for`循环遍历生成器的元素。
3. 单向性：生成器只能向前迭代，不能回退。
4. 状态保存：生成器函数会保存生成器的状态，每次调用生成器的`__next__()`方法时，生成器函数会从上一次`yield`语句的位置继续执行。
5. 生成器使用一次后即失效，不能重复使用。

## 2. 迭代器（Iterator）
可以直接作用于`for`循环的对象统称为可迭代对象：Iterable。  
可以使用isinstance()判断一个对象是否是Iterable对象。
```python
from collections.abc import Iterable
isinstance([], Iterable)
```
```python
>>> from collections.abc import Iterator
>>> isinstance((x for x in range(10)), Iterator)
True
>>> isinstance([], Iterator)
False
>>> isinstance({}, Iterator)
False
>>> isinstance('abc', Iterator)
False
```
生成器都是Iterator对象，但list、dict、str虽然是Iterable，却不是Iterator。  
这是因为Python的Iterator对象表示的是一个数据流，Iterator对象可以被next()函数调用并不断返回下一个数据，直到没有数据时抛出StopIteration错误。可以把这个数据流看做是一个有序序列，但我们却不能提前知道序列的长度，只能不断通过next()函数实现按需计算下一个数据，所以Iterator的计算是惰性的，只有在需要返回下一个数据时它才会计算。  


## 3. 函数式编程（Functional Programming）
函数式编程是一种编程范式，它将计算过程视为数学函数的求值，避免使用变量和可变状态。函数式编程的核心思想是函数，函数是一等公民，可以作为参数传递、作为返回值返回、赋值给变量等。函数式编程具有以下特点：  
1. 不可变性：函数式编程避免使用可变状态，所有数据都是不可变的，函数不会改变外部状态。
2. 纯函数：函数式编程的函数是纯函数，即相同的输入始终得到相同的输出，不产生副作用。
3. 无状态：函数式编程避免使用状态，函数的输出仅取决于输入，不依赖于外部状态。
4. 递归：函数式编程使用递归代替循环，避免使用可变状态。

### 3.1 高阶函数（Higher-order Function）
高阶函数是一种函数，它接收一个或多个函数作为参数，返回一个函数。高阶函数可以用于抽象通用的计算过程，提高代码的复用性。常见的高阶函数有`map()`、`filter()`、`reduce()`等。  

我们可以通过对于函数本身的操作，来实现对于函数的操作。  
```python
>>> def add(x, y, f):
...     return f(x) + f(y)
...
>>> add(-5, 6, abs)
11
```
由此可见，函数名也是一个变量，可以指向函数。     
如果一个函数可以接受另一个函数作为参数，这种函数就称之为高阶函数。  

#### 3.1.1 map()函数
`map()`函数接收一个函数和一个可迭代对象，将函数依次作用于可迭代对象的每个元素，返回一个新的可迭代对象。`map()`函数的语法为：
```python
map(function, iterable)
```
`map()`函数的返回值是一个`map`对象，可以使用`list()`函数将其转换为列表。
```python
# map()函数
def square(x):
    return x ** 2

result = map(square, [1, 2, 3, 4, 5])
print(list(result)) # [1, 4, 9, 16, 25]
```

#### 3.1.2 reduce()函数
`reduce()`函数接收一个函数和一个可迭代对象，将函数依次作用于可迭代对象的每个元素，返回一个累积的结果。`reduce()`函数的语法为：
```python
reduce(function, iterable)
```
`reduce()`函数需要通过`from functools import reduce`导入。
```python
# reduce()函数
from functools import reduce

def add(x, y):
    return x + y

result = reduce(add, [1, 2, 3, 4, 5])
print(result) # 15
```

插入知识点：
> 字典 {} : 无序的键值对集合，键值对之间用逗号分隔，键和值之间用冒号分隔，键必须是唯一的，值可以重复。
```python
>>> d = {'Michael': 95, 'Bob': 75, 'Tracy': 85}
>>> d['Michael']
95
```
 
```python
def normalize(name):
    if name[0].isupper() and name[1:].islower():
        return name
    else:
        return name[0].upper() + name[1:].lower()
L1 = ['adam', 'LISA', 'barT']




