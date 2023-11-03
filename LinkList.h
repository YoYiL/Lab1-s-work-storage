#pragma once
#include<iostream>
using namespace std;


template<class Elementtype>
struct Node
{
    Elementtype data;
    Node<Elementtype>* next;
};

template<class Elementtype>
class LinkList
{
public:
    LinkList();//无参构造函数，生成具有头节点的空链表
    LinkList(Elementtype a[], int n);
    ~LinkList();//因为自己在堆中开辟了空间，所以得重新设置析素的算法。
    void Reverse();//线性表“逆置”算法
    void MoveRight(int k);//循环右移
    void MoveLeft(int k);//循环左移
    void MergeSeqList(LinkList& L);//合并两个已排好序线性表的算法
public:
    Node<Elementtype>* first;
};

template<class Elementtype>
LinkList<Elementtype>::LinkList()//无参构造函数，生成具有头节点的空链表
{
    first = new Node<Elementtype>;
    first->next = NULL;
}


template<class Elementtype>
LinkList<Elementtype>::~LinkList()//析构函数，手动删除开辟空间
{
    while (first != NULL)
    {
        Node<Elementtype>* q = first;
        first = first->next;
        delete q;
    }
}

template<class Elementtype>
int LinkList<Elementtype>::Locate(Elementtype x) //用于之后的按值删除函数
{
    Node<Elementtype>* p = first->next;
    int count = 1;
    while (p != NULL)
    {
        if (p->data == x) return count;
        p = p->next;
        count++;
    }
    return 0;
}

template<class Elementtype>
void LinkList<Elementtype>::Insert(int i, Elementtype x)//插入操作
{
    Node<Elementtype>* p = first;
    int count = 0;
    while (p != NULL && count < i - 1)
    {
        p = p->next;
        count++;
    }//这时已经到了前驱节点
    if (p == NULL) throw "位置为空!";//前驱为空
    else {
        Node<Elementtype>* s = new Node<Elementtype>;
        s->data = x;
        s->next = p->next;
        p->next = s;
    }
}

template<class Elementtype>
Elementtype LinkList<Elementtype>::Delete1(int i)//按位删除
{
    Node<Elementtype>* p = first;
    int count = 0;
    while (p != NULL && count < i - 1)
    {
        p = p->next;
        count++;
    }
    if (p == NULL || p->next == NULL) throw "位置为空!";//前驱为空或者前途是终端节点
    else {
        Node<Elementtype>* q = p->next;
        int x = q->data;
        p->next = q->next;
        return x;//返回被删除的值
    }
}

template<class Elementtype>//只删除遇到的第一个值
int LinkList<Elementtype>::Delete2(Elementtype x)//按值删除
{
    int Y = Locate(x);
    Delete1(Y);
    return Y;
}

template<class Elementtype>
void LinkList<Elementtype>::Print()
{
    Node<Elementtype>* p = first->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


template<class Elementtype>
void LinkList<Elementtype>::Sort()//这里用的选择排序
{
   
    for (Node<Elementtype>* p = first->next; p != NULL; p = p->next) {
        Node<Elementtype>* min = p;
        for (Node<Elementtype>* q = p->next; q != NULL; q = q->next) {
            if (q->data < min->data)
                min = q;
        }
        if (min != p) {//这里其实没有真正改变链表结构，只是交换了结构体的值
            Elementtype temp = min->data;
            min->data = p->data;
            p->data = temp;
        }
    }
}

template<class Elementtype>
void LinkList<Elementtype>::DeleteRe()//对于已排好序的线性表，删除所有重复元素的算法。
{
    this->Sort();//先排序
    int count = 1;//计数器
    for (Node<Elementtype>* p = first->next; p != NULL; p = p->next) {
        Elementtype temp = p->data;
        for (Node<Elementtype>* q = p->next; q != NULL; q = q->next) {
            int n = count + 1;
            if (q->data == temp)
                this->Delete1(n);
            n++;
        }
        count++;
    }
}


template<class Elementtype>
void LinkList<Elementtype>::Reverse()//线性表“逆置”算法
{
    Node<Elementtype>* end;
    for (end = first->next; end->next != NULL; end = end->next);//找到末尾
    Node<Elementtype>* q = end;
    for (Node<Elementtype>* p = first->next; p != q; p = p->next) {
        Node<Elementtype>* T = q;
        Elementtype temp = p->data;
        p->data = q->data;
        q->data = temp;
        for ( q=first->next ; q->next != T; q = q->next);//找末尾的前驱          
    }
}

template<class Elementtype>
void LinkList<Elementtype>::MoveRight(int k)//循环右移
{
    while (k--)
    {
        Node<Elementtype>* end;
        for (end = first->next; end->next != NULL; end = end->next);//找到末尾
        Elementtype a = end->data;//用于临时保存末尾的数据
        Node<Elementtype>* q = end;
        while(q!=first->next) {
            Node<Elementtype>* T = q;//最开始指向末尾
            for (q = first->next; q->next != T; q = q->next);//把q变成T的前驱
            T->data = q->data;
        }
        first->next->data = a;
    }

}


template<class Elementtype>
void LinkList<Elementtype>::MoveLeft(int k)//循环左移
{
    while (k--) {
        Elementtype a = first->next->data;//用于临时保存第一个数据
        Node<Elementtype>* p;
        for ( p = first->next; p->next != NULL; p = p->next) {//循环出口为末尾
            p->data = p->next->data;          
        }
        p->data = a;
    }
}

template<class Elementtype>
void LinkList<Elementtype>::MergeSeqList(LinkList& L)//合并两个已排好序线性表的算法
{
    Node<Elementtype>* q ;
    for (q = L.first->next; q != NULL; q = q->next) {
        this->Insert(1, q->data);
    }
    this->Sort();
}