#include<iostream>
#include "fstream"
#include "stdlib.h"
#include <stdio.h>
#include <math.h>

using namespace std;

class Vector
{
	int n;
	float* num; // ����� �������
public:
	Vector(int a, float* m) {
		n = a;
		num = new float[n];
		for (int i = 0; i < n; i++)
			num[i] = m[i];
	}

	Vector() {
		n = 0;
	}
	
	//--------������-� �����-�-------------
	Vector(const Vector& V) {
		n = V.n;
		num = new float[n];
		for (int i = 0; i < n; i++)
			num[i] = V.num[i];
	}

	int get_dim() {
		return n;
	}

	float* get_vec() {
		return num;
	}

	Vector& operator=(Vector V1) {// �������� ������������
		n = V1.get_dim();
		num = new float[n];
		for (int i = 0; i < n; i++)
			num[i] = (V1.get_vec())[i];
		return *this;
	}

	void set_vec(float* V, int r) {
		num = V;
		n = r;
	}

	~Vector() {// ����������
		delete[] num;
	}

	Vector operator+ (Vector& V) {
		Vector V1;
		if (n > V.get_dim()) {
			float* m = new float[n];
			for (int i = 0; i < V.get_dim(); i++)
				m[i] = num[i] + (V.get_vec())[i];
			for (int i = V.get_dim(); i < n; i++)
				m[i] = num[i];
			V1.set_vec(m, n);
		}

		else {
			float* m = new float[V.get_dim()];
			for (int i = 0; i < n; i++)
				m[i] = num[i] + (V.get_vec())[i];
			for (int i = n; i < V.get_dim(); i++)
				m[i] = (V.get_vec())[i];
			V1.set_vec(m, V.get_dim());
		}
		return V1;
	}

	Vector operator* (float k) {
		Vector V1;
		float* m = new float[n];
		for (int i = 0; i < n; i++)
			m[i] = num[i] * k;
		V1.set_vec(m, n);
		return V1;
	}
	//-----------������� ��������------------
	bool operator< (Vector& V2) {
		if (mod() < V2.mod())
			return true;
		else return false;
	}

	bool operator> (Vector& V2) {
		if (mod() > V2.mod())
			return true;
		else return false;
	}

	bool operator== (Vector& V2) {
		if (mod() == V2.mod())
			return true;
		else return false;
	}

	bool operator!= (Vector& V2) {
		if (mod() != V2.mod())
			return true;
		else return false;
	}
	//----------�����-----------
	void print() {
		for (int i = 0; i < n; i++)
			cout << num[i] << " ";
		cout << endl;
	}

	//------------������ �������--------
	float mod() {
		float a = 0;
		for (int i = 0; i < n; i++)
			a += num[i] * num[i];
		return a;
	}
	//----------��������� ������-� ��������----------
	float scalar(Vector& V2) {
		float a = 0;
		if (n > V2.get_dim()) {
			for (int i = 0; i < V2.get_dim(); i++)
				a += num[i] * (V2.get_vec())[i];
		}

		else {
			for (int i = 0; i < n; i++)
				a += num[i] * (V2.get_vec())[i];
		}
		return a;
	}

};

//-------------------
int main() {
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ����������� ������� ������� ";
	cin >> n;
	float* m = new float[n];
	cout << "������� ���������� ������� ������� ";
	for (int i = 0; i < n; i++)
		cin >> m[i];
	Vector V1(n, m);
	cout << "������� ����������� ������� ������� ";
	cin >> n;
	m = new float[n];
	cout << "������� ���������� ������� ������� ";
	for (int i = 0; i < n; i++)
		cin >> m[i];
	Vector V2(n, m);
	cout << "������ ������: ";
	V1.print();
	cout << "������ ������: ";
	V2.print();
	Vector SUM = V1 + V2;
	cout << "����� �������� ����� ";
	SUM.print();
	cout << "������� �����: ";
	int k;
	cin >> k;
	Vector V3 = V1 * k;
	cout << "��������� ��������� ������� ������� �� ��� �����: ";
	V3.print();
	float Sc = V1.scalar(V2);
	cout << "��������� ������������ �������� ��������: " << Sc << endl;
	if (V1 > V2)
		cout << "������ 1 �� ������ ������ ������� 2" << endl;
	if (V1 < V2)
		cout << "������ 1 �� ������ ������ ������� 2" << endl;
	if (V1 == V2)
		cout << "������� ����� �� ������" << endl;
	float alpha = Sc / (sqrt(V1.mod()) * sqrt(V2.mod()));
	cout << "������� ���� ����� ����� ��������� �����: " << alpha << endl;
}