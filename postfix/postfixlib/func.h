#pragma once
#include <iostream>
using namespace std;

/*!
* Выполнил: Филатьев В.
* функция возведения числа в целую степень
* \param[in] double x - чисдо которое возводится 
* \param[in] int p - степень числа
*/
double st(double x, int p);

/*!
* функция факториала
* \param[in] double n - число от которого нужно получить факториал
*/
double fac(int n);

/*!
* функция логарифма
* \param[in] double a - степень логарифма
* \param[in] double b - число
*/
double Log(double a, double b);

/*!
* функция размешения
*/
double A(int n,int  k);

/*!
* функция сочитания
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
