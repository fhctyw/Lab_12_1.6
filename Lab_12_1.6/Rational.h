// Rational.h
#pragma once
#include <string>
using namespace std;

class Rational
{
public:
	class Pair {
		int a, b;
	public:
		void setA(double a);
		void setB(double b);

		int getA() const;
		int getB() const;

		void Init(int a, int b);

		string toString() const;
		void Display() const;

		friend Pair sub(const Pair& p1, const Pair p2);
		friend Pair mult(const Pair& p1, const Pair p2);
		friend bool equal(const Pair& p1, const Pair p2);
	};
private:
	Pair pair;
public:
	Pair getPair() const;

	void setPair(Pair pair);
	void setPair(int a, int b);

	void Init(int a, int b);

	void Display() const;
	string toString() const;
	void Read();

	friend Rational add(const Rational& r1, const Rational& r2);
	friend Rational div(const Rational& r1, const Rational& r2);
	friend Rational sub(const Rational& r1, const Rational& r2);
	friend Rational mult(const Rational& r1, const Rational& r2);

	double value();
private:
	void Reduce();
};

