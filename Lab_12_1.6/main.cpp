// main.cpp
#include "Rational.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Rational r1;
	r1.Read();

	Rational r2;
	r2.Read();

	cout << r1.toString() << " + " << r2.toString() << " = " << add(r1, r2).toString() << endl;
	cout << r1.toString() << " - " << r2.toString() << " = " << sub(r1, r2).toString() << endl;
	cout << r1.toString() << " * " << r2.toString() << " = " << mult(r1, r2).toString() << endl;
	cout << r1.toString() << " / " << r2.toString() << " = " << div(r1, r2).toString() << endl;


	return 0l;
}