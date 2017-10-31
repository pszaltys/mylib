#include "functortest.h"
#include "Functor.h"
#include <vector>

double fun1(double a, int b)
{
	return a + b;
}

double fun3(double& a, int* b)
{
	a = 1.1;
	*b = 2;
	return a + *b;
}

int fun7(int& a, int& c, int*& b)
{
	b = &a;
	return *b + c;
}

double fun4(const double* a, const int& b)
{
	return *a + b;
}

std::vector<float> fun2(double a, int b, std::vector<float>& c)
{
	c.push_back((float)a);
	c.push_back((float)b);
	return c;
}

int emptyfun()
{
	return 1;
}

int GLOB = 0;

void emptyfun2()
{
	GLOB = 11;
}
///////////////////////////////////////////////////

struct Fun
{
	int operator()(int p)
	{
		return p;
	}
};


struct A
{
	double ma;
	A() : ma(1.1)	{}

	double fun5(double a)
	{
		return a;
	}

	double& fun6(double a)
	{
		return ma;
	}
};

void FunctorTest::TestFunctions()
{
	Functor<double, double, int> funct1(fun1);
	test_(funct1(0, 0) == 0);
	test_(funct1(1, 1) == 2);
	test_(funct1(10., 1) == 11);
	test_(funct1(9.65, 2) == 11.65);

	Functor<double, double&, int*> funct3(fun3);
	double a = 0.;
	int b = 0;
	int* pb = &b;
	test_(funct3(a, pb) == 3.1);
	test_(a == 1.1);
	test_(b == 2);

	Functor<int, int&, int&, int*&> funct7(fun7);
	int aa = 9;
	int bb = 8;
	int* pp = &bb;
	int res = funct7(aa, bb, pp);
	test_(res == 17);

	Functor<double, const double*, const int&> funct4(fun4);
	double* pa = &a;
	a = 2.34;
	b = 22;
	test_(funct4(pa, b) == 24.34);


	test_(funct1(9.65, 2) == 11.65);
	Functor<std::vector<float>, double, int, std::vector<float>& > funct2(fun2);
	std::vector<float> v;
	v.push_back(1.);
	test_(funct2(0., 0, v).size() == 3);
	test_(funct2(11.456, 2, v)[4] == 2);
	test_(v.size() == 5);

	Functor<int> funct5(emptyfun);
	test_(funct5() == 1);

	Functor<void> funct6(emptyfun2);
	funct6();
	test_(GLOB == 11);
}

void FunctorTest::TestMemFunction()
{
	A a;
	Functor<double, double> funct1(&a, &A::fun5);
	test_(funct1(23.56) == 23.56);

	Functor<double&, double> funct2(&a, &A::fun6);
	test_(funct2(1.) == 1.1);
}


void FunctorTest::TestObjFunction()
{
	Fun f;
	Functor<int, int> funct1(f);
	test_(funct1(44) == 44);
}

void FunctorTest::Run()
{
	TestFunctions();
	TestMemFunction();
}