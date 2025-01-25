# 用于记录JavaScript基础知识的学习

## 1. JavaScript简介
JavaScript是一种轻量级的编程语言，是一种解释性的语言。JavaScript是一种基于对象（Object）和事件驱动（Event Driven）的脚本语言，主要应用于网页客户端的开发，可以实现网页的动态效果，交互效果，以及实现一些简单的功能。

## 2. JavaScript的组成
JavaScript由ECMAScript、DOM、BOM三部分组成。
ECMAScript是JavaScript的核心，提供了JavaScript的核心语法。
DOM（Document Object Model）提供了访问和操作网页内容的方法和接口。
BOM（Browser Object Model）提供了与浏览器交互的方法和接口。

## 3. JavaScript的基本语法

### 3.1 变量
JavaScript的变量是松散类型的，可以用var关键字来声明变量，也可以不用var关键字来声明变量。

```javascript
var a = 1;
b = 2;
let c = 3;
var a //此时a的值为1，并不会被丢失
```
ES6中，提出了let和const关键字，let和const关键字声明的变量不会被提升，而且不允许重复声明。
```javascript
var a = 1;
var a = 2;
let b = 3;
let b = 4; //报错
```
也可以使用let关键字来声明变量，let关键字声明的变量只在let命令所在的代码块内有效。
```javascript
var x = 10;
// 这里输出 x 为 10
{ 
    let x = 2;
    // 这里输出 x 为 2
}
// 这里输出 x 为 10
```
let和var之间不能够重复声明变量。


### 3.2 输出
