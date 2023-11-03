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
    StaticLinkList();//�޲ι��죬��ʼ����̬����
    void BuildList(int L);//�ھ�̬����ռ��д���һ�����Ա�ʵ���������α�λ�ôӿ��ÿռ�����Ƴ�
    int GetNode();//�൱��NEW����
    void FreeNode(int q);//���ղ���
    void Insert(DataType x, int p);
    void Delete(int p);//����Ϊ����λ�ã�ɾ��ʵ����SList[p].next
    void Reverse(int L);//����Ϊ�α�ͷ
    void print(int L);
    int FindEnd(int L);//����һ���α�ָ�����Ա��ĩβλ��

public:
    SNode<DataType> SList[Maxsize];
    int av;//��ʶ���Ա�
    int len;//��¼���Ա���
};

template<class DataType>
StaticLinkList<DataType>::StaticLinkList() {//�޲ι��죬��ʼ����̬����
    int j = 0;
    for (j = 0; j < Maxsize - 1; j++)
        SList[j].next = j + 1;
    SList[j].next = -1;//���һ��Ϊ��
    av = 0;//���ÿռ��
    len = 0;
}

template<class DataType>
void StaticLinkList<DataType>::BuildList(int L)//�ھ�̬����ռ��д���һ�����Ա�ʵ���������α�λ�ôӿ��ÿռ�����Ƴ�
{
    int j = 0;
    for (j = 0; SList[j].next != L; j= SList[j].next);//�Ѿ����˿��б����α��ǰ��
    int i= SList[L].next;//���б����α�ĺ��
    SList[j].next = i;
    SList[L].next = -1;//��ʼ����ͷ���ڱ�β

}

template<class DataType>
int StaticLinkList<DataType>::GetNode() {//�൱��NEW����
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
void StaticLinkList<DataType>::FreeNode(int q) {//���ղ���
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
    int i = FindEnd(L);//L���ĩβ
    int j ;
    for (j = SList[L].next; j != i; j = SList[j].next) {
        int temp = i;
        DataType n = SList[j].data;//i,jǰ�󽻻�
        SList[j].data = SList[i].data;
        SList[i].data = n;
        for (i = j; SList[i].next != temp; i = SList[i].next);//�ҵ�i��ǰ��
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
int StaticLinkList<DataType>::FindEnd(int L)//����һ���α�ָ�����Ա��ĩβλ��
{
    int j;
    for (j = L; SList[j].next != -1; j = SList[j].next);//����ĩβ
    return j;
}