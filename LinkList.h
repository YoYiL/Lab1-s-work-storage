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
    LinkList();//�޲ι��캯�������ɾ���ͷ�ڵ�Ŀ�����
    LinkList(Elementtype a[], int n);
    ~LinkList();//��Ϊ�Լ��ڶ��п����˿ռ䣬���Ե������������ص��㷨��
    void Reverse();//���Ա����á��㷨
    void MoveRight(int k);//ѭ������
    void MoveLeft(int k);//ѭ������
    void MergeSeqList(LinkList& L);//�ϲ��������ź������Ա���㷨
public:
    Node<Elementtype>* first;
};

template<class Elementtype>
LinkList<Elementtype>::LinkList()//�޲ι��캯�������ɾ���ͷ�ڵ�Ŀ�����
{
    first = new Node<Elementtype>;
    first->next = NULL;
}


template<class Elementtype>
LinkList<Elementtype>::~LinkList()//�����������ֶ�ɾ�����ٿռ�
{
    while (first != NULL)
    {
        Node<Elementtype>* q = first;
        first = first->next;
        delete q;
    }
}

template<class Elementtype>
int LinkList<Elementtype>::Locate(Elementtype x) //����֮��İ�ֵɾ������
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
void LinkList<Elementtype>::Insert(int i, Elementtype x)//�������
{
    Node<Elementtype>* p = first;
    int count = 0;
    while (p != NULL && count < i - 1)
    {
        p = p->next;
        count++;
    }//��ʱ�Ѿ�����ǰ���ڵ�
    if (p == NULL) throw "λ��Ϊ��!";//ǰ��Ϊ��
    else {
        Node<Elementtype>* s = new Node<Elementtype>;
        s->data = x;
        s->next = p->next;
        p->next = s;
    }
}

template<class Elementtype>
Elementtype LinkList<Elementtype>::Delete1(int i)//��λɾ��
{
    Node<Elementtype>* p = first;
    int count = 0;
    while (p != NULL && count < i - 1)
    {
        p = p->next;
        count++;
    }
    if (p == NULL || p->next == NULL) throw "λ��Ϊ��!";//ǰ��Ϊ�ջ���ǰ;���ն˽ڵ�
    else {
        Node<Elementtype>* q = p->next;
        int x = q->data;
        p->next = q->next;
        return x;//���ر�ɾ����ֵ
    }
}

template<class Elementtype>//ֻɾ�������ĵ�һ��ֵ
int LinkList<Elementtype>::Delete2(Elementtype x)//��ֵɾ��
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
void LinkList<Elementtype>::Sort()//�����õ�ѡ������
{
   
    for (Node<Elementtype>* p = first->next; p != NULL; p = p->next) {
        Node<Elementtype>* min = p;
        for (Node<Elementtype>* q = p->next; q != NULL; q = q->next) {
            if (q->data < min->data)
                min = q;
        }
        if (min != p) {//������ʵû�������ı�����ṹ��ֻ�ǽ����˽ṹ���ֵ
            Elementtype temp = min->data;
            min->data = p->data;
            p->data = temp;
        }
    }
}

template<class Elementtype>
void LinkList<Elementtype>::DeleteRe()//�������ź�������Ա�ɾ�������ظ�Ԫ�ص��㷨��
{
    this->Sort();//������
    int count = 1;//������
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
void LinkList<Elementtype>::Reverse()//���Ա����á��㷨
{
    Node<Elementtype>* end;
    for (end = first->next; end->next != NULL; end = end->next);//�ҵ�ĩβ
    Node<Elementtype>* q = end;
    for (Node<Elementtype>* p = first->next; p != q; p = p->next) {
        Node<Elementtype>* T = q;
        Elementtype temp = p->data;
        p->data = q->data;
        q->data = temp;
        for ( q=first->next ; q->next != T; q = q->next);//��ĩβ��ǰ��          
    }
}

template<class Elementtype>
void LinkList<Elementtype>::MoveRight(int k)//ѭ������
{
    while (k--)
    {
        Node<Elementtype>* end;
        for (end = first->next; end->next != NULL; end = end->next);//�ҵ�ĩβ
        Elementtype a = end->data;//������ʱ����ĩβ������
        Node<Elementtype>* q = end;
        while(q!=first->next) {
            Node<Elementtype>* T = q;//�ʼָ��ĩβ
            for (q = first->next; q->next != T; q = q->next);//��q���T��ǰ��
            T->data = q->data;
        }
        first->next->data = a;
    }

}


template<class Elementtype>
void LinkList<Elementtype>::MoveLeft(int k)//ѭ������
{
    while (k--) {
        Elementtype a = first->next->data;//������ʱ�����һ������
        Node<Elementtype>* p;
        for ( p = first->next; p->next != NULL; p = p->next) {//ѭ������Ϊĩβ
            p->data = p->next->data;          
        }
        p->data = a;
    }
}

template<class Elementtype>
void LinkList<Elementtype>::MergeSeqList(LinkList& L)//�ϲ��������ź������Ա���㷨
{
    Node<Elementtype>* q ;
    for (q = L.first->next; q != NULL; q = q->next) {
        this->Insert(1, q->data);
    }
    this->Sort();
}