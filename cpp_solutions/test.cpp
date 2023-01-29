/*
 * @Author: QDX
 * @Date: 2023-01-27 13:19:03
 * @Description: 
 */
#include "utils.h"


// int main() {
// 	//后置递增
// 	int a = 10;
// 	a++; //等价于a = a + 1
// 	cout << a << endl; // 11
// 	//前置递增
// 	int b = 10;
// 	++b;
// 	cout << b << endl; // 11
// 	//区别
// 	//前置递增先对变量进行++，再计算表达式
// 	int a2 = 10;
// 	int b2 = ++a2 * 10;
// 	cout << b2 << endl;  // 110
// 	//后置递增先计算表达式，后对变量进行++
// 	int a3 = 10;
// 	int b3 = a3++ * 10;
// 	cout << b3 << endl;  // 100
// 	return 0;
// }

// int main() {

// 	//数组名用途
// 	//1、可以获取整个数组占用内存空间大小
// 	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

// 	cout << "整个数组所占内存空间为： " << sizeof(arr) << endl;  // 40
// 	cout << "每个元素所占内存空间为： " << sizeof(arr[0]) << endl;  // 4
// 	cout << "数组的元素个数为： " << sizeof(arr) / sizeof(arr[0]) << endl;  // 10

// 	//2、可以通过数组名获取到数组首地址
// 	cout << "数组首地址为： " << (long)arr << endl;
// 	cout << "数组中第一个元素地址为： " << (long)&arr[0] << endl;
// 	cout << "数组中第二个元素地址为： " << (long)&arr[1] << endl;

// 	//arr = 100; 错误，数组名是常量，因此不可以赋值
// 	return 0;
// }


// int main() {
// 	//1、指针的定义
// 	int a = 10; //定义整型变量a
	
// 	//指针定义语法： 数据类型 * 变量名 ;
// 	int * p;

// 	//指针变量赋值
// 	p = &a; //指针指向变量a的地址
// 	cout << &a << endl; //打印数据a的地址, 0x16b63b058
// 	cout << p << endl;  //打印指针变量p, 0x16b63b058

// 	//2、指针的使用
// 	//通过*操作指针变量指向的内存
// 	cout << "*p = " << *p << endl;  // 10

//     *p = 20;
//     cout << "*p = " << *p << endl;  // 20
//     cout << &a << " " << a << endl;  // 20

// 	return 0;
// }


int main() {
	//指针变量p指向内存地址编号为0的空间
	int * p = NULL;
	//访问空指针报错 
	//内存编号0 ~255为系统占用内存，不允许用户访问
	cout << *p << endl;
	return 0;
}

