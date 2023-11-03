#pragma once
#include<iostream>
using namespace std;
const int Maxsize = 100;

template<class DataType>
struct SNode {
    DataType data;
    int next;
};

template<class DataType>
class StaticLinkList {
public:
    StaticLinkList();//无参构造，初始化静态链表
    void BuildList(int L);//在静态链表空间中创建一个线性表实例，即把游标位置从可用空间表中移除
    int GetNode();//相当于NEW操作
    void FreeNode(int q);//回收操作
    void Insert(DataType x, int p);
    void Delete(int p);//参数为数组位置，删的实际是SList[p].next
    void Reverse(int L);//参数为游标头
    void print(int L);
    int FindEnd(int L);//查找一个游标指向线性表的末尾位置

public:
    SNode<DataType> SList[Maxsize];
    int av;//标识线性表
    int len;//记录线性表长度
};

template<class DataType>
StaticLinkList<DataType>::StaticLinkList() {//无参构造，初始化静态链表
    int j = 0;
    for (j = 0; j < Maxsize - 1; j++)
        SList[j].next = j + 1;
    SList[j].next = -1;//最后一个为空
    av = 0;//可用空间表
    len = 0;
}

template<class DataType>
void StaticLinkList<DataType>::BuildList(int L)//在静态链表空间中创建一个线性表实例，即把游标位置从可用空间表中移除
{
    int j = 0;
    for (j = 0; SList[j].next != L; j= SList[j].next);//已经到了空闲表中游标的前驱
    int i= SList[L].next;//空闲表中游标的后继
    SList[j].next = i;
    SList[L].next = -1;//初始化表头等于表尾

}

template<class DataType>
int StaticLinkList<DataType>::GetNode() {//相当于NEW操作
    int p;
    if (SList[av].next == -1)
        p = -1;
    else {
        p = SList[av].next;
        SList[av].next = SList[p].next;
    }
    return p;
}

template<class DataType>
void StaticLinkList<DataType>::FreeNode(int q) {//回收操作
    SList[q].next = SList[av].next;
    SList[av].next = q;
}

template<class DataType>
void StaticLinkList<DataType>::Insert(DataType x, int p)
{
    int q;
    q = GetNode();
    SList[q].data = x;
    SList[q].next = SList[p].next;
    SList[p].next = q;
    len++;
}

template<class DataType>
void StaticLinkList<DataType>::Delete(int p) {
    int q;
    if (SList[p].next != -1) {
        q = SList[p].next;
        SList[p].next = SList[q].next;
        FreeNode(q);
        len--;
    }
}

template<class DataType>
void StaticLinkList<DataType>::Reverse(int L) {
    int i = FindEnd(L);//L表的末尾
    int j ;
    for (j = SList[L].next; j != i; j = SList[j].next) {
        int temp = i;
        DataType n = SList[j].data;//i,j前后交换
        SList[j].data = SList[i].data;
        SList[i].data = n;
        for (i = j; SList[i].next != temp; i = SList[i].next);//找到i的前驱
    }
}

template<class DataType>
void StaticLinkList<DataType>::print(int L) {
    int p = SList[L].next;
    int n = len;
    for (n; n != 0;n--) {
        cout << SList[p].data<<" ";
        p = SList[p].next;
    }
    cout << endl;
}

template<class DataType>
int StaticLinkList<DataType>::FindEnd(int L)//查找一个游标指向线性表的末尾位置
{
    int j;
    for (j = L; SList[j].next != -1; j = SList[j].next);//到达末尾
    return j;
}