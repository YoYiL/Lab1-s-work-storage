#pragma once
#include<iostream>
using namespace std;
const int maxlength=500;
//���Ա���������������ʵʱ��������Ȼ��Ҳ�������Ӳ���������Ĺ��캯��ȥ���п��ٿռ䣬�����Ϳ������û�������С�ˡ�

//��׼������һ����ģ�壬ʹ���Ա��ܹ���Ÿ�����������

template<class Elementtype>
class SeqList {

public:
e>
SeqList<Elementtype>::SeqList(Elementtype a[], int n)//�вι��죬��һ�������ʼ�����Ա�
{
	if (n > maxlength)
	{
		cout << "װ����" << endl;

	}
	else {
		for (int i = 0; i < n; i++)
			elements[i] = a[i];
		len = n;
	}
}



template <class Elementtype>
void SeqList<Elementtype>::Delete1(int i) //��λɾ������
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
void SeqList<Elementtype>::Delete2(Elementtype x) //��ֵɾ������,�ظ�Ԫ��ֻɾ����һ��
{
	int p = 0;
	for (int i = 0; i < len; i++)
		if (elements[i] == x) {
			p = i + 1;
			break;
		}
	if (p == 0)
		cout << "δ�ҵ���ֵ" << endl;
	else {
		for (int j = p; j < len; j++)
			elements[j - 1] = elements[j];
		len--;
	}
}

template <class Elementtype>
void SeqList<Elementtype>::Sort() {//���õļ�ð������
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
void SeqList<Elementtype>::DeleteRe()//�������ź�������Ա�ɾ�������ظ�Ԫ�ص��㷨��
{
	this->Sort();//������������
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
void SeqList<Elementtype>::Reverse()//���Ա����á��㷨
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
void SeqList<Elementtype>::MoveRight(int k)//ѭ������
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
void SeqList<Elementtype>::MoveLeft(int k)//ѭ������
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
	cout << "˳��ṹ���Ա�ĳ���Ϊ��" << this->len << endl;
	cout << "����Ԫ��Ϊ��" ;
	for (int i = 0; i < len; i++)
	{
		cout << this->elements[i] << " ";
	}
	cout << endl;
}