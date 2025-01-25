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
L2 = list(map(normalize, L1))
print(L2)  # 输出: ['Adam', 'Lisa', 'Bart']
```

#### 3.1.3 filter()函数
`filter()`函数用于过滤序列，接收一个函数和一个序列，返回一个迭代器。该函数会依次作用于序列的每个元素，根据返回值是`True`还是`False`决定保留还是丢弃该元素。

```python
def is_odd(n):
    return n % 2 == 1

list(filter(is_odd, [1, 2, 3, 4, 5, 6]))  # [1, 3, 5]
```

## 4. 装饰器（Decorator）
装饰器是Python中的一个重要概念，它可以在不修改原函数的情况下，为函数增加新的功能。

### 4.1 装饰器的基本使用
```python
def log(func):
    def wrapper(*args, **kw):
        print('call %s():' % func.__name__)
        return func(*args, **kw)
    return wrapper

@log
def now():
    print('2024-3-20')

# 调用now()函数，实��上相当于调用log(now)
now()  # 输出：call now(): \n 2024-3-20
```

### 4.2 带参数的装饰器
```python
def log(text):
    def decorator(func):
        def wrapper(*args, **kw):
            print('%s %s():' % (text, func.__name__))
            return func(*args, **kw)
        return wrapper
    return decorator

@log('execute')
def now():
    print('2024-3-20')
```

## 5. 面向对象编程（OOP）
### 5.1 类和实例
```python
class Student(object):
    def __init__(self, name, score):
        self.name = name
        self.score = score
    
    def print_score(self):
        print('%s: %s' % (self.name, self.score))

# 创建实例
bart = Student('Bart Simpson', 59)
bart.print_score()
```

### 5.2 访问限制
在Python中，以双下划线开头的属性是私有属性，不能直接访问：
```python
class Student(object):
    def __init__(self, name, score):
        self.__name = name
        self.__score = score
    
    def get_name(self):
        return self.__name
    
    def set_score(self, score):
        if 0 <= score <= 100:
            self.__score = score
        else:
            raise ValueError('invalid score')
```

### 5.3 继承和多态
```python
class Animal(object):
    def run(self):
        print('Animal is running...')

class Dog(Animal):
    def run(self):
        print('Dog is running...')

class Cat(Animal):
    def run(self):
        print('Cat is running...')
```
这里可以看到，子类可以继承父类的属性和方法，并且可以重写父类的方法。



## 6. 异常处理
### 6.1 try...except...finally
```python
try:
    print('try...')
    r = 10 / 0
except ZeroDivisionError as e:
    print('except:', e)
finally:
    print('finally...')
```

### 6.2 自定义异常
```python
class CustomError(Exception):
    def __init__(self, message):
        self.message = message

try:
    raise CustomError('This is a custom error')
except CustomError as e:
    print(e.message)
```

## 7. 文件操作
### 7.1 读写文件
```python
# 读取文件
with open('test.txt', 'r', encoding='utf-8') as f:
    content = f.read()

# 写入文件
with open('test.txt', 'w', encoding='utf-8') as f:
    f.write('Hello, world!')
```

## 8. 模块和包（Modules and Packages）

### 8.1 模块基础
模块是一个包含Python代码的文件，以.py结尾。使用模块可以让我们更好地组织代码，实现代码复用。

#### 8.1.1 导入模块
```python
# 方式1：导入整个模块
import math
print(math.pi)  # 3.141592653589793

# 方式2：导入特定函数或变量
from math import pi, sqrt
print(pi)  # 3.141592653589793

# 方式3：导入所有内容（不推荐）
from math import *

# 方式4：使用别名
import math as m
print(m.pi)
```

#### 8.1.2 创建自己的模块
```python
# mymodule.py
def greeting(name):
    return f"Hello, {name}!"

PI = 3.14159

class Calculator:
    def add(self, x, y):
        return x + y
```

```python
# main.py
import mymodule

print(mymodule.greeting("Alice"))
print(mymodule.PI)
calc = mymodule.Calculator()
```

### 8.2 包（Package）
包是一种管理Python模块命名空间的方式，本质上是一个含有特殊文件__init__.py的目录。

#### 8.2.1 包的结构
```
mypackage/
    __init__.py
    module1.py
    module2.py
    subpackage/
        __init__.py
        module3.py
```

#### 8.2.2 创建和使用包
```python
# mypackage/__init__.py
from .module1 import function1
from .module2 import function2

# mypackage/module1.py
def function1():
    return "This is function1"

# 使用包
from mypackage import function1
from mypackage.module2 import function2
```

### 8.3 常用内置模块
```python
# os模块 - 操作系统接口
import os
print(os.getcwd())  # 获取当前工作目录
os.mkdir("new_directory")  # 创建新目录

