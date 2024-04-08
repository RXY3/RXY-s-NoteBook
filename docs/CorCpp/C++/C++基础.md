# CPP算法基础与学习
## Vector
### Intro to vector
> vector是一个动态数组，可以在运行时动态的改变数组的大小。
> 其采用连续的线性空间存储元素，可以随机访问其中的元素。这意味着可以进行下标访问，也可以使用迭代器访问。
> 从本质实现上来说，vector是一个模板类，可以存储任意类型的数据。其储存方式是动态分配的，每次新元素的加入，都会重新分配内存空间，将原来的元素复制到新的空间中，然后释放原来的空间。
> vector的容量是指其内部存储空间的大小，而大小是指其内部实际存储的元素的个数。
> vector的容量是指其内部存储空间的大小，而大小是指其内部实际存储的元素的个数。其扩容的方式一般是每次扩容为原来的两倍。
### THE USAGE OF VECTOR
#### 1.创建vector
```cpp
vector<int> v1;
//创建一个空的vector v1
vector<int> v2(10);
//创建一个大小为10的vector v2，其中的元素都是0
vector<int> v3(10,1);
//创建一个大小为10的vector v3，其中的元素都是1
vector<int> v4(v3);
//将v3复制给v4
string s = "hello";
vector<char> s1(s.begin(),s.end());
//创建一个大小为s的vector s1，其中的元素是s的begin到end的元素
vector<int> v5(v3.begin(),v3.end());
//创建一个大小为v3的vector v5，其中的元素是v3的begin到end的元素
//begin和end是迭代器，指向v3的第一个元素和最后一个元素的下一个元素
```
#### 2.访问vector
```cpp
vector<int> v1(10,1);
//创建一个大小为10的vector v1，其中的元素都是1
cout << v1[0] << endl;
//访问v1的第一个元素
```
#### 3.vector函数
1. 容量相关函数
size/capacity
```cpp
vector<int> v1(10,1);
//创建一个大小为10的vector v1，其中的元素都是1
cout << v1.size() << endl;
//输出v1的大小
cout << v1.capacity() << endl;
//输出v1的容量
v1.resize(5);
//将v1的大小改为5
cout << v1.size() << endl;//：5
//输出v1的大小
cout << v1.capacity() << endl;//：10
cout << v1[5]; //：1
```
reserve
> reserve函数可以改变容器的最大容量.使用规则如下：
> 1.假设所给值小于当前容量值什么都不会发生改变
> 2.假如所给值大于当前容容量值扩容至所给值
```cpp
vector<int> v1(10,1);
//创建一个大小为10的vector v1，其中的元素都是1
cout << v1.size() << endl;
//输出v1的大小
cout << v1.capacity() << endl;
//输出v1的容量
v1.reserve(5);
//将v1的容量改为5
cout << v1.size() << endl;//：10
//输出v1的大小
cout << v1.capacity() << endl;//：10
cout << v1[5]; //无任何变化
```
2. 插入删除相关函数

