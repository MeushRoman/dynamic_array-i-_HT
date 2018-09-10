// ConsoleApplication30.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

/*1.	**Даны два массива : А[M] и B[N](M и  N вводятся с клавиатуры).Необходимо создать третий массив минимально возможного размера, в котором нужно собрать элементы массива A, которые не включаются в массив B
Рекомендации :
Сначала посчитайте количество разных(не общих) элементов массивов, потом уже создайте третий массив и занесите туда эти числа.

2.	**Даны два массива : А[M] и B[N](M и  N вводятся с клавиатуры).Необходимо создать третий массив минимально возможного размера, в котором нужно собрать общие элементы массивов A и B
Рекомендации :
Сначала посчитайте количество разных(не общих) элементов массивов, потом уже   создайте третий массив и занесите туда эти числа.*/


void printA(int *a, int m, int *b, int n) {

	for (int i = 0; i < m; i++)
	{
		a[i] = rand() % 9 + 1;
		cout << a[i] << " ";
	}

	cout << endl;

	for (int j = 0; j < n; j++)
	{
		b[j] = rand() % 9 + 1;
		cout << b[j] << " ";
	}
	cout << endl;
}


void arr(int *a, int m, int *b, int n) {
	int z = 0;
	int c = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] == b[j]) {
				c++;
				z++;
				break;
			}
		}
	}
	//2.
	int *a1;
	a1 = new int[z];
	int l = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] == b[j]) {
				a1[l] = a[i];
				l++;
				break;
			}
		}
	}

	


	//1.
	int *ar;
	c = m - c;

	ar = new int[c];

	int x = 0, k = 0;

	for (int i = 0; i < m; i++)
	{
		

		for (int j = 0; j < n; j++)
		{
			x = 0;
			if (a[i] != b[j]) {
				x = -1;
			}
			else {
				x = 0;
				break;
			}
		}

		if (x == -1) {
			ar[k] = a[i];
			k++;
		}
	}

	cout << endl;
	cout << "1." << endl;
	for (int i = 0; i < c; i++)
	{
		cout << ar[i] << " ";
	}
	cout << endl << endl;

	cout << "2." << endl;
	for (int i = 0; i < z; i++)
	{
		cout << a1[i] << " ";
	}
	cout << endl;

	delete[] a1;
	delete[] ar;
}

int main()
{
	srand(time(NULL));


	int *a;
	int *b;
	int m = 5, n = 4;
	cin >> m >> n;
	a = new int[m];
	b = new int[n];

	printA(a, m, b, n);
	arr(a, m, b, n);

	delete[] a;
	delete[] b;

	return 0;
}