# sys模块 - 系统相关参数和函数
import sys
print(sys.path)  # Python的搜索路径
print(sys.version)  # Python版本信息

# datetime模块 - 日期和时间处理
from datetime import datetime, timedelta
now = datetime.now()
future = now + timedelta(days=1)
```

## 9. 正则表达式（Regular Expression）

### 9.1 基础语法
```python
import re

# 基本匹配
text = "The quick brown fox"
pattern = r"fox"
result = re.search(pattern, text)
print(result.group())  # 输出: fox

# 常用元字符
# . 匹配任意字符（除换行符外）
# ^ 匹配字符串开始
# $ 匹配字符串结束
# * 匹配0次或多次
# + 匹配1次或多次
# ? 匹配0次或1次
# [] 字符集
# [^] 否定字符集
# {} 指定重复次数
```

### 9.2 常用函数
```python
import re

text = "The quick brown fox jumps over the lazy dog"

# re.match() - 从字符串开始匹配
result = re.match(r"The", text)
print(result.group())  # The

# re.search() - 搜索整个字符串中的第一个匹配
result = re.search(r"fox", text)
print(result.group())  # fox

# re.findall() - 找到所有匹配
text = "The price is $10.99, $20.50 and $5.00"
prices = re.findall(r"\$\d+\.\d+", text)
print(prices)  # ['$10.99', '$20.50', '$5.00']

# re.sub() - 替换匹配的文本
text = "I love cats, cats are cute"
new_text = re.sub(r"cats", "dogs", text)
print(new_text)  # I love dogs, dogs are cute
```

### 9.3 常用正则表达式模式

#### 9.3.1 匹配邮箱
```python
email_pattern = r'^[\w\.-]+@[\w\.-]+\.\w+$'
email = "user@example.com"
if re.match(email_pattern, email):
    print("Valid email")
```

#### 9.3.2 匹配手机号码（中国）
```python
phone_pattern = r'^1[3-9]\d{9}$'
phone = "13812345678"
if re.match(phone_pattern, phone):
    print("Valid phone number")
```

#### 9.3.3 匹配URL
```python
url_pattern = r'https?://(?:[\w-]+\.)+[\w-]+(?:/[\w-./?%&=]*)?'
url = "https://www.example.com/path?param=value"
if re.match(url_pattern, url):
    print("Valid URL")
```

### 9.4 正则表达式分组
```python
# 使用()进行分组
text = "John Smith"
pattern = r"(\w+)\s+(\w+)"
match = re.match(pattern, text)
if match:
    first_name = match.group(1)  # John
    last_name = match.group(2)   # Smith
    
# 命名分组
pattern = r"(?P<first>\w+)\s+(?P<last>\w+)"
match = re.match(pattern, text)
if match:
    first_name = match.group('first')  # John
    last_name = match.group('last')    # Smith
```

### 9.5 正则表达式修饰符
```python
# re.IGNORECASE 或 re.I - 忽略大小写
text = "Python programming"
pattern = r"python"
result = re.search(pattern, text, re.IGNORECASE)

# re.MULTILINE 或 re.M - 多行模式
text = """First line
Second line
Third line"""
pattern = r"^Second"
result = re.search(pattern, text, re.MULTILINE)

# re.DOTALL 或 re.S - 点号匹配所有字符（包括换行符）
text = """First line
Second line"""
pattern = r"First.*Second"
result = re.search(pattern, text, re.DOTALL)
```

## 10. 网络编程（Network Programming）

### 10.1 TCP/IP基础
TCP/IP是互联网最基本的协议。TCP协议是建立可靠连接，而IP协议是找到对���。

### 10.2 Socket编程

#### 10.2.1 TCP编程
服务器端：
```python
import socket

# 创建Socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 绑定地址和端口
s.bind(('127.0.0.1', 9999))

# 监听端口
s.listen(5)
print('等待客户端连接...')

while True:
    # 接受一个新连接
    sock, addr = s.accept()
    # 创建新线程来处理TCP连接
    t = threading.Thread(target=handle_client, args=(sock, addr))
    t.start()

def handle_client(sock, addr):
    print(f'接受来自 {addr} 的连接')
    
    while True:
        data = sock.recv(1024)
        if not data:
            break
        sock.send(('Hello, %s!' % data.decode('utf-8')).encode('utf-8'))
    
    sock.close()
    print('Connection from %s closed.' % addr)
```

客户端：
```python
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('127.0.0.1', 9999))

# 发送数据
s.send(b'World')
# 接收数据
print(s.recv(1024).decode('utf-8'))

