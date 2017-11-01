#include "smatrixtest.h"
#include "smatrix.h"
#include <utility>
#include <algorithm>


template<typename T, int N>
void SMatrixTest::Init2dTest()
{
	SMatrix<T> m;

	vector<int> i;
	vector<int> j;
	vector<T> val;
	for (int k = 0; k < N; k++)
	{
		i.push_back(int(rand()));
		j.push_back(int(rand()));
		val.push_back(T(rand()));
	}
	m.Init2d(i, j, val);

	for (int k = 0; k < i.size(); k++)
	{
		test_(m.cVal(i[k], j[k]) == val[k]);
	}

	for (int k = 0; k < N; k++)
	{
		val[k] = T(rand());
	}

	for (int k = 0; k < i.size(); k++)
	{
		m.rVal(i[k], j[k]) = val[k];
	}

	for (int k = 0; k < i.size(); k++)
	{
		test_(m.cVal(i[k], j[k]) == val[k]);
	}
}

void SMatrixTest::Run()
{
	Init2dTest<int, 3>();
	Init2dTest<double, 4>();
}