push_back
> push_back函数可以在vector的末尾插入一个元素
```cpp
vector<int> v1(10,1);//创建一个大小为10的vector v1，其中的元素都是
v1.push_back(2);//在v1的末尾插入一个元素2
cout << v1.size() << endl;//：11
cout << v1.capacity() << endl;//：20(扩容2倍)
cout << v1[10]; //：2
```
pop_back
> pop_back函数可以在vector的末尾删除一个元素
```cpp
vector<int> v1(10,1);//创建一个大小为10的vector v1，其中的元素都是
v1.pop_back();//在v1的末尾删除一个元素
cout << v1.size() << endl;//：9
cout << v1.capacity() << endl;//：10
```
insert
> insert函数可以在vector的任意位置插入一个元素
```cpp
vector<int> v1(10,1);//创建一个大小为10的vector v1，其中的元素都是
v1.insert(v1.begin()+5,2);//在v1的第5个元素的位置插入一个元素2
cout << v1.size() << endl;//：11
cout << v1.capacity() << endl;//：20(扩容2倍)
cout << v1[5]; //：2
v.insert(v.begin(),5,10);//我们头插5个10
cout << v.size() << endl;//：16
cout << v.capacity() << endl;//：20(扩容2倍)
```
vector<int>::iterator
> vector<int>::iterator是vector的迭代器，可以用来访问vector中的元素
```cpp
vector<int> v1(10,1);//创建一个大小为10的vector v1，其中的元素都是
vector<int>::iterator it = v1.begin();
//创建一个迭代器it，指向v1的第一个元素
cout << *it << endl;//：1
//输出it指向的元素
it++;
//将it指向下一个元素
cout << *it << endl;//：1
//输出it指向的元素
```
erase
> erase函数可以删除vector中的元素
```cpp
vector<int> v1;//创建一个大小为10的vector v1，其中的元素都是
v.push_back(1);
v.push_back(2);
v.push_back(3);
vector<int>::iterator it = v1.begin();//创建一个迭代器it，指向v1的第一个元素
v1.erase(it);
//删除it指向的元素
cout << v1.size() << endl;//：2
cout << v1.capacity() << endl;//：10
v.erase(v.begin(),v.begin()+2);//删除v的前两个元素
cout << v.size() << endl;//：0
cout << v.capacity() << endl;//：10
```
find
> find函数可以在vector中查找某个元素并返回迭代器
```cpp
vector<int> v1;//创建一个大小为10的vector v1，其中的元素都是
v.push_back(1);
v.push_back(2);
v.push_back(3);
vector<int>::iterator it = v1.begin();//创建一个迭代器it，指向v1的第一个元素
vector<int>::iterator it1 = find(v.begin(),v.end(),2);
//创建一个迭代器it1，指向v中元素2的位置
cout << *it1 << endl;//：2
//输出it1指向的元素
```
### vector的适用场景以及优势
> vector适用于需要随机访问的场景，其优势是可以随机访问，可以在任意位置插入和删除元素，可以动态改变大小。
> vector的缺点是插入和删除元素的效率较低，因为每次插入和删除元素都需要重新分配内存空间，将原来的元素复制到新的空间中，然后释放原来的空间。
> vector的底层实现是数组，所以其在内存中是连续存储的，可以随机访问，但是其在插入和删除元素的时候，需要将插入和删除位置之后的元素都向后或者向前移动，所以效率较低。


# 本文档用于进行每日知识点的记录
## 2023.12.16 ： 为什么不建议使用“using namespace std”？ in cpp
### 1. 什么是using namespace std？
> using namespace std是C++中的一个编译指令，它告诉编译器，后面的代码中如果找不到对应的变量或者函数，就到std这个命名空间中去找。比如，如果你写了一行代码：cout << "Hello World!" << endl;，编译器就会在当前命名空间中查找cout和endl，如果没有找到，就会在std命名空间中查找。如果你使用了using namespace std，那么编译器就不会在当前命名空间中查找了，直接在std命名空间中查找。
> 知识点先导：命名空间(namespace)：
> 命名空间是C++中用来解决命名冲突问题的一种机制。比如，你在自己的程序中定义了一个名为cout的变量，而在std命名空间中也有一个名为cout的变量，这时编译器就不知道你到底是要使用你自己定义的cout变量，还是要使用std命名空间中的cout变量了。这时，你就可以通过命名空间来指定到底使用哪个cout变量。比如，你可以通过std::cout来指定使用std命名空间中的cout变量，通过::cout来指定使用全局命名空间中的cout变量。
### 2. 为什么不建议使用using namespace std？
> 命名空间是为了避免命名冲突而存在的，如果你使用了using namespace std，那么你的程序中所有的命名都直接引用了std命名空间，这就失去了命名空间的意义。比如，你在自己的程序中定义了一个名为cout的变量，而在std命名空间中也有一个名为cout的变量，这时编译器就不知道你到底是要使用你自己定义的cout变量，还是要使用std命名空间中的cout变量了。这时，你就可以通过命名空间来指定到底使用哪个cout变量。比如，你可以通过std::cout来指定使用std命名空间中的cout变量，通过::cout来指定使用全局命名空间中的cout变量。
### 附录：
> 1. 命名空间的写法：
> namespace namespace_name {
> // 代码声明
> }
> 2. 命名空间的使用：
```cpp
#include <iostream>
namespace first_space {
   void func() {
      std::cout << "Inside first_space" << std::endl;
   }
}
namespace second_space {
   void func() {
      std::cout << "Inside second_space" << std::endl;
   }
}
int main () {
   // 调用第一个命名空间中的函数
   first_space::func();
   // 调用第二个命名空间中的函数
   second_space::func();
   return 0;
}
```