s.close()
```

#### 10.2.2 UDP编程
服务器端：
```python
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(('127.0.0.1', 9999))

print('等待接收数据...')
while True:
    data, addr = s.recvfrom(1024)
    print(f'接收到来自 {addr} 的数据：{data.decode("utf-8")}')
    s.sendto(b'Hello, %s!' % data, addr)
```

客户端：
```python
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
for data in [b'Michael', b'Tracy', b'Sarah']:
    s.sendto(data, ('127.0.0.1', 9999))
    print(s.recv(1024).decode('utf-8'))

s.close()
```

### 10.3 HTTP编程

#### 10.3.1 使用requests库
```python
import requests

# GET请求
r = requests.get('https://api.github.com/user', auth=('user', 'pass'))
print(r.status_code)
print(r.headers['content-type'])
print(r.encoding)
print(r.text)

# POST请求
r = requests.post('http://httpbin.org/post', data={'key': 'value'})

# 其他HTTP方法
r = requests.put('http://httpbin.org/put', data={'key': 'value'})
r = requests.delete('http://httpbin.org/delete')
r = requests.head('http://httpbin.org/get')
r = requests.options('http://httpbin.org/get')
```

## 11. 并发编程（Concurrent Programming）

### 11.1 多线程（Threading）

#### 11.1.1 创建线程
```python
import threading
import time

def worker():
    print(f'线程 {threading.current_thread().name} 开始')
    time.sleep(2)
    print(f'线程 {threading.current_thread().name} 结束')

# 创建线程
t = threading.Thread(target=worker)
t.start()  # 启动线程
t.join()   # 等待线程结束
```

#### 11.1.2 线程同步
```python
import threading

# 创建锁
lock = threading.Lock()

# 使用锁
lock.acquire()  # 获取锁
try:
    # 这里是临界区
    pass
finally:
    lock.release()  # 释放锁

# 使用with语句更优雅
with lock:
    # 这里是临界区
    pass
```

#### 11.1.3 线程通信
```python
import queue
import threading

# 创建队列
q = queue.Queue()

def producer():
    for i in range(5):
        q.put(i)
        print(f'生产者生产: {i}')
        time.sleep(1)

def consumer():
    while True:
        item = q.get()
        print(f'消费者消费: {item}')
        q.task_done()

# 创建生产者和消费者线程
producer_thread = threading.Thread(target=producer)
consumer_thread = threading.Thread(target=consumer)

producer_thread.start()
consumer_thread.start()

# 等待队列清空
q.join()
```

### 11.2 多进程（Multiprocessing）

#### 11.2.1 创建进程
```python
from multiprocessing import Process

def worker(name):
    print(f'进程 {name} 开始工作')
    
if __name__ == '__main__':
    p = Process(target=worker, args=('worker1',))
    p.start()
    p.join()
```

#### 11.2.2 进程池
```python
from multiprocessing import Pool
import time

def task(x):
    time.sleep(1)
    return x * x

if __name__ == '__main__':
    # 创建包含4个进程的进程池
    with Pool(4) as p:
        # 使用map
        results = p.map(task, range(10))
        print(results)
```

#### 11.2.3 进程间通信
```python
from multiprocessing import Process, Pipe

def sender(conn):
    conn.send(['Hello', 42, dict(name='John')])
    conn.close()

def receiver(conn):
    print(conn.recv())
    conn.close()

if __name__ == '__main__':
    parent_conn, child_conn = Pipe()
    p1 = Process(target=sender, args=(parent_conn,))
    p2 = Process(target=receiver, args=(child_conn,))
    
    p1.start()
    p2.start()
    
    p1.join()
    p2.join()
```

### 11.3 异步IO（asyncio）

#### 11.3.1 基本用法
```python
import asyncio

async def main():
    print('Hello')
    await asyncio.sleep(1)
    print('World')

# Python 3.7+
asyncio.run(main())
```

#### 11.3.2 并发任务
```python
import asyncio
import time

async def say_something(delay, what):
    await asyncio.sleep(delay)
    print(what)

async def main():
    print(f"started at {time.strftime('%X')}")
    
    await asyncio.gather(
        say_something(1, 'hello'),
        say_something(2, 'world')
    )
    
    print(f"finished at {time.strftime('%X')}")

asyncio.run(main())
```

#### 11.3.3 异步上下文管理器
```python
import asyncio

class AsyncContextManager:
    async def __aenter__(self):
        print('entering context')
        await asyncio.sleep(1)
        return self
    
    async def __aexit__(self, exc_type, exc_val, exc_tb):
        print('exiting context')
        await asyncio.sleep(1)

async def main():
    async with AsyncContextManager():
        print('in context')

asyncio.run(main())
```