#pragma once
#include<iostream>
using namespace std;
const int maxlength=500;
//线性表的最大容量，可以实时调整，当然，也可以增加参数，让类的构造函数去堆中开辟空间，这样就可以让用户决定大小了。

//我准备构造一个类模板，使线性表能够存放各种数据类型

template<class Elementtype>
class SeqList {

public:
e>
SeqList<Elementtype>::SeqList(Elementtype a[], int n)//有参构造，用一个数组初始化线性表
{
	if (n > maxlength)
	{
		cout << "装不下" << endl;

	}
	else {
		for (int i = 0; i < n; i++)
			elements[i] = a[i];
		len = n;
	}
}



template <class Elementtype>
void SeqList<Elementtype>::Delete1(int i) //按位删除操作
{
	if (len == 0) {
		cout << "EMPTY!" << endl;
	}
	else if (i<1 || i>len) {
		cout << "WRONG!" << endl;
	}
	else {
		for (int j = i; j < len; j++)
			elements[j - 1] = elements[j];
		len--;
	}
}

template <class Elementtype>
void SeqList<Elementtype>::Delete2(Elementtype x) //按值删除操作,重复元素只删除第一个
{
	int p = 0;
	for (int i = 0; i < len; i++)
		if (elements[i] == x) {
			p = i + 1;
			break;
		}
	if (p == 0)
		cout << "未找到该值" << endl;
	else {
		for (int j = p; j < len; j++)
			elements[j - 1] = elements[j];
		len--;
	}
}

template <class Elementtype>
void SeqList<Elementtype>::Sort() {//我用的简单冒泡排序
	int i, j;
	for (i = 0; i < len-1; i++)
	{
		bool flag = false;
		for (j = len-1; j >= i + 1; j--)
			if (elements[j] < elements[j - 1])
			{
				Elementtype temp = elements[j];
				elements[j] = elements[j - 1];
				elements[j - 1] = temp;
				flag = true;
			}
		if (flag == false)
			return;
	}
}



template <class Elementtype>
void SeqList<Elementtype>::DeleteRe()//对于已排好序的线性表，删除所有重复元素的算法。
{
	this->Sort();//内置了排序功能
	int i, j;
	for (i = 0; i < len - 1; i++) {
		Elementtype temp = elements[i];
		for (j = i + 1; j < len; j++) {
			if (elements[j] != temp)
				break;
			else
				Delete1(j + 1);
		}
	}
}

template <class Elementtype>
void SeqList<Elementtype>::Reverse()//线性表“逆置”算法
{

	int i = 0, j = len - 1;
	for (i = 0; i != j; i++) {

		Elementtype temp = elements[i];
		elements[i] = elements[j];
		elements[j] = temp;
		j--;
	}

}

template <class Elementtype>
void SeqList<Elementtype>::MoveRight(int k)//循环右移
{
	while (k--) {
		Elementtype temp = elements[len - 1];
		for (int i = len - 1; i > 0; i--) {
			elements[i] = elements[i - 1];
		}
		elements[0] = temp;
	}
}


template <class Elementtype>
void SeqList<Elementtype>::MoveLeft(int k)//循环左移
{
	while (k--) {
		Elementtype temp = elements[0];
		for (int i = 0; i < len - 1; i++) {
			elements[i] = elements[i + 1];
		}
		elements[len - 1] = temp;
	}

}


template <class Elementtype>
void  SeqList<Elementtype>::MergeSeqList(SeqList& L) {
	int i = L.len;
	for (int j = 0; j < i; j++)
		this->Insert(1, L.elements[j]);
	this->DeleteRe();
	
}


template <class Elementtype>
void SeqList<Elementtype>::Print(){
	cout << "顺序结构线性表的长度为：" << this->len << endl;
	cout << "表中元素为：" ;
	for (int i = 0; i < len; i++)
	{
		cout << this->elements[i] << " ";
	}
	cout << endl;
}