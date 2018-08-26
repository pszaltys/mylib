#include "helperstest.h"

#include "helpers.h"

#include <array>

template<typename T, size_t N>
bool ArrTest()
{
	T a[N];
	return ArraySize(a) == N;
}

void HelpersTest::TestArraySize()
{
	test_((ArrTest<int, 10>()));
	test_((ArrTest<int, 1>()));
	test_((ArrTest<double, 10>()));
	test_((ArrTest<double, 1>()));

	test_((ArrTest<int*, 10>()));
	test_((ArrTest<int*, 1>()));

//	test_((ArrTest<const int, 10>()));
//	test_((ArrTest<const int, 1>()));

//	test_((ArrTest<const int*, 10>()));
//	test_((ArrTest<const int*, 1>()));

//	test_((ArrTest<const int* const, 10>()));
//	test_((ArrTest<const int* const, 1>()));
}

void HelpersTest::Run()
{
	TestArraySize();
}
