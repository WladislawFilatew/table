#pragma once
#include <iostream>
using namespace std;

/*!
* ��������: �������� �.
* ������� ���������� ����� � ����� �������
* \param[in] double x - ����� ������� ���������� 
* \param[in] int p - ������� �����
*/
double st(double x, int p);

/*!
* ������� ����������
* \param[in] double n - ����� �� �������� ����� �������� ���������
*/
double fac(int n);

/*!
* ������� ���������
* \param[in] double a - ������� ���������
* \param[in] double b - �����
*/
double Log(double a, double b);

/*!
* ������� ����������
*/
double A(int n,int  k);

/*!
* ������� ���������
*/
double C(int n, int  k);




double st(double x, int p)
{
	double ans = 1;
	while (p > 0) {
		if (p % 2)
			ans *= x;
		p /= 2;
		x *= x;
	}
	return ans;
}

double fac(int n)
{
	double ans = 1;
	for (int i = 2; i <= n; i++) {
		ans *= i;
	}
	return ans;
}

double Log(double a, double b)
{
	return log(a) / log(b);
}

double A(int n, int k)
{
	return fac(n) / fac(n - k);
}

double C(int n, int k)
{
	return fac(n) / ((long long)fac(n - k) * fac(k));
}
