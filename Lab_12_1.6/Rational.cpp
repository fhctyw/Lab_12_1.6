// Rational.cpp
#include "Rational.h"
#include <iostream>
#include <sstream>
using namespace std;

void Rational::Pair::Display() const
{
	cout << toString() << endl;
}

string Rational::Pair::toString() const
{
	stringstream ss;
	ss << "Перше число: " << a << ", Друге число: " << b;
	return ss.str();
}

void Rational::Pair::Init(int a, int b)
{
	setA(a);
	setB(b);
}

void Rational::Pair::setA(double a)
{
	this->a = a;
}

void Rational::Pair::setB(double b)
{
	this->b = b;
}

int Rational::Pair::getA() const
{
	return a;
}

int Rational::Pair::getB() const
{
	return b;
}

Rational::Pair sub(const Rational::Pair& p1, const Rational::Pair p2)
{
	Rational::Pair p;
	p.setA(p1.a - p2.a);
	p.setB(p1.b - p2.b);
	return p;
}

bool equal(const Rational::Pair& p1, const Rational::Pair p2)
{
	return p1.a == p2.a && p1.b == p2.b;
}

Rational::Pair Rational::getPair() const
{
	return pair;
}

void Rational::setPair(Pair pair)
{
	this->pair = pair;
}

void Rational::setPair(int a, int b)
{
	Pair p;
	p.Init(a, b);
	pair = p;
}

void Rational::Init(int a, int b)
{
	setPair(a, b);
}

void Rational::Display() const
{
	cout << toString() << endl;
}

string Rational::toString() const
{
	stringstream ss;
	ss << this->pair.getA() << '/' << this->pair.getB();
	return ss.str();
}

void Rational::Read()
{
	int a, b;
	cout << "Чисельник: "; cin >> a;
	cout << "Знаменник: "; cin >> b;
	Init(a, b);
	cout << endl;
}

double Rational::value()
{
	Reduce();
	return 1. * pair.getA() / pair.getB();
}

void Rational::Reduce()
{
	int a = pair.getA(), b = pair.getB();
	int i;
	do
	{
		for (i = abs(std::min(a, b)); i > 0; i--)
		{
			if (a % i == 0 && b % i == 0) {
				a /= i;
				b /= i;
				break;
			}
		}
	} while (i != 1);
	pair.setA(a);
	pair.setB(b);
}

Rational::Pair mult(const Rational::Pair& p1, const Rational::Pair p2)
{
	Rational::Pair p;
	p.a = p1.a * p2.a;
	p.b = p1.a * p2.b;
	return p;
}

Rational add(const Rational& r1, const Rational& r2)
{
	Rational r;
	r.Init(r1.pair.getA() * r2.pair.getB() + r1.pair.getB() * r2.pair.getA(), r1.pair.getB() * r2.pair.getB());
	r.Reduce();
	return r;
}

Rational div(const Rational& r1, const Rational& r2)
{
	Rational r;
	r.Init(r1.pair.getA() * r2.pair.getB(), r1.pair.getB() * r2.pair.getA());
	r.Reduce();
	return r;
}

Rational sub(const Rational& r1, const Rational& r2)
{
	Rational r;
	r.Init(r1.pair.getA() * r2.pair.getB() - r1.pair.getB() * r2.pair.getA(), r1.pair.getB() * r2.pair.getB());
	r.Reduce();
	return r;
}

Rational mult(const Rational& r1, const Rational& r2)
{
	Rational r;
	r.Init(r1.pair.getA() * r2.pair.getA(), r1.pair.getB() * r2.pair.getB());
	r.Reduce();
	return r;
}