
#include <cmath>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
struct tree_T01 {

	int* A; //основной массив чисел
	int N; //кол-во эл-в
	int* t;//массив дерева

	/*
	Текстовый блок для пункта 11
			в задании 
	*/
	void write(int n) {
		N = n;
		t = new int[n];
		A = new int[n];
		for (int i = 0; i <= n - 1; i++) {
			cin >> A[i];
		}
		buildMass(A, 0, 0, n - 1);
	}
	//a0, b0 - границы тек отрезука
	void buildMass(int A[], int tecVer, int a0, int b0) {
		int center;
		if (a0 == b0) {
			t[tecVer] = A[a0];
		}
		else {
			center = a0 + (b0 - a0) / 2; //вычисление края узла вниз
			buildMass(A, tecVer * 2 + 1, a0, center); //правая часть
			buildMass(A, tecVer * 2 + 2, center + 1, b0); //левая часть
			t[tecVer] = t[tecVer * 2 + 1] + t[tecVer * 2 + 2];
		}
	}
	//a, b -граница запроса
	int findSum(int tecVer, int a0, int b0, int a, int b) {
		int sum, sum1, sum2, center;
		if (b < a0 || b0 < a)
			return 0;
		if (a <= a0 && b0 <= b)
			return t[tecVer];
		center = a0 + (b0 - a0) / 2;
		sum1 = findSum(tecVer * 2 + 1, a0, center, a, b);
		sum2 = findSum(tecVer * 2 + 2, center + 1, b0, a, b);
		sum = sum1 + sum2;
		return sum;
	}
};


int main() {
	int n, * K1, * K2, a, b, l, k, sum;
	tree_T01 R;
	cout << "Количество запросов: ";
	cin >> n;
	R.write(n); //заполнение массива
	cin >> k;	//кол-во запросов
	K1 = new int[k];
	K2 = new int[k];
	for (int i = 0; i < k; i++) {
		cin >> a;
		cin >> b;
		if (a > b) {
			l = b;
			b = a;
			a = l;
		}
		K1[i] = a;
		K2[i] = b;
	}
	cout << "--------------------------------------";
	cout << "\n";
	for (int i = 0; i < k; i++) {
		sum = R.findSum(0, 0, n - 1, K1[i], K2[i]);
		cout << sum;
		cout << "\n";
	}
	return (0);
}